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