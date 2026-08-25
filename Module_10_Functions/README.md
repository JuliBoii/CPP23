# Functions

A function is a reusable block of self-contained code. \
Designed to perform a specific, single task. Which alleviates the need to write the same code over and over, again. With
a function, we simply write it once, then "call" it whenever we need it.

This is nothing new, since we have been using functions already in previous modules. We are simply defining what a
function is and how we can utilize them.

## Declaration & Definition

Declaring a function is simply telling the compiler that an "independent" code block exist. While defining a function
entails the actual code being written inside the declaration.

### Declaration

To declare a function we need to define the following:

- Return Type:
  - The data type of the value the function, if applicable, will return
    - For `void` type, we do not return a value
- Function Name
  - A valid C++ identifier used to invoke the function
    - Cannot use a number or special character at the start of the name
    - Compiler will fail to compile
- Optional
  - Parameter List
    - A comma separated list inside a pair of parentheses `()`.
    - Each parameter has to have a respective data type
      - The names/alias of the respective parameters is optional
    - These parameters are input types that we pass to the function, when calling it
  - Semicolon (`;`)
    - If we want to declare a function, but define it later on
      - We add a terminating semicolon following the parameter list

Put together we have:

```c++
return_type function_name(parameter_type_1 /*parameter_name_1*/, parameter_type_2 /*parameter_name_2*/);
```

### Define

To define a function we have two options, as briefly mentioned. We can either define the function seperate from the
declaration or together with the function.

- If we define it later on, we simply write the declaration again.
  - Except, if we did not provide names to our parameters list
    - We must include parameter variable names so we can reference them inside the code block
  - Then, rather than a trailing semicolon
    - We add a pair of curly braces `{}`
      - This is where our code block will be

So, in general, to define a function, you need:

- Return Type, Function Name, & (If any) Parameter List
  - Must match our declaration
  - Must include variable parameter names
- Function Body
  - A block of code enclosed in curly braces `{}`
- Return Statement (if applicable)
  - If return type is `void`
    - We do not have to include `return` keyword
  - Elsewise, we need to include the `return` keyword with a value of matching return type

Put together we have:

```c++
return_type function_name (parameter_type_1 /*parameter_name_1*/, parameter_type_2 /*parameter_name_2*/) {
    // Code
    return return_type_value; // not needed if return_type is void
}
```

> In general, functions should be simple and compact. Being constrained to do a task. For example, a function to
> download files form the internet, or encrypt a file. While not enforced by a compiler, having a function do multiple
> tasks is looked down upon. As it can be verbose and confusing.

## Module files

Throughout the course, we have been using a single module file to implement external functions. But, there may be times
when we do not want to expose the implementation of our functions. Simply showcasing the functions available. We achieve
this by seperating the interface/declarations from the implementation.

We achieve this by creating two seperate files:

- An interface file
  - Often having the `.ixx` or `.cppm` extensions
  - This is where we will have our function declarations
    - Need to add the `export` keyword in front of functions we want to be accessible
      - When importing the module in a separate file
  - We do not have to implement anything, just declare them
  - If implementation needs legacy, non-modularized header files (like OpenSSL or old C-headers),
    - Must be placed/declared in a global module fragment at the very top of interface file
    - Such as:

```c++
module;

#include <fmt/format.h> // Added before the export module line

export module module_name;
```

- An implementation file
  - Often having the `.cpp` extension
  - This is where we fully implement the functions we declared in the interface file
    - We **do not** add the `export` keyword when writing out the function
      - `export` is never in the implementation file
  - To use legacy, non-modularized files
    - We redefine the Global Module Fragment
    - Similar the interface file
      - Add `module` keyword on the first line
      - Include header files
      - Then declare `module module_name;`
    - Keeping the implementation file completely self-contained

## Passing Parameters

We will now discuss how we can pass parameters to a function. Let us view the different possibilities.

### Pass by Value

In this case, the function receives a copy of the value passed to it.

```c++
int add(int a, int b);
```

This method is best used for small data types, such as:

- `int`
- `double`
- `char`

This is a safe and reliable method. Specifically, original data cannot be accidentally altered. But, can be inefficient
for large objects since we are creating a copy.

### Pass by Reference

In this case, the function receives a reference to the value passed to it. So, it is working with the original variable,
rather a copy.

```c++
int add(int& a, int& b);
```

