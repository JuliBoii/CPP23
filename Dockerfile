# Base image we are building from
FROM alpine:latest
LABEL maintainer="Julian H, ah503917@gmail.com" \
      description="A small image for CPP Development"

# Ensuring we have the latest security patches and software updates
RUN apk update && apk upgrade

# Installing Tools
# --no-cache rmoves the cache. Ensuring, image size remains at its smallest possible
RUN apk add --no-cache autoconf \
                        autoconf-archive \
                        automake \
                        bash \
                        build-base \
                        ccache \
                        clang20-dev \
                        clang20-extra-tools \
                        cmake \
                        curl \
                        eudev-libs \
                        freetype \
                        gdb \
                        gettext \
                        git \
                        libc++-dev \
                        libflac \
                        libgcc \
                        libogg \
                        libstdc++-dev \
                        libtool \
                        libvorbis \
                        libx11 \
                        libxcursor \
                        libxrandr \
                        linux-headers \
                        lldb \
                        llvm \
                        llvm-dev \
                        make \
                        musl \
                        nano \
                        openal-soft-libs \
                        pkgconf \
                        python3 \
                        python3-dev \
                        py3-pip \
                        tar \
                        unzip \
                        wget \
                        zip

ENV VCPKG_ROOT=/opt/vcpkg

ENV PATH=${VCPKG_ROOT}:${PATH}
ENV VCPKG_FORCE_SYSTEM_BINARIES=1

# Cloning Ninja from source
RUN git clone https://github.com/ninja-build/ninja.git /ninja
WORKDIR /ninja
RUN git checkout release

# Building Ninja
# Generates the initial Ninja files to build itself
RUN python3 configure.py --bootstrap

# Creates a build directory for CMake & builds Ninja using CMake
RUN cmake -Bbuild-cmake && cmake --build build-cmake

# Installing Compiled Ninja binary to a standard location
RUN cp ninja /usr/bin/
WORKDIR /

# Cleaning up, to reduce image size
RUN rm -rf ninja/

# Cloning vcpkg from source
RUN git clone https://github.com/microsoft/vcpkg.git /opt/vcpkg
WORKDIR /opt/vcpkg
RUN git pull

# Building vcpkg
RUN ./bootstrap-vcpkg.sh -disableMetrics --useSystemBinaries

WORKDIR /
RUN chmod -R 777 /opt/vcpkg

WORKDIR /workspace
