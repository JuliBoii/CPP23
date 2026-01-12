FROM ubuntu:rolling
LABEL maintainer="Julian H, ah503917@gmail.com" \
      description="An Ubuntu image for C++ Development"

# Ensuring we have the latest security patches and software updates
RUN apt update && apt upgrade -y

# Installing Tools
RUN apt install build-essential clang curl cmake gdb git lldb libx11-dev libxi-dev libxrandr-dev libxcursor-dev libxi-dev \
     libudev-dev libgl1-mesa-dev pkg-config tar unzip wget x11-apps zip -y

ENV VCPKG=/opt/vcpkg
ENV PATH=${VCPKG_ROOT}:${PATH}
ENV VCPKG_FORCE_SYSTEM_BINARIES=1
ENV DISPLAY=:0


# Cloning Ninja from source
RUN git clone https://github.com/ninja-build/ninja.git /ninja
WORKDIR /ninja
RUN git checkout release

# Building Ninja
RUN python3 configure.py --bootstrap

# Creates a build directory for CMAKE & builds Ninja
RUN cmake -B build-cmake && cmake --build build-cmake

# Installing compiled Ninja binary to /bin directory
RUN cp ninja /usr/bin/
WORKDIR /

# Cleaning up
RUN rm -rf ninja/

# Cloning vcpkg from source
RUN git clone https://github.com/microsoft/vcpkg.git /opt/vcpkg
WORKDIR /opt/vcpkg
RUN git pull

# Building VCPKG
RUN ./bootstrap-vcpkg.sh -disableMetrics

WORKDIR /
RUN chmod -R 777 /opt/vcpkg

RUN ln -s /opt/vcpkg/vcpkg /usr/local/bin/vcpkg