This method is best used for cases that modify the original variable. This method is fast, since we do not need to
create copies of the argument passed. And allows for returning multiple values through parameters. But, an argument that
takes a reference cannot accept literal values directly, i.e. `3`, `"hey"`, `false`, etc. Doing so will cause a compiler
error.

#### Pass by `const` Reference

This is a case where we add the `const` keyword along with the reference operator.

```c++
int add(const int& a, const int& b);
```

This method is suited for cases where we do not want to modify the data being passed. Nor, do we want the program to
make copies of the variable data. Suitable with large read-only objects such as:

- `std::string`
- `std::vector`
- etc.

In general, passing by `const` reference is highly efficient and safe from unintended modifications. Plus, passing by
`const` reference can accept both variables and temporary literals.

> The use of `const` is not limited to references, simply wanted to showcase it here. We can combine `const` with any of
> the other passing methods if we chose too.

### Pass by Pointer

In this case, the function receives a pointer to the value passed to it.

```c++
int add(int* a, int* b);
```

In this case, rather than creating a copy of the value passed, it creates a copy of a variables address. So, we are
using a copy of the variables address to modify the original variable. Plus, allows for an argument to be a
`nullptr`, which is useful for parameters that are optional. But the downside is the complex syntax of pointers. While
simple uses of pointers is not complicated, they can gradually become more complex, especially if working with various
pointers. Requiring manual checks to avoid crashes.

### Default Parameter

In this case, a parameter of the function has a value has been defined when declared in the parameter list of the
function.

```c++
int add(int a = 10, int b = 8);
```

This method allows for calling the function without having to pass any parameters. This is useful in cases where a
person may forget or choose to leave an argument blank, the compiler will automatically use the backup value stored.

With default parameters, it is best practice to put all default parameters at the very end of the parameter list. Since,
a person fills out the arguments from left to right, it can be confusing if a required parameter comes after an optional
one.

If splitting the function declaration and definition, one only needs to define the default parameters in the definition.
The declaration does not need to be rewritten with the default values.

## Passing Sequences & Arrays

We are writing a seperate section for sequences and arrays since we do need to think differently when passing them. Plus
the method for passing changes depending on the use of old-school C-style arrays or Modern C++ containters.

### Modern C++ Sequences

For modern containers, such as `std::vector` or `std::array`, it is usually recommended to pass by `const` reference.

This is due to the massive amount of data a modern container could hold. So to prevent our program from slowing down due
to the creation of copies of the container passed, we pass them by reference. `const` helps prevent the function from
accidentally altering the data.

```c++
void print_vector(const std::vector<int>& vec);
```

But if we do want to modify our original container, we simply do not include the `const` keyword, still utilizing the
reference operator.

```c++
void update_vector(std::vector<int>& vec);
```

### Old-school C-style Arrays

When dealing with raw arrays, like `int arr[4]`, we use a different approach. Raw arrays cannot be passed by value.
Thus, when passing a raw array, it automatically decays/transforms into a pointer (to its first element).

Since a pointer does not provide information about the container, one also needs to pass the size of the array as an
additional argument.

```c++
void print_raw_array(const int arr[], int size);
```

### C++ Span (C++20)

For newer compilers, the C++20 standard introduced a new method of passing sequences. The introduction of
`std::span`. This acts as a lightweight, non-owning window to **any** kind of sequence. Whether a raw array,
`std::vector`, or `std::array`.

`std::span` is incredibly fast, due to being passed by value. Not memory expensive, since a `std::span` holds a pointer
and a size under the hood. So it works seamlessly with both old and new array styles.

```c++
#include <span>
#include <vector>
#include "fmt/format.h"

void print_sequence(std::span<const int> span_view) {
    for (auto& num : span_view) {
        fmt::println("{}", num);
    }
}

int main() {
    int raw_arr[] = {1, 2, 4, 5};
    std::vector<int> vec = {14, 41, 44};
    
    print_sequence(raw_arr);
    print_sequence(vec);
}

```

## `constexpr` and `consteval` Functions

Refresher, `constexpr` and `consteval` are special keywords that are utilized to tell the compiler a given section/line
of code should be run when compiling the program. Rather than having the code run at runtime, when the user calls it.

Utilizing these keywords helps our program run faster, since the math or logic is already done before the program even
starts.

### `constexpr` Function

A `constexpr` function is flexible. Meaning, it can be run at compile-time _or_ runtime. Depending on the use case.