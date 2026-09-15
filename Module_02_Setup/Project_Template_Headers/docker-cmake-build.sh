#! /bin/bash

cmake --preset linux-clang -S ./ -B build/
cmake --build build
