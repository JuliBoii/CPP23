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
    - CMake
    - VCPKG


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

### _Another Note:_ For this project I will be using JetBrains' Fleet Editor, rather than VS Code. Just a matter of preference.

### If you chose to use Homebrew follow these steps

- First off, you need Homebrew
- Run the following in your terminal

    ```commandline
    % /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    ```

- Then we install the following:
    - Ninja
    - LLVM
    - GCC
    - CMAKE
    - Git
    - gh
    - pkgconf (for our Vcpkg installation)
- We run:

    ```commandline
    % brew install ninja cmake git gh llvm gcc pkgconf
    ```

- That covers most of the tools we will be using
- If `git` is not set up we need to run the following (optional)
    - replace the content in quotation with your respective information

    ```commandline
    % git config --global user.email "email@example.com"
    % git config --global user.name "usrexample"
    ```

- We use the following command to connect our `git` with `GitHub`. (My preferred repo)
- This should cover everything we need, aside from `VCPKG`
- We run the following to connect the two:

    ```commandline
    % gh auth login
    ```

- In a terminal we want to ensure we are in the home directory so run:

    ```commandline
    % cd ~/
    ```

- Now we need to install vcpkg into our MacOS system
- We run the following commands in the terminal

    ```commandline
    % git clone https://github.com/microsoft/vcpkg.git
    % cd vcpkg && ./bootstrap-vcpkg.sh
    ```

- Then we run:

    ```commandline
    % cd ../
    % chmod -R 777 /vcpkg
    ```

- Now we want to set our enviornment variables to use `VCPKG` in our projects
- In a terminal we want to ensure we are in the home directory so run:

    ```commandline
    % cd ~/
    ```

- We want to open our shell's profile script
- The profile script can be any of the following:
    - `.bashrc`
    - `.bash_profile`
    - `.zshrc`
    - `.zsh_profile`
    - `.zprofile`
    - `.profile`
- In my case it is `.zprofile`.
- We can see what its called by outputing the files in our Home Directory
- We use the following command to list the files, even hidden ones

    ```commandline
    % ls -a
    ```

- We open the file using any code editor of choice, for simplicity I used `nano` in the terminal.
- So I ran the command:

    ```commandline
    % nano .zprofile
    ```

- We add the following:

    ```shell
    % export VCPKG_ROOT="$HOME/vcpkg"
    % export PATH="$VCPKG_ROOT:$PATH"
    ```

- Then we refresh to apply our changes to our current terminal session
- Run the following in the termianl
    - _Again as a reminder_, you should change the file name to match your shell profile's

    ```commandline
    % source ~/.zprofile
    ```

- _Remember this is for an Intel-based Mac, not sure if this will work for an ARM-based Mac_
- We should be good after this step
---

## Modern C++ On Docker

---

### What is Docker?

Docker lets you run applications inside **lightweight, isolated enviornments** called **containers**.

Ensures consistency across different systems.

- Avoids _"It worked on my machine"_ problems
- Get a consistent dev setup everywhere
- use newer compilers hassle-free
- Run different C++ versions easily

---

* Isolated C++ Enviornment


[Code] ---> Runs ---> [Container]


* Preconfigured System & Tools


[Container] ---> Uses ---> [Docker Image]

---

Essential Commands:

- Build:

    ``` commandline
    % docker build -t my_cpp_env
    ```

- List:

    ``` commandline
    % docker images
    ```

- Run:

    ``` commandline
    % docker run -it my_cpp_env
    ```

- Stop:

    ``` commandline
    % docker stop <container_id>
    ```

[Use the following link for Docker Setup Instructions](https://github.com/rutura/cpp23m/blob/main/02.EnvironmentSetup/06.Docker_setup.md)

_Or utilize the Dockerfile I provide in my root directory and build it_

---