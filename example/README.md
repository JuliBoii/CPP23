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

## Running a Preset in the terminal

- In cases where we are not using Visual Studio Code, like my current setup, we will not be able to automatically build using our preset
    - Which we defined in our `CMakePresets.json` file
    - We will ned to run our preset in the terminal

- Before anything, we need to ensure that we are in the project location
    - Meaning, your terminal is `cd` into the location of the project folder
        - _In this case, the `example` folder_
- To check your location (in Linux and MacOS), we type in the terminal:

    ```commandline
    % pwd
    /Users/angelito/Documents/FleetProjectFiles/CPP23
    ```

- So we need to change into the example folder so we enter:
    - Then we confirm we are in the correct directory `example/`

    ```commandline
    % cd example/
    % pwd
    /Users/angelito/Documents/FleetProjectFiles/CPP23/example
    ```

- Now, the process of using our presets is fairly straightfoward.
- We can list the avaliable presets **_(If a CMakePresets.json file is present in directory)_**
    - We enter:

    ``` commandline
    % cmake --list-presets
    ```

- We enter the following in the terminal when we know which preset we want to use:

    ``` commandline
    % cmake --preset <preset name> -S .
    ```

- We can also list the build presets (if they exist) that are avaliable to us:
    - We enter:

    ``` commandline
    % cmake --list-presets=build
    ```

    - We need to take note that
        - This command will not filter out options, we are not able to use
- To build the project, we will be entering the following:

    ``` commandline
    % cmake --build --preset <build preset name>
    ```

- Now we are able to run our executable by navigating to it
- In my case, I enter the following on my MacBook:

    ``` commandline
    % ./cmake-build/Darwin/macos-llvm-debug/Example
    The values are 10 and 20
    ```

- Put all together it looks like the following:

    ``` commandline
    % cmake --preset macos-llvm-debug -S .
    % cmake --build --preset build-macos-llvm-debug
    % ./cmake-build/Darwin/macos-llvm-debug/Example
    ```

- For my Alpine enviornment on Docker it would look like:

    ``` commandline
    % cmake --preset linux-clang -S .
    % cmake --build --preset linux-clang-debug --config Debug
    % ./cmake-build/Linux/linux-clang/Debug/Example
    ```

---

## Don't want to use CMakePresets.json?

### Learning how to manually compile and build in the terminal with CMake

- We will still be using `VCPKG` to download the dependencies
    - Will be connecting vcpkg and cmake using the `CMAKE_TOOLCHAIN_FILE` flag option
- This is mainly being written in the case that you prefer:
    - Doing everything manually in the terminal
    - Or you want to test other options
- The most important step is to ensure that you are in the project location
    - Meaning, your terminal is `cd` into the location of the project folder
- To check your location (in Linux and MacOS), in the terminal we run:

    ```commandline
    % pwd
    /Users/angelito/Documents/FleetProjectFiles/CPP23
    ```

- So we need to change into the example folder so we enter:
    - Then we confirm we are in the correct directory `example/`

    ```commandline
    % cd example/
    % pwd
    /Users/angelito/Documents/FleetProjectFiles/CPP23/example
    ```

#### Building the Project

- We will now be building the project using cmake in the terminal
    - **_NOTE:_** We will be using the `CMAKE_TOOLCHAIN_FILE` option to conncet CMake and vcpkg
    - We use this option by adding a `-D` before writing the option name
        - Similar to our `CMakePresets.json` file, but we are manually entering the vcpkg source pathway
        - **_Again Noting:_** that `VCPKG_ROOT` was set for your system enviornment
- So we enter the following:

    ``` commandline
    % cmake -B cmake-build -S . -G "Ninja" -DCMAKE_TOOLCHAIN_FILE="$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake"
    ```

- Want to append something that is specific to my system, in the case that the command does not work for them
    - In my case, CMake is not able to find my system's SDK file
    - So, I added the `CMAKE_OSX_SYSROOT` option to tell CMake where to find the files needed
        - Otherwise, the command would fail
- So, my command looks like:

    ``` commandline
    % cmake -B cmake-build -S . -G "Ninja" -DCMAKE_TOOLCHAIN_FILE="$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake" -DCMAKE_OSX_SYSROOT="/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk"
    ```

- Now, just like my previous notes, my system does not have an updated C++ compiler
    - So, I used Homebrew to install an up-to-date compiler
    - But, I need to tell CMake to utilize that compiler, **_Not the pre-installed compiler_**
- So I enter the following command
    - This will include other commands that were previously discussed

    ``` commandline
    % cmake -B cmake-build -S . -G "Ninja" -DCMAKE_TOOLCHAIN_FILE="$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake" -DCMAKE_OSX_SYSROOT="/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk" -DCMAKE_CXX_COMPILER="/usr/local/opt/llvm/bin/clang++" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_COLOR_DIAGNOSTICS=ON
    ```

- After all that, we can now build the project
    - We can do this in one of two ways:
        - Move into the `cmake-build` directory
        - Or just build from the `example` directory
    - There is no difference between the two, just a matter of how you write the command
- After a successful build, we can run the executable
- You would enter the following if building from the `cmake-build` directory

    ``` commandline
    % cd cmake-build/
    % cmake --build ./
    % ./Example
    ```

- If you build from the `example` directory, you would enter:

    ``` commandline
    % cmake --build cmake-build/
    % ./cmake-build/Example
    ```

- **Again, its just a matter of preference**, nothing more
    - The last line, in each code block, is us running the executable

---
