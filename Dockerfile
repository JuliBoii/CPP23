# Base image we are building from
FROM debian:trixie-slim AS tool_build

ENV DEBIAN_FRONTEND=noninteractive
ENV PREFIX=/usr/local

# Ensuring we have the latest security patches and software updates
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    curl \
    git \
    libssl-dev \
    libncurses5-dev \
    ca-certificates \
    wget \
    && rm -rf /var/lib/apt/lists/*

# Building packages from source
WORKDIR /tmp/sources

RUN git clone https://github.com/Kitware/CMake.git /tmp/sources/cmake
WORKDIR /tmp/sources/cmake
RUN git checkout release

# Building CMAKE
RUN ./bootstrap --parallel=$(nproc) --prefix=$PREFIX && make -j $(nproc) && make install
RUN cd .. && rm -rf cmake

# Cloning Ninja from source
RUN git clone https://github.com/ninja-build/ninja.git /tmp/sources/ninja
WORKDIR /tmp/sources/ninja
RUN git checkout release

# Building Ninja
# Creates a build directory for CMake & builds Ninja using CMake
RUN cmake -Bbuild-cmake -DBUILD_TESTING=OFF -DCMAKE_INSTALL_PREFIX=$PREFIX && cmake --build build-cmake --parallel \
    $(nproc) && cmake --install build-cmake

RUN cd .. && rm -rf ninja

FROM debian:trixie-slim AS gcc_build

ENV DEBIAN_FRONTEND=noninteractive
ENV PREFIX=/usr/local

COPY --from=tool_build /usr/local /usr/local

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    curl \
    git \
    ca-certificates \
    bzip2 \
    libgmp-dev \
    libmpfr-dev \
    libmpc-dev \
    flex \
    bison \
    gawk \
    && rm -rf /var/lib/apt/lists/*

ARG GCC_VERSION=16
WORKDIR /tmp/sources

RUN git clone --depth 1 --branch releases/gcc-16 https://gcc.gnu.org/git/gcc.git /tmp/sources/gcc
WORKDIR /tmp/sources/gcc

RUN ./contrib/download_prerequisites

WORKDIR /tmp/sources

RUN mkdir gcc-16-build && cd gcc-16-build && ../gcc/configure --prefix=$PREFIX --enable-languages=c,c++ --disable-multilib --program-suffix=-${GCC_VERSION} \
    && make -j $(nproc) && make install-strip

RUN cd .. && rm -rf gcc && rm -rf gcc-16-build

FROM debian:trixie-slim AS llvm_build

ENV DEBIAN_FRONTEND=noninteractive
ENV PREFIX=/usr/local

COPY --from=gcc_build /usr/local /usr/local

ARG GCC_VERSION=16

RUN ln -sf /usr/local/bin/gcc-${GCC_VERSION} /usr/local/bin/gcc \
    && ln -sf /usr/local/bin/g++-${GCC_VERSION} /usr/local/bin/g++

RUN apt-get update && apt-get install -y --no-install-recommends \
    git \
    ca-certificates \
    python3 \
    python3-yaml \
    python3-dev \
    zlib1g \
    libtinfo6 \
    libxml2 \
    swig \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /tmp/sources
RUN git clone --depth 1 https://github.com/llvm/llvm-project.git /tmp/sources/llvm-project

WORKDIR /tmp/sources/llvm-project
RUN cmake -S llvm -B build -G Ninja \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_INSTALL_PREFIX=$PREFIX \
        -DLLVM_ENABLE_PROJECTS="clang;lld;lldb" \
        -DLLVM_INCLUDE_TESTS=OFF \
        -DCOMPILER_RT_BUILD_SANITIZERS=ON \
    && ninja -C build install

FROM debian:trixie-slim

# Copy the completely compiled compiler toolchain from the builder stage
COPY --from=llvm_build /usr/local /usr/local

ARG GCC_VERSION=16
RUN ln -sf /usr/local/bin/gcc-${GCC_VERSION} /usr/local/bin/gcc \
    && ln -sf /usr/local/bin/g++-${GCC_VERSION} /usr/local/bin/g++ \

# Re-install minimal runtime library requirements
RUN apt-get update && apt-get install -y --no-install-recommends \
    ca-certificates \
    python3 \
    git \
    && rm -rf /var/lib/apt/lists/*

# Fix dynamic linker run-time bindings for the new libraries
RUN ldconfig

## Cloning vcpkg from source
#RUN git clone https://github.com/microsoft/vcpkg.git /opt/vcpkg
#WORKDIR /opt/vcpkg
#RUN git pull
#
## Building vcpkg
#RUN ./bootstrap-vcpkg.sh -disableMetrics --useSystemBinaries
#
#ENV VCPKG_ROOT=/opt/vcpkg
#
#ENV PATH=${VCPKG_ROOT}:${PATH}
#ENV VCPKG_FORCE_SYSTEM_BINARIES=1
#
#WORKDIR /
#RUN chmod -R 777 /opt/vcpkg
#
#FROM vcpkg_build AS final_build
#
#WORKDIR /workspace
