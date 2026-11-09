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
    zlib1g-dev \
    python3 \
    python3-yaml \
    python3-dev \
    bzip2 \
    libgmp-dev \
    libmpfr-dev \
    libmpc-dev \
    flex \
    bison \
    gawk \
    libtinfo6 \
    libxml2 \
    swig \
    && rm -rf /var/lib/apt/lists/*

# Building packages from source
WORKDIR /build

RUN git clone https://github.com/Kitware/CMake.git /build/cmake
WORKDIR /build/cmake
RUN git checkout release \
    && ./bootstrap --parallel=$(nproc) --prefix=$PREFIX \
    && make -j $(nproc) \
    && make install \
    && cd .. \
    && rm -rf cmake

# Cloning Ninja from source
RUN git clone https://github.com/ninja-build/ninja.git /build/ninja
WORKDIR /build/ninja
RUN git checkout release \
    && cmake -Bbuild-cmake -DBUILD_TESTING=OFF -DCMAKE_INSTALL_PREFIX=$PREFIX \
    && cmake --build build-cmake --parallel $(nproc) \
    && cmake --install build-cmake \
    && cd .. \
    && rm -rf ninja

ARG GCC_VERSION=16

RUN git clone --depth 1 --branch releases/gcc-16 https://gcc.gnu.org/git/gcc.git /build/gcc
WORKDIR /build/gcc

RUN ./contrib/download_prerequisites

WORKDIR /build

RUN mkdir gcc-${GCC_VERSION}-build \
    && cd gcc-${GCC_VERSION}-build \
    && ../gcc/configure --prefix=$PREFIX --enable-languages=c,c++ --disable-multilib --program-suffix=-${GCC_VERSION} \
    && make -j $(nproc) \
    && make install-strip \
    && cd .. && rm -rf gcc \
    && rm -rf gcc-${GCC_VERSION}-build \
    && ln -sf /usr/local/bin/gcc-${GCC_VERSION} /usr/local/bin/gcc \
    && ln -sf /usr/local/bin/g++-${GCC_VERSION} /usr/local/bin/g++

RUN git clone --depth 1 https://github.com/llvm/llvm-project.git /build/llvm-project
WORKDIR /build/llvm-project
RUN cmake -S llvm -B build -G Ninja \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_INSTALL_PREFIX=$PREFIX \
        -DLLVM_ENABLE_PROJECTS="clang;lld" \
        -DLLVM_INCLUDE_TESTS=OFF \
        -DLLVM_TARGETS_TO_BUILD="X86" \
        -DLLVM_BUILD_LLVM_DYLIB=ON \
        -DLLVM_LINK_LLVM_DYLIB=ON \
    && cmake --build build --target install/strip --parallel $(nproc) \
    && cd .. && rm -rf llvm-project

FROM debian:trixie-slim

ENV VCPKG_ROOT=/opt/vcpkg
ENV PATH=${VCPKG_ROOT}:${PATH}
ENV VCPKG_FORCE_SYSTEM_BINARIES=1

# Re-install minimal runtime library requirements
RUN apt-get update && apt-get install -y --no-install-recommends \
    ca-certificates \
    curl \
    git \
    zip \
    unzip \
    libstdc++6 \
    libssl3 \
    tar \
    zlib1g \
    && rm -rf /var/lib/apt/lists/*

COPY --from=tool_build /usr/local/ /usr/local/

# Fix dynamic linker run-time bindings for the new libraries
RUN find /usr/local/lib -name "*.a" -delete \
    && find /usr/local/lib -name "*.la" -delete \
    && rm -rf /usr/local/include/llvm* /usr/local/include/clang* \
    && ldconfig

# Cloning vcpkg from source
RUN git clone https://github.com/microsoft/vcpkg.git /opt/vcpkg \
    && cd /opt/vcpkg \
    && git pull \
    && ./bootstrap-vcpkg.sh -disableMetrics --useSystemBinaries \
    && cd / && chmod -R 777 /opt/vcpkg

