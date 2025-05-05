# Enviornment Setup

- Windows
- Linux
- Mac
- Docker
    - Containerized Enviornments
- Compiler Exploration
    - Using an online complier

- Understanding the Tools:
    - C++
    - Cmake
    - Vcpkg


---

## Modern C++ On Windows

---
[Visual Studio IDE] ----> (cl.exe) Complier

[CMake] ---- Uses ----> (cl) Compiler

[Vcpkg] ----> Manages Packages

[Ninja] ----> Build System

[Visual Studio Code] ----> Editor

- Extensions:
    - C++ Language Server for IntelliSense
        - Microsoft C++ Extension
        - codelldb & clangd (Better in some tasks, uses Clang tools)
    - CMake Extension
    - CMake Tools Extension

[Uses following link for Windows install instructions](https://github.com/rutura/cpp23m/blob/main/02.EnvironmentSetup/03.Windows_setup.md)

---

## Modern C++ on Linux (Ubuntu 24.04)

---
[Clang 19] ----> (clang++) Complier

[CMake] ---- Uses ----> (clang++)

[Vcpkg] ----> Manages Packages

[Ninja] ----> Build System

[Visual Studio Code] ----> Editor

- Extensions:
    - C++ Language Server for InteliSense
        - Microsoft C++ Extension
        - codelldb & clangd (Better in some tasks, uses Clang tools)
    - CMake Extension
    - CMake Tools Extension

[Uses following link for Ubuntu install instructions](https://github.com/rutura/cpp23m/blob/main/02.EnvironmentSetup/04.Linux_setup.md)

---

## Modern C++ on Mac (Apple Clang)

---

[Apple Clang] ----> (clang++) Compiler (Default on MacOS)

[CMake] ---- Uses ----> (clang++)

[Vcpkg] ----> Manganges Packages

[Ninja] ----> Build System

[Visual Studio Code] ----> Editor

- Extensions:
    - C++ Language Server for InteliSense
        - Microsoft C++ Extension
        - codelldb & clangd (Better in some tasks, uses Clang tools)
    - CMake Extension
    - CMake Tools Extension

### **! Apple Clang tends to lag behind in C++ features !**

Consider using Docker for access to newer versions of Clang or GCC if needed

[Use following link for MacOS install instructions](https://github.com/rutura/cpp23m/blob/main/02.EnvironmentSetup/05.Mac_setup.md)

[_Side Note:_ Many of these installations are easier using package managers like Homebrew](https://brew.sh/)

### _Another Note:_ For this project I will be using JetBrains' Fleet Editor, rather than VS Code.
