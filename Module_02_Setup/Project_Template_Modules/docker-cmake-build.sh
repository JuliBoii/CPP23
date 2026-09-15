#! /bin/bash

cmake --preset linux-clang -S ./
cmake --build --preset linux-clang-debug
