# Simple C++ Program

---

## First C++ Program of the Course

- Introduces comments
- Introduces errors and warnings
- Statements and functions
- Coding conventions. (Snake Case)
- Taking a look at `main.cpp` we see the following

```c++
// main.cpp
import utilities;
// One line comment

/*
 * This is a block comment that englobes
 * multiple
 * lines
 * of
 * text
 */

int main(){
    // This is going to print Number1, Number2, and Number3
    print_msg("Number1");
    print_msg("Number2");
    print_msg("Number3");
    print_number(5);

    int num1{5};
    int num2{6};
    int result = add_numbers(num1, num2);

    print_number(result);

    return 0;
}
```

- Compilers will ignore comments
    - As commented in the file, we add single line comments with the use of two slashes `//`
    - Block comments are added using `/**/` to encapsulate multiple lines
        - The start of the block is denoted by `/*`
        - With the end being `*/`
- `int main(){}` is where our program runs
    - It is a function
    - But the compiler specifically looks for this function as the entry point
- The following are functions we built in the `utilities.ixx` file
    - `print_msg()`
    - `print_number()`
    - `add_numbers()`
        - The functions cannot be run without being imported in
        - Which we designated at the top of our program
- `int` is a data type built into the C++ language
    - We make variables by giving them a name and initializing them
- `num1` & `num2` are variable
    - We `list initialize` them by using curly braces and putting a value between them `{5}`
        - If left empty, the default constructor of (sub)objects are called
            - Fundamental data types are initialized with `0/false/nullptr`
    - We can also assign a value by using `=`, as seen with: `int result = add_numbers(num1, num2);`
        - This operator does not have the same behavior as `list initialization`

---

## C++ Execution Model

###**_ Need to add information!!!_**

---

## Why is the C++ Execution Model Important?

To execute our function, we had to just a sizable distance from one memory location to another, keeping the return address somewhere else

- There is a feature of C++ we can use to have the function expanded in place so that it adds `int a` and `int b` directly and put the result in `int result`
    - Avoids expensive memory jumps

- Some features of C++ will allow you to:
    - Control how your program is compiled
    - How it is loaded in memory
    - How it is executed by the CPU

- In the next chapters, we will learn about buttons, knobs and handlers we can use to control how our C++ program works

---

## We will now be testing other packages

We will be using SFML, specifically their premade example script, to get understand of using `vcpkg` for our projects

- We first need to tell vcpkg we want the `SFML` package
- So we add the following to `vcpkg.json`

    ```json
    {
        "dependencies": [
            "fmt",
            "smfl"
        ]
    }
    ```

- Now we need to modify our `CMakeLists.txt` file to utilize the package in our programs
- We add the following, below or above `find_package(fmt CONFIG REQUIRED)`:

    ```text
    find_package(SFML COMPONENTS Network Graphics Window Audio System CONFIG REQUIRED)
    ```

- Then we append the following to our `target_link_libraries()` command, after `fmt::fmt`:

    ```text
    SFML::Network SFML::Graphics SFML::Window SFML::Audio SFML::System
    ```

### **_Using Docker for this project (SFML) is not recommended, in my honest opinion_**

- I tried updating my `Dockerfile` with packages that may be needed
    - I built the file
    - Ran the image
    - Then tried compiling and building the project, but it did not work
- So I am thinking of trying to use a Virtual Machine to test my project for Linux
- The project does work for my MacOS, so I think, it is a docker problem
    - Was not meant for GUI applications

### **_Not using GCC for this project_**

- Similar to Docker, this project would not build with GCC.
- The error I got said the following:
    ```commandline
    internal compiler error: in core_vals, at cp/module.cc:6641
        9 | export module utilities; // Module definition
          |        ^~~~~~
    Please submit a full bug report, with preprocessed source (by using -freport-bug).
    See <https://github.com/Homebrew/homebrew-core/issues> for instructions.
    ninja: build stopped: subcommand failed.
    ```
    - Meaning that it failed because of the compiler, not my code
- IDK what to do, but for a heads up, I will be using LLVM for my system
    - _My system being a 2017 MacBook Pro_
    - _**Another Side Note:_ I am using clang that I downloaded through Homebrew
        - Just a reminder in case someone does not read my other notes

- I also for got to mention this in my example folder, but I added the `CMAKE_OSX_SYSROOT` option to my `CMakePresets.json` file
    - Because I am using `LLVM` that was installed by Homebrew
        - I need to provide the location of my Systems SDK headers.
        - Otherwise, my projects will not build
