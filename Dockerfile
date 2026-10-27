# Base image we are building from
FROM debian:trixie-slim AS tool_builder
LABEL maintainer="Julian H, ah503917@gmail.com" \
      description="An image for CPP Development"

ENV DEBIAN_FRONTEND=noninteractive

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
RUN ./bootstrap --parallel=$(nproc) --prefix=/opt/cmake && make -j $(nproc) && make install

ENV PATH="/opt/cmake/bin:${PATH}"

WORKDIR /

# Cloning Ninja from source
RUN git clone https://github.com/ninja-build/ninja.git /tmp/sources/ninja
WORKDIR /tmp/sources/ninja
RUN git checkout release

# Building Ninja
# Creates a build directory for CMake & builds Ninja using CMake
RUN cmake -Bbuild-cmake -DBUILD_TESTING=OFF -DCMAKE_INSTALL_PREFIX=/opt/ninja && cmake --build build-cmake --parallel \
    $(nproc) && cmake --install build-cmake

ENV PATH="/opt/ninja/bin:${PATH}"

#FROM tool_builder AS gcc_builder
#
#RUN apt-get update && apt-get install -y --no-install-recommends \
#    bzip2 \
#    libgmp-dev \
#    libmpfr-dev \
#    libmpc-dev \
#    flex \
#    bison \
#    && rm -rf /var/lib/apt/lists/*
#
#RUN git clone --depth 1 --branch releases/gcc-16 https://gcc.gnu.org/git/gcc.git /tmp/sources/gcc
#WORKDIR /tmp/sources/gcc
#
#RUN ./contrib/download_prerequisites  \
#
#WORKDIR /tmp/sources
#
#RUN mkdir gcc-16-build && cd gcc-16-build
#RUN $PWD/../gcc/configure --prefix=$HOME/toolchains --enable-languages=c,c++
#RUN make -j $(nproc) && make install
#
#ENV CC=$HOME/toolchains/bin/gcc
#ENV CXX=$HOME/toolchains/bin/g++

#FROM ninja_build AS vcpkg_build
#
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
