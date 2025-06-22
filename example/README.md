# Template Folder for Dockerfile Enviornment in CPP23

---

## Understanding the files in the Directory

### CMakeLists.txt

- This is the main configuration file for `CMake`, the build system generator.
    - So, CMake will take the files and process them
    - CMake can also generate build files for different build systems
        - For example:
            - On Windows, you can have Visual C++, MinGW, MSVC, Ninja
        - Setting up differing builds will be discussed later
- Defines how the project should be built, including source files, dependencies, and compiler settings
- Specifies the project name, version, and any libraries or external dependencies required
- CMake will use `CMakeLists.txt` to generate appropriate build files (e.g., Makefile, Visual Studio project files)

### CMakePresets.json

- This is also a `CMake` file
- This file will be used to take some load off of `CMakeLists.txt`, so it is easier to build our project
- Provides a standardized way to define CMake configurations for different build environments.
- It stores settings for differnt build presets, such as compiler options, architecture ,and toolchains, ensuring a consistent build setup across different platforms
- Useful for managing different build types (e.g., Debug, Release) and compiler toolchains in a portable way

### main.cpp

- This is typically the entry point of the C++ application
- Contains the `main()` function, where program execution starts
- May include other files and logic to initialize and run the application, such as creating objects, calling functions, and managing flow control

### utilities.ixx

- As seen in other directories within `CPP23`, the `.ixx` file extension is used to denote for C++20 Modules
    - But this is not the only extension for these types of files
    - _I personally may use_ `.mpp` _as the file extension, not too sure yet_
- This is a C++20 module interface file
- Defines a module named utilities, exposing functions, types, or constants that can be imported by other source files
- Using modules improves the efficiency of the build process, as the compiler can better manage dependencies and reduce redundant compilations
- May include utility fucntions or classes commonly used in the project

### vcpkg.json

- File is used to manage dependencies through vcpkg, a C++ package manager
- It list the libraries and packages needed for the project
- vcpkg will read `vcpkg.json` to install and manage the dependencies, ensuring that the correct version of libraries are used

### .gitignore

- This file specifies which files and directories Git should ignore during version control
- Typically includes build artifacts (like *.o, *.a, *.exe), temporary files, or IDE-specific configuration files that should not be tracked in the repository
- Ensures that only relevant source files and configurations are committed to the Git repo, avoiding clutter

---

## Don't want to use CMakePresets.json?

### Learning how to manually compile and build in the terminal with CMake

- We will still be using `VCPKG` to download the dependencies
    - Will be connecting vcpkg and cmake using the `CMAKE_TOOLCHAIN_FILE` flag option
- This is mainly being written in the case that you prefer:
    - Doing everything manually in the terminal
    - Or you want to test other options
- The most important step is to ensure that you are in the project
    - Meaning, your terminal is `cd` into the location of the project folder
- To check your location (in Linux and MacOS), in the terminal we run:

    ```commandline
    % pwd
    /Users/angelito/Documents/FleetProjectFiles/CPP23
    ```

- So we need to change into the example folder so we enter:

    ```commandline
    % cd example/
    % pwd
    /Users/angelito/Documents/FleetProjectFiles/CPP23/example
    ```
