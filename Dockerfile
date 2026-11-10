# Base image we are building from
FROM debian:trixie-slim AS tool_build

ENV DEBIAN_FRONTEND=noninteractive
ENV PREFIX=/usr/local
ARG GCC_VERSION=16
ARG MAX_JOBS=6
ARG MAX_LINK_JOBS=2

# Ensuring we have the latest security patches and software updates
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    curl \
    git \
    libssl-dev \
    libexpat1-dev \
    libncurses-dev \
    libreadline-dev \
    liblzma-dev \
    libzstd-dev \
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
    texinfo \
    && rm -rf /var/lib/apt/lists/*

# Building packages from source
WORKDIR /build

RUN git clone https://github.com/Kitware/CMake.git /build/cmake \
    && cd ./cmake \
    && git checkout release \
    && ./bootstrap --parallel=${MAX_JOBS} --prefix=$PREFIX --no-qt-gui \
    && make -j ${MAX_JOBS} \
    && make install \
    && cd /build \
    && rm -rf cmake

# Cloning Ninja from source
RUN git clone https://github.com/ninja-build/ninja.git /build/ninja \
    && cd ./ninja \
    && git checkout release \
    && cmake -Bbuild-cmake -DBUILD_TESTING=OFF -DCMAKE_INSTALL_PREFIX=$PREFIX \
    && cmake --build build-cmake --parallel ${MAX_JOBS} \
    && cmake --install build-cmake \
    && cd /build \
    && rm -rf ninja

RUN git clone --depth 1 --branch releases/gcc-16 https://gcc.gnu.org/git/gcc.git /build/gcc \
    && cd ./gcc \
    && ./contrib/download_prerequisites \
    && cd /build \
    && mkdir gcc-${GCC_VERSION}-build \
    && cd gcc-${GCC_VERSION}-build \
    && ../gcc/configure --prefix=$PREFIX \
      --enable-languages=c,c++ \
      --disable-multilib \
      --disable-bootstrap \
      --with-system-zlib \
      --program-suffix=-${GCC_VERSION} \
    && make -j ${MAX_JOBS} \
    && make install-strip \
    && cd /build && rm -rf gcc \
    && rm -rf gcc-${GCC_VERSION}-build \
    && ln -sf /usr/local/bin/gcc-${GCC_VERSION} /usr/local/bin/gcc \
    && ln -sf /usr/local/bin/g++-${GCC_VERSION} /usr/local/bin/g++

ENV CC=/usr/local/bin/gcc
ENV CXX=/usr/local/bin/g++
ENV LD_LIBRARY_PATH=/usr/local/lib64:/usr/local/lib

RUN git clone --depth 1 https://sourceware.org/git/binutils-gdb.git /build/gdb \
    && cd /build/gdb \
    && mkdir -p build && cd build \
    && ../configure \
        --prefix=${PREFIX} \
        --with-python=/usr/bin/python3 \
        --with-system-zlib \
        --with-system-readline \
        --with-expat \
        --with-lzma \
        --disable-binutils \
        --disable-ld \
        --disable-gold \
        --disable-gas \
        --disable-sim \
        --disable-gprof \
    && make -j${MAX_JOBS} \
    && make install-strip \
    && cd /build && rm -rf gdb

RUN git clone --depth 1 https://github.com/llvm/llvm-project.git /build/llvm-project \
    && cd /build/llvm-project \
    && cmake -S llvm -B build -G Ninja \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_INSTALL_PREFIX=$PREFIX \
        -DLLVM_ENABLE_PROJECTS="clang;lld" \
        -DLLVM_INCLUDE_TESTS=OFF \
        -DLLVM_INCLUDE_EXAMPLES=OFF \
        -DLLVM_INCLUDE_DOCS=OFF \
        -DLLVM_TARGETS_TO_BUILD="X86" \
        -DLLVM_PARALLEL_COMPILE_JOBS=${MAX_JOBS} \
        -DLLVM_PARALLEL_LINK_JOBS=${MAX_LINK_JOBS} \
        -DLLVM_BUILD_LLVM_DYLIB=ON \
        -DLLVM_LINK_LLVM_DYLIB=ON \
    && ninja -C build install/strip \
    && cd /build && rm -rf llvm-project
#    && cmake --build build --target install/strip --parallel $(nproc) \

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
    libc6-dev \
    libstdc++6 \
    libmpfr6 \
    libssl3 \
    python3 \
    libncursesw6 \
    libgmp10 \
    libmpfr6 \
    libmpc3 \
    libexpat1 \
    libreadline8t64 \
    libpython3.13 \
    liblzma5 \
    libzstd1 \
    tar \
    zlib1g \
    && rm -rf /var/lib/apt/lists/*

COPY --from=tool_build /usr/local/ /usr/local/

RUN find /usr/local/lib -name "*.a" -delete \
    && find /usr/local/lib -name "*.la" -delete \
    && rm -rf /usr/local/include/llvm* /usr/local/include/clang* \
    && ldconfig

ENV CC=/usr/local/bin/gcc
ENV CXX=/usr/local/bin/g++

# Cloning vcpkg from source
RUN git clone https://github.com/microsoft/vcpkg.git /opt/vcpkg \
    && cd /opt/vcpkg \
    && git pull \
    && ./bootstrap-vcpkg.sh -disableMetrics \
    && cd / && chmod -R 777 /opt/vcpkg
