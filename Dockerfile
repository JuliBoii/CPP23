# Base image we are building from
FROM alpine:latest
LABEL maintainer="Julian H, ah503917@gmail.com" \
      description="An image for CPP Development"

ARG MAX_JOBS=6
ENV PREFIX=/usr/local
ENV VCPKG_ROOT=/opt/vcpkg
ENV PATH=${VCPKG_ROOT}:${PATH}
ENV VCPKG_FORCE_SYSTEM_BINARIES=1

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
                        clang \
                        clang-dev \
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
                        openal-soft-libs \
                        pkgconf \
                        python3 \
                        python3-dev \
                        py3-pip \
                        tar \
                        unzip \
                        wget \
                        zip

# Cloning Ninja from source
RUN git clone https://github.com/ninja-build/ninja.git /build/ninja \
    && cd /build/ninja \
    && git checkout release \
    && cmake -Bbuild-cmake -DBUILD_TESTING=OFF -DCMAKE_INSTALL_PREFIX=${PREFIX} \
    && cmake --build build-cmake --parallel ${MAX_JOBS} \
    && cmake --install build-cmake \
    && cd / \
    && rm -rf build

RUN git clone https://github.com/microsoft/vcpkg.git /opt/vcpkg \
    && cd /opt/vcpkg \
    && git pull \
    && ./bootstrap-vcpkg.sh -disableMetrics \
    && cd / && chmod -R 777 /opt/vcpkg
