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