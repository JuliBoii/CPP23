# Pointers, Dynamic Memory, & Arrays

---

<!-- TOC -->

* [Pointers, Dynamic Memory, & Arrays](#pointers-dynamic-memory--arrays)
    * [Pointers](#pointers)
        * [Declaring & Initializing](#declaring--initializing)
    * [Memory Layout](#memory-layout)
        * [Quick Warning](#quick-warning)
        * [Declaring & Initializing (Cont.)](#declaring--initializing-cont)
        * [Assignment & Access](#assignment--access)
            * [Accessing Address stored in Pointer](#accessing-address-stored-in-pointer)
            * [Accessing Value Stored in Address Being Pointed by a Pointer (Dereference)](#accessing-value-stored-in-address-being-pointed-by-a-pointer-dereference)
            * [Accessing the Address of a Pointer (Reference)](#accessing-the-address-of-a-pointer-reference)
        * [Pointer Re-assignment](#pointer-re-assignment)
        * [`Char` Pointers](#char-pointers)
    * [Working with Pointers & `const` keyword](#working-with-pointers--const-keyword)
        * [Raw Variables That Can Be Modified](#raw-variables-that-can-be-modified)
        * [Non-`const` Pointer to Non-`const` Data](#non-const-pointer-to-non-const-data)
        * [Non-`const` Pointer to `const` Data](#non-const-pointer-to-const-data)
        * [(Semi) `const` Pointer to Non-`const` Data](#semi-const-pointer-to-non-const-data)
        * [`const` Pointer to `const` Data](#const-pointer-to-const-data)
        * [`const` Pointer & Non-`const` Data](#const-pointer--non-const-data)
    * [Relationship Between Pointers & Array's](#relationship-between-pointers--arrays)
    * [Pointer Arithmetic](#pointer-arithmetic)
        * [Navigation](#navigation)
            * [Explicit Addition](#explicit-addition)
        * [Distance](#distance)
            * [`std::ptrdiff_t`](#stdptrdiff_t)
        * [Comparisons](#comparisons)
    * [Dynamic Memory Allocation](#dynamic-memory-allocation)
        * [Uninitialized Pointers Are Bad](#uninitialized-pointers-are-bad)
        * [Dynamic Memory](#dynamic-memory)
        * [Other Methods of Initialization for Dynamic Memory](#other-methods-of-initialization-for-dynamic-memory)
        * [Reusing Pointers](#reusing-pointers)
        * [Properly Pair `new` and `delete`](#properly-pair-new-and-delete)
    * [Dangling Pointers](#dangling-pointers)
        * [Case 1: Dangling Uninitialized Pointer](#case-1-dangling-uninitialized-pointer)
            * [Solution for Uninitialized Pointer](#solution-for-uninitialized-pointer)
        * [Case 2: Using a Deleted Pointer](#case-2-using-a-deleted-pointer)
            * [Solution for Using a Deleted Pointer](#solution-for-using-a-deleted-pointer)
        * [Case 3: Multiple Pointers Pointing to the Same Address](#case-3-multiple-pointers-pointing-to-the-same-address)
            * [Solution for Multiple Pointers Pointing to the Same Address](#solution-for-multiple-pointers-pointing-to-the-same-address)
    * [When `new` fails](#when-new-fails)
        * [Use `exception`](#use-exception)
        * [Use `std::nothrow`](#use-stdnothrow)
    * [Tips for Pointers](#tips-for-pointers)
        * [`NULL` Pointer Safety](#null-pointer-safety)
        * [Memory Leaks](#memory-leaks)
            * [One Does Not Release Allocated Memory](#one-does-not-release-allocated-memory)
            * [Double Memory Allocation](#double-memory-allocation)
            * [Nested Scope with Dynamically Allocated Memory](#nested-scope-with-dynamically-allocated-memory)
    * [Dynamic Arrays](#dynamic-arrays)
        * [Dynamic v.s. Static Array's](#dynamic-vs-static-arrays)
    * [Smart Pointers](#smart-pointers)
        * [`std::unique_ptr`](#stdunique_ptr)
            * [C++14 Updates](#c14-updates)
            * [Cannot Make Copies with `unique_ptr`](#cannot-make-copies-with-unique_ptr)
            * [Moving a `unique_ptr`](#moving-a-unique_ptr)
            * [Resetting `unique_ptr`](#resetting-unique_ptr)
            * [`unique_ptr` As Function Parameters & Return Values](#unique_ptr-as-function-parameters--return-values)
            * [`unique_ptr` and Array's](#unique_ptr-and-arrays)
        * [`std::shared_ptr`](#stdshared_ptr)
            * [Copy `shared_ptr`'s](#copy-shared_ptrs)
            * [Other Methods for Declaration & Initialization](#other-methods-for-declaration--initialization)
            * [Using `shared_ptr` to Manage Existing Memory](#using-shared_ptr-to-manage-existing-memory)
            * [Reset(): Decrement the Use Count & Set Ptr to
              `nullptr`](#reset-decrement-the-use-count--set-ptr-to-nullptr)
            * [`std::make_shared`](#stdmake_shared)
            * [Creating a `shared_ptr` from `unique_ptr`](#creating-a-shared_ptr-from-unique_ptr)
            * [Returning a Smart Pointer](#returning-a-smart-pointer)
            * [`shared_ptr` with Arrays (C++17 and above)](#shared_ptr-with-arrays-c17-and-above)
            * [`shared_ptr` as function parameters & return value](#shared_ptr-as-function-parameters--return-value)
                * [Pass by Value](#pass-by-value)
                * [Pass by Non-`const` Reference](#pass-by-non-const-reference)
                * [Pass by `const` Reference](#pass-by-const-reference)
                * [Return by Value](#return-by-value)
                * [Return by Reference](#return-by-reference)
        * [`std::weak_ptr`](#stdweak_ptr)
            * [What is a `weak_ptr` useful for?](#what-is-a-weak_ptr-useful-for)
                * [Compile-Time: The Size and Include Dilemma](#compile-time-the-size-and-include-dilemma)
                * [Runtime: The `shared_ptr` Memory Leak](#runtime-the-shared_ptr-memory-leak)
    * [References](#references)

<!-- TOC -->

---

## Pointers

We will be starting to explore pointers in C++. With pointers being one of the most confusing
parts of C++. Realistically, they are not hard concepts to understand.

**A pointers is a variable that contains an address of another variable.**

Based on this we can categorize variables of two types:

1. Data Variables
    1. Used for storing data
2. Address Variables
    1. Used for storing addresses in memory

Suppose we have an `int` variable declared in our C++ program. When we declare a variable,
the compiler/computer will reserve memory for this declared variable. The memory is going to
be an address, where the literal `42` wil be stored.

```c++
int num {42};
```

| `int` variable (visual example) |
|:--------------------------------|
| Name: num                       |
| Value: 42                       |
| Address: 0x7ffe                 |

Thus, we can declare another variable which stores the address to our variable's value.

```c++
int *ptr = &num;
```

| Pointer `var`                    |
|----------------------------------|
| Name: ptr                        |
| Value: 0x7ffe (Address of `num`) |
| Address: 0x8abc                  |

For clarity, `int` is a data type and a `pointer` is a type which contains addresses pointing to other
variables. So it looks like the following (for visual aid):

| Memory Address (Hex) | Memory Value                   |
|----------------------|--------------------------------|
| 0x7ffe ->            | 42 (Value of `num`)            |
| 0x8abc ->            | 0x7ffe (Value stored by `ptr`) |

Lets breakdown the syntax for declaring & initializing a pointer.

### Declaring & Initializing

```c++
int *ptr = &variable_name;
```

- The most evident change is the `*` after declaring the data type
    - This paired with a `datatype` makes a pointer
- We give the pointer a name: `ptr`
- Then we obtain the address of the variable we want to point to
    - So we use the assignment operator (`=`)
    - Get `variable_name`'s address using an ampersand in front: `&`.

Before continuing with our topic, we need more foundational understanding of memory layout.

## Memory Layout

When building a C++ program and compile, the information is going to be laid out in memory
to something called "memory map". This will be storing information about the memory our
application will be using.

This memory is broken up into a few parts, but we will focus on the stack and heap.

| Memory Layout                                                                                                                                    |
|--------------------------------------------------------------------------------------------------------------------------------------------------|
| Stack (High Memory Address/Grows Downward):<br/>- Local variables<br/>- Function call frames<br/>- Operates in a Last-In-First-Out (LIFO) manner |
| ...                                                                                                                                              |
| Heap (Grows upward):<br/>- Dynamically Allocated Memory<br/>- Managed via `new`/`delete` in C++                                                  |
| Unitialized Data (.bss segment):<br/>- Uninitialized Globals<br/>- Uninitialized Statics                                                         |
| Initialized Data (.data segment):<br/>- Initialized Globals<br/>- Initialized Statics<br/> - They default to zero                                |
| Code Segment (.text segment):<br/>- Executable Instructions                                                                                      |

So for simplicity:

| Why Pointers?              |
|----------------------------|
| Heap:                      |
| Stack:                     |
| Code Section:<br/>`main()` |

Our main function/program will live in the code segment. Outright it will be able to access two sections
of memory: code section and stack.

The program will not be able to directly access any other section. So the program makes a policy
that it will not access any other thing directly except the code section or stack.

So, can our program directly access the heap? No.

How are we supposedly accessing the heap then?

The program is indirectly accessing the heap. We declare a pointer and that pointer can have
an address of some memory in the heap. Thus, the pointer will help the main function of the
program to access the heap section.

So what is the point of pointers?

To access the heap.

| Aspect         | Stack                              | Heap                              |
|----------------|------------------------------------|-----------------------------------|
| Structure      | Linear (LIFO)                      | Hierarchial                       |
| Allocation     | Automatic (By Compiler)            | Manual (By Programmer)            |
| Access Speed   | Faster                             | Slower                            |
| Memory Size    | Typically Limited                  | Generally Larger                  |
| Fragmentation  | Rarely Fragmented                  | Can become fragmented             |
| Scope/Lifetime | Local to function<br/>Short lived  | Global access<br/>Persists longer |
| Flexibility    | Fixed Sized<br/>Not Resizable      | Resizable<br/>Dynamic Allocation  |
| Security       | Tread-Specific<br/>Safer           | Accessible by all treads          |
| Use Cases      | Local Variables<br/>Function Calls | Dynamic Memory Allocation         |

There are other reasons too.

Suppose we have a file on a disk. How can the file be accessed by a program? Can the
program directly access it?

No. Again, we can access it indirectly with the help of a pointer. We use file pointers
to access files.

Then, if there is a network connection, how can a program access a network connection?

Again, we utilize a pointer.

If there's a mouse, keyboard, monitor, printer, etc. connected to the computer.
All of them can be accessed by a program, indirectly, with the help of pointers.

That is why C++ is used to do system and operating programming or developing drivers.

As previously mentioned, the stack stores our local variables and function calls.
While the heap is for dynamic memory, memory that is not prepared and assigned by the
compiler/computer.

We can also utilize the heap using the `new` and `delete` operators

### Quick Warning

> Raw pointers should be used sparingly, after careful consideration in Modern C++. Smart Pointers and RAII should be
> your default way of doing things, so you rarely have to deal with memory manually.

Why is this important?

Because pointers are the source of lots of bugs. Deadly depending on the application of one's program.

### Declaring & Initializing (Cont.)

```c++
double* p_fractional_number{};

int* p_number{ nullptr };
```

As showcased earlier, we can make pointers by simply stating a `datatype` and adding `*` after

In the example above we are not initializing the pointer with an address. But rather than having
the pointer be filled with junk data, we use curly braced initialization. So the pointer will be
initialized with the `0` equivalent for an address being `nullptr`.

for the `int*` pointer we are explicitly initializing the pointer with `nullptr` rather than leaving
the curly brace empty. However, both result in the same initialization.

Now let us look at the `sizeof()` a pointer:

```c++
std::println("sizeof(int): {}", sizeof(int));
std::println("sizeof(double): {}", sizeof(double));
std::println("sizeof(int*): {}", sizeof(int*));
std::println("sizeof(double*): {}", sizeof(double*));
std::println("sizeof(p_number): {}", sizeof(p_number));
std::println("sizeof(p_fractional_number): {}", sizeof(p_fractional_number));
```

This prints the following:

```terminaloutput
sizeof(int): 4
sizeof(double): 8
sizeof(int*): 8
sizeof(double*): 8
sizeof(p_number): 8
sizeof(p_fractional_number): 8
```

What do we notice?

Despite the different data types used, the pointers are the same number of bytes.

Why is that?

Because, pointers are holding addresses of memory. Regardless of data type, the size of a memory addresses
will be the same. But the size of the address can be different depending on your compiler, architecture,
and processor.

Overall, the pointers will be the same size regardless if the pointer is an `int`, `double` or other `datatype`.

### Assignment & Access

Let us look at an example of how to assign and access data to a pointer.

```c++
int integer_var{42};
int *p_int{&integer_var};
```

- We first need a variable to point to
    - We declare an `int` variable: `integer_var`
    - And initialize the variable
- Now we declare our pointer variable
    - Of same type as `integer_var`: `int *`
- Then initialize the pointer
    - Adding `&`, prefixing `integer_var`
    - This assigns the address of `integer_var` to `p_int`

We can now use the pointer.

First we just want to see the various options when accessing a pointer.

#### Accessing Address stored in Pointer

```c++
std::println("Address of integer_var: {}", static_cast<void*>(&integer_var));
std::println("Address stored in p_int: {}", static_cast<void*>(p_int));
```

In this example we are showing how to access the address stored in the pointer.

- We first are printing the address of the data variable
    - Which we access using `&`
- Then we print the address stored in the pointer by
    - Using the `p_int` pointer by itself

Running this prints out:

```terminaloutput
Address of integer_var: 0xb1656ff7b4
Address stored in p_int: 0xb1656ff7b4
```

Comparing the two addresses, we see they are identical. _Note:_ each time
we run the program, will return different addresses. For the fact that the
operating system will give you different pieces of memory. So the location/address
of our variables will not be under our control. The operating system will simply
give you memory that it has available.

#### Accessing Value Stored in Address Being Pointed by a Pointer (Dereference)

```c++
std::println("Value of integer_var: {}", integer_var);
std::println("Value of Stored Address in p_int: {}", *p_int);
```

In this example we are showing how to use the pointer to access the data stored
at the address of the data variable.

- Once again, we print the data stored in `integer_var`
    - Simply by stating the variable
- With the pointer, we are prefixing `p_int` with `*`
    - This is referred to as dereferencing the pointer

Running this prints:

```terminaloutput
Value of integer_var: 34
Value of Stored Address in p_int: 34
```

Again, the values are the same. Meaning we were able to access and print
the data stored at the address pointed to by our pointer.

#### Accessing the Address of a Pointer (Reference)

```c++
std::println("Address of p_int: {}", static_cast<void*>(&p_int));
```

In this example we want to show that, just like data variables,
address variables have addresses too.

- Similar to how we initialized our pointer
    - We add an `&` in front of our pointer variable name
        - `&p_int`
    - This returns the address of the pointer
        - Also referred to as "reference"

Running this prints:

```terminaloutput
Address of p_int: 0xb1656ff7d8
```

### Pointer Re-assignment

We are able to change the address being pointed to by the pointer. Look
at our example below:

```c++
std::println("Old Address stored in p_int: {}", static_cast<void*>(p_int));

int integer_var_2{13};
p_int = &integer_var_2;

std::println("New address stored in p_int: {}", static_cast<void*>(p_int))
```

In the example we are:

- Printing the old address stored
    - For comparison
- We declare and initialize a new variable
    - `integer_var_2`
- Then assign the address of `integer_var_2` to `p_int`
    - Using `&`
- Printing the new address stored by `p_int`

This results in the following:

```terminaloutput
Address of p_int: 0x31af7df784
New Address of p_int: 0x31af7df7c4
```

> Note: We cannot cross assign pointers of differing `datatype`.

```c++
int *p_int{nullptr};
double double_var{414.341};

p_int = &double_var;
```

In this example we are:

- Declaring a pointer of type `int`
    - `p_int`
- Along with a variable of type `double`
    - `double_var`
- Then we are assigning the address of `double_var` to `p_int`
- When compiled, we receive an error like below:

    ```c++
    pointer1.ixx(55): error C2440: '=': cannot convert from 'double *' to 'int *'
    pointer1.ixx(55): note: Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or parenthesized function-style cast
    ```

### `Char` Pointers

For this section, there is nothing different from what we have been doing. The only difference
is working with the `char` data type. Below is a simple example of an array:

```c++
const char *message{"Hello world!"};
```

When we make a raw array. The name we assign to the variable,
is a pointer to the first element. This behavior is not exclusive to
raw arrays, just wanted to mention it here.

In the example above we make the array `const`. What if we want to modify
the data.

We simply use a different syntax when declaring & initializing.

```c++
char message[]{"Hello World"};
```

- We specify that our `char` type is an array
    - Using `[]`
- Then initialize the array with a string literal
    - Indicated by using double quotes
    - The compiler will understand what we are trying to accomplish
    - Thus, we will be able to modify elements within the array

```c++
*message = 'B';
std::println("Message: {}", message);
```

Resulting in the following output:

```terminaloutput
Message: Bello World
```

The C++ code also showcases our previous point. The variable name, most of the time,
is a "Pointer".

## Working with Pointers & `const` keyword

We will be exploring the concept of how one can combine pointers and constants.
Meaning, we may have a piece of data living somewhere in our program, with a
pointer pointing to that piece of data.

We can make the pointer `const`, thus one cannot use the pointer to modify
the data it is pointing to.

Or we can make the data `const`, thus the data cannot change regardless of what is
pointing to it.

### Raw Variables That Can Be Modified

In this example/case we want to see a situation where we are able to modify a
raw variable. Seeing what we should expect.

```c++
int number{5}; // Not const

std::println("Number: {}", number);
std::println("Number Address: {}\n", static_cast<void*>(&number));

std::println("Modifying 'number':");
number = 12;
number += 13;

std::println("New Number: {}", number);
std::println("Number Address: {}", static_cast<void*>(&number));
```

In the example above we are doing the following:

- Declaring a variable
    - That is not `const`
- Printing the literal stored in the variable
- Printing the address of the variable
- Then modifying the information stored.
    - Reassigning the literal to `12`
    - Then compound summation with `13`
- Finally, we print the new literal
- Then the address of the variable

Resulting in the following:

```terminaloutput
Number: 5
Number Address: 0x7ff7bd055c5c

Modifying 'number':
New Number: 25
Number Address: 0x7ff7bd055c5c
```

Notice what happened:

- We were able to change the literal stored
    - Due to the variable not being `const`
- The address of the variable remains the same

### Non-`const` Pointer to Non-`const` Data

In this example/case we want to see a situation where we are able to modify a
variable and pointer.

```c++
int *ptr_number1(nullptr);
int number1{23};

ptr_number1 = &number1;
std::println("ptr_number1 Address: {}", static_cast<void *>(ptr_number1));
std::println("ptr_number1 Value Pointed To: {}", *ptr_number1);
std::println("number1 Value Stored: {}", number1);
std::println("number1 Address: {}", static_cast<void *>(&number1));
```

In the example above we are doing the following:

- Declaring & initialing a pointer: `ptr_number1`
    - Init to `nullptr`
- Declaring & initializing a variable: `number1`
- We then assign the address of `number1` to `ptr_number1`
    - Using the `&` operator

From here we print the following:

- Printing the address stored in `ptr_number1`
- Printing the value stored in the address we printed
- Print the literal stored in the variable `number1`
- Then the address of the variable

Resulting in the following:

```terminaloutput
ptr_number1 Address: 0x4ddbf9f6e4
ptr_number1 Value Pointed To: 23
number1 Value Stored: 23
number1 Address: 0x4ddbf9f6e4
```

With the result, we wanted to confirm the address being pointed to by
`ptr_number1` is the same as `number1` and that we can access the data
stored.

Now let us modify the value stored by `number1` using the pointer.

```c++
*ptr_number1 = 432;
std::println("ptr_number1 Address: {}", static_cast<void *>(ptr_number1));
std::println("ptr_number1 Value Pointed To: {}", *ptr_number1);
std::println("number1 Value Stored: {}", number1);
std::println("number1 Address: {}", static_cast<void *>(&number1));
```

Resulting in the output:

```terminaloutput
Reassigning the value stored through a the pointer:
ptr_number1 Address: 0x4ddbf9f6e4
ptr_number1 Value Pointed To: 432
number1 Value Stored: 432
number1 Address: 0x4ddbf9f6e4
```

Notice what happened:

- We were able to change the literal stored
    - Storing `432` instead of `23`
    - We were able to do this due to `number1` not being `const`
- The address of the variable remains the same
    - Showing the location of the data has not changed

Likewise, since the pointer itself is not `const` either. We are
able to change what the pointer is pointing to. That can be another
pointer or a different variable.

```c++
int number2{41};

ptr_number1 = &number2;
std::println("ptr_number1 Address: {}", static_cast<void *>(ptr_number1));
std::println("ptr_number1 Value Pointed To: {}", *ptr_number1);
std::println("number1 Value Stored: {}", number1);
std::println("number1 Address: {}", static_cast<void *>(&number1));
std::println("number2 Value Stored: {}", number2);
std::println("number2 Address: {}", static_cast<void *>(&number2));
```

Resulting in:

```terminaloutput
ptr_number1 Address: 0x4ddbf9f704
ptr_number1 Value Pointed To: 41
number1 Value Stored: 432
number1 Address: 0x4ddbf9f6e4
number2 Value Stored: 41
number2 Address: 0x4ddbf9f704
```

What happened?

- We declared a new variable: `number2`
    - Initialized with `41`
- We reassign `ptr_number1` with the address of `number2`
    - Using the `&` operator
- From here we are simply printing the values & addresses
    - We print the address pointed to by `ptr_number1`
    - Data stored at the pointed address
    - Data stored in `number1`
    - Address of `number1`
    - Data stored in `number2`
    - Address of `number2`

We can see from the printed result:

- The address pointed to by `ptr_number1` changed
    - It is no longer the same as the address of `number1`
    - Plus the value stored does not match the value stored in `number1`
- The address and value match those of `number2`
    - Meaning we were able to modify the pointer

To summarize:

- Non-`const` variable
    - We are able to assign a different value
        - Either directly or using the pointer
- Non-`const` pointer
    - We are able to change what address we are pointing to

In this case, we are looking at situations where we have
a non-`const` variable that has a non-`const` pointer pointing
at the variable's memory address.

```c++
int *ptr_number1(nullptr);
int number1{23};

ptr_number1 = &number1;
fmt::println("ptr_number1 Address: {}", static_cast<void *>(ptr_number1));
fmt::println("ptr_number1 Value Pointed To: {}", *ptr_number1);
fmt::println("number1 Value Stored: {}", number1);
```

In the example above, we are declaring and initializing two elements:

1. A pointer: `ptr_number1`
2. An `int` variable: `number1`

From there we are assigning the address of the variable to the pointer.

```terminaloutput
ptr_number1 Address: 0x7ff7bb839f3c
ptr_number1 Value Pointed To: 23
number1 Value Stored: 23
```

### Non-`const` Pointer to `const` Data

In this example/case we want to see a situation where we are able to modify a pointer
but the variable is `const`

```c++
int *ptr_number1(nullptr);
const int number1{23};
ptr_number1 = &number1;
```

Before we continue, I need to let the reader know that this case
is not possible. If attempted, the compiler will not build the
project. Giving the following output:

```terminaloutput
pointer2.ixx(60): error C2440: '=': cannot convert from 'const int *' to 'int *'
pointer2.ixx(60): note: Conversion loses qualifiers
```

Reason: Allowing this case would permit one to bypass the `const`
restriction and modify a value that was intended to be immutable,
which is unsafe.

> You can read more about
> this [here](https://www.learncpp.com/cpp-tutorial/pointers-and-const/).

### (Semi) `const` Pointer to Non-`const` Data

In this example/case we want to see a situation where we are able to modify a variable
but the pointer is `const`

```c++
int number1{4214};
const int *p_number1{&number1};
```

We then want to quickly print the usual information:

```c++
std::println("p_number1 Value Pointed To: {}", *p_number1);
std::println("p_number1 Address Stored: {}", static_cast<const void *>(p_number1));
std::println("number1 Value Stored: {}", number1);
std::println("number1 Address: {}", static_cast<void *>(&number1));
```

Resulting in:

```terminaloutput
p_number1 Value Pointed To: 4214
p_number1 Address Stored: 0x306e6ff9d4
number1 Value Stored: 4214
number1 Address: 0x306e6ff9d4
```

Now, what if we want to change the value stored in `number1`.

Let us try modifying the value of `number1` through the pointer:

```c++
*p_number1 = 4321;
```

When compiled, the compiler fails. Returning the following in the terminal:

```terminaloutput
pointer2.ixx(77): error C3892: 'p_number1': you cannot assign to a variable that is const
```

Demonstrating that the pointer is not able to modify the data located
at the address being pointed at. Thus, "limiting" the capability of the
pointer.

Let us look at what is being stated by the compiler first.

```terminaloutput
you cannot assign to a variable that is const
```

We never made `number1` a `const` variable. Why is the compiler
stating it is? Because, we are implicitly stating the
variable we are pointing to is a `const` variable. Obviously
there is more to this, but this is a simplified explanation.

What if we modified the variable directly:

```c++
number1 = 14;
```

The program is able to compile. So let us print the usual information:

```c++
p_number1 Value Pointed To: 14
p_number1 Address Stored: 0x306e6ff9d4
number1 Value Stored: 14
number1 Address: 0x306e6ff9d4
```

- Notice the value has changed
- Despite `p_number1` being `const`
    - We were able to modify the variable directly
    - And the address has not changed
        - Which should have not changed regardless (Duh)

Now, what if we try changing what the pointer is pointing to:

```c++
int number2{54};
p_number1 = &number2;
```

Once agin, the compiler was able to build successfully.

```terminaloutput
p_number1 Value Pointed To: 54
p_number1 Address Stored: 0x306e6ff9f4
number1 Value Stored: 14
number1 Address: 0x306e6ff9d4
number2 Value Stored: 54
number2 Address: 0x306e6ff9f4
```

Printing the usual information we can see:

- We were able to change what `p_number1` is pointing to
    - Thus, the address changed and the value
    - Having the same address of the new variable introduced
- We also have to remember:
    - Even though we were able to change what is being pointed to
    - We still cannot modify the data using the pointer

Overall, we need to remember the error output when we attempted to modify the data.
We said the point is making the variable/memory address implicitly `const`. So,
the pointer itself is not `const`. Which is why we are able to modify what is
being pointed to, but not change the data.

That is why, it is better to explicitly add `const` to the variable, when
declared. Given that we do not want to modify the data pointed to, either directly
or indirectly, but still would like to change what the pointer points to. Like below:

```c++
constexpr int protected_number{4214};
const int *p_protected_number{&protected_number};
```

### `const` Pointer to `const` Data

In this example/case we want to see a situation where we are not able to modify
either the variable or the pointer. Once declared & initialized, the variable cannot
change its data and the pointer cannot modify the data. Nor can the pointer be
redirected to point to a new location/variable.

Let us set up an example, where the pointer is `const` and the data is `const`

```c++
const int number1{459};
const int* const p_number1{&number1};
```

What do we notice:

- Like the previous example, we add `const` to the variable `number1`
- Add `const` at the beginning of the declaration for `p_number1`
    - However, this time we add `const` a second time
        - After `int*` declaring the pointer type

Why the second `const`?

The first section of the declaration: `const int*`. Signifies that the
data being pointed to is going to be `const` data. Which we previously
showcased where the data being pointed to was implicitly `const` data.
The second `const` is going to mean that the pointer itself is also
`const`.

Printing the usual data:

```terminaloutput
p_number1 Value Pointed To: 459
p_number1 Address Stored: 0x717cff814
number1 Value Stored: 459
number1 Address: 0x717cff814
```

Now, we need to remember that we cannot modify the data in `number1` directly
or indirectly using `p_number1`. Nor, can we change what `p_number1` is pointing
to. Once declared & initialized, they cannot be changed, as doing so would
result in a compiler error.

As shown below:

```c++
number1 = 41;

...

*p_number1 = 459;

...

p_number1 = &number2;
```

Resulting in the respective compiler errors:

```terminaloutput
error C3892: 'number1': you cannot assign to a variable that is const

...

error C3892: 'p_number1': you cannot assign to a variable that is const

...

error C3892: 'p_number1': you cannot assign to a variable that is const
```

### `const` Pointer & Non-`const` Data

Utilizing everything we have learned up to now, let us attempt a
scenario where we want a `const` pointer (can't change what it points to)
and a non-`const` variable.

```c++
int number1{3145};
int* const p_number1{&number1};
```

What is going on:

- We declared & initialized our variable: `number1`
- We declare & initialize our pointer: `p_number1`
    - Notice where we put the `const` keyword
        - After declaring the pointer type
        - This signifies that the pointer cannot be reassigned
            - With a new address
        - But we are able to change the data at the address it points to

```terminaloutput
p_number1 Value Pointed To: 3145
p_number1 Address Stored: 0x51feaff844
number1 Value Stored: 3145
number1 Address: 0x51feaff844
```

Let us attempt to modify the data which is being pointed to by `p_number1`.

```c++
*p_number1 = 79864;
```

This properly compiles and executes. So let's print the information
again to reconfirm.

```terminaloutput
p_number1 Value Pointed To: 79864
p_number1 Address Stored: 0x51feaff844
number1 Value Stored: 79864
number1 Address: 0x51feaff844
```

Remember, we made the pointer `const`, so we are unable to modify the
location to which `p_number1` is pointing to. If we do, we will receive a
compiler error.

```c++
int number2{1234};
p_number1 = &number2;
```

Results in:

```terminaloutput
error C3892: 'p_number1': you cannot assign to a variable that is const
```

Likewise, we are able to modify the variable directly. We will skip
showing that.

Just a note:

> Despite everything we learned, it is not recommended to implement & modify raw
> pointers. This section is mainly for showcasing potential legacy implementations
> that were done prior to Modern C++ standards.

---

## Relationship Between Pointers & Array's

We will be exploring the realtionship between pointers and arrays (Raw).
We did allude to the relationship previously which is treating the
name of a variable/array as a pointer. This "pointer" points to the first
element of the array.

```c++
int scores[10]{11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
int *p_scores{scores};
```

For example, the array declared & initialized above is given
the name `scores`. The name points to the first element: `11`.
We also set up a seperate pointer `p_scores` which we intitialize
by passing `scores` without the `&` operator. Since, the name of the
array variable is a "pointer".

We can see this relationship when we print the various manors of accessing
the address of the first element and the data stored.

```c++
std::println("Printing the addresses:");
std::println("scores: {}", static_cast<void *>(scores));
std::println("p_scores: {}", static_cast<void *>(p_scores));
std::println("&scores[0]: {}\n", static_cast<void *>(&scores[0]));

std::println("Printing the data:");
std::println("*scores: {}", *scores);
std::println("*p_scores: {}", *p_scores);
std::println("scores[0]: {}", scores[0]);
std::println("p_scores[0]: {}\n", p_scores[0]);
```

Which results in:

```terminaloutput
Printing the addresses:
scores: 0x7ff7b9863200
p_scores: 0x7ff7b9863200
&scores[0]: 0x7ff7b9863200

Printing the data:
*scores: 11
*p_scores: 11
scores[0]: 11
p_scores[0]: 11
```

What is going on:

- When printing the addresses
    - We are utilizing 3 differnt methods to access the address of the first element
        - `scores` could be used by itself to access the address
        - `p_scores` could also be used by itself
            - Given that it has been initialized
        - `&score[0]`
            - We access the first element
            - Then, using the `&` operator, we print its address
    - Each method results in the same address being printed
    - Which showcases the relationship we previously mentioned
- Afterward, we print the data stored at the address
    - `*scores`
        - We are dereferencing the "pointer" to access the data
    - `*p_scores`
        - In this case, we are also dereferencing the pointer
    - `scores[0]`
        - We are directly accesing the data using the `[]` notation
    - `p_scores[0]`
        - Similarly, we are going directly through the pointer
            - Because, the pointer is pointing to the same location

However, there is a clear distinction between a pointer
and a variable name.

You can change a pointer to make it point to a new memory address, but you cannot
change the array variable to point to a different memory address.

```c++
int number1{245};
p_scores = &number1;

// scores = &number1;
```

In the example above, we are declaring and initializing a new variable of type `int`.
Using the existing `p_scores` pointer, we reassign `p_scores` to point to the
memory location of `number1`. Likewise, if we attempt to change the memory location
pointed to by `scores`, we will receive a compiler error.

```terminaloutput
pointer3.ixx:31:16: error: array type 'int[10]' is not assignable
```

There are other differences, for example:

```c++
std::println("size: {}", std::size(p_scores));
```

The `std::size()` facility does not work with raw pointers. Thus, if we tried to compile
the example above, we would receive a compiler error. Resulting in the following to
be printed:

```terminaloutput
: error C2672: 'std::size': no matching overloaded function found
```

This is happening because `p_scores` is a single memory address, being a pointer
to a memory address. `p_scores` does not have the concept of a size. While, an array
variable handles cases where requests of information can occur. That is why `std::size()`
will work when passed `scores`.

There exist more differences, but in most cases you can treat them as similar.

---

## Pointer Arithmetic

We will be discussing pointer arithmetic. This is just a name that encompasses a bunch of
operations that we can do on pointers. We can use pointer arithmetic to navigate arrays.
Get the "distance", which is what one gets if you take a pointer and subtract another pointer
in an array. Giving us the number of elements between the two pointers. We can also compare
pointers.

### Navigation

We can do pointer arithmetic by adding or subtracting from the pointer address.

```c++
int *p_score{scores};
fmt::println("Values in scores array (p_score pointer increment): ");
fmt::println("Address: {}, Value: {}", fmt::ptr(p_score), *p_score);

++p_score; // Moves forward by sizeof(int): 4 bytes
fmt::println("Address: {}, Value: {}", fmt::ptr(p_score), *p_score);

++p_score; // Moves forward by sizeof(int): 4 bytes
fmt::println("Address: {}, Value: {}",fmt::ptr(p_score), *p_score);

++p_score; // Moves forward by sizeof(int): 4 bytes
fmt::println("Address: {}, Value: {}", fmt::ptr(p_score), *p_score);

++p_score; // Moves forward by sizeof(int): 4 bytes
fmt::println("Address: {}, Value: {}", fmt::ptr(p_score), *p_score);

++p_score; // Moves forward by sizeof(int): 4 bytes
fmt::println("Address: {}, Value: {}", fmt::ptr(p_score), *p_score);
```

The example above showcases how we are able to navigate the array using addition
on `p_score`. Each time we add, moving in memory by the size of the element that we are
storing.

Key to remember that we do not go beyond the valid range of addresses in the array.

The example prints the following when run:

```terminaloutput
Address: 0xfa20f1f648, Value: 11
Address: 0xfa20f1f64c, Value: 12
Address: 0xfa20f1f650, Value: 13
Address: 0xfa20f1f654, Value: 14
Address: 0xfa20f1f658, Value: 15
Address: 0xfa20f1f65c, Value: 16
```

Which showcases the behavior of incrementing the memory address by the size of the
element being stored (4 bytes).

It is also possible to add another number on the pointer and move by a bunch of bytes.

#### Explicit Addition

The way this works is simply adding an integer to the pointer.

```c++
p_score = scores; // Reset the pointer to the start of the array.
fmt::println("scores[4]: {}", *(p_score + 4)); // Moves forward by 4 * sizeof(int) = 16 bytes
```

Recall that the pointer had been moved up after the previous element in the array.
So, we have to reset the position of the array: `p_score = scores`.
In the following line, we are dereferencing the element at `p_score + 4`. This is
equivalent to getting the element at index 4.

We can also use loops to print out the elements using the pointer arithmetic.

```c++
p_score = scores;
for (size_t i {0}; i < std::size(scores); ++i) {
    fmt::println("Value: {}", *(p_score + i)); // scores[i]
}
```

Again, we have to reset the position of the pointer `p_score` after we previously
did some operations. From there, we are simply going through a `for` loop.
The only difference being the method of accessing the elements. We use the pointer
arithmetic to access each element.

Also, we can use the same method on the original array.

```c++
for (size_t i{0}; i < std::size(scores); ++i) {
    fmt::println("Value: {}", *(scores + i));
}
```

Why does this work?

If we tried to increment `scores` using the addition increment operator `++`,
we would receive a compiler error.

Why does `scores + i` not result in a compiler error. For the fact that we are
only doing an operation on `scores`, but not trying to store that result. Which
does occur when using the addition increment operator.

Pointer arithmetic also works with decrementing (`--`) when using a pointer.

### Distance

We will be computing the distance using pointer arithmetic. **Only pointers to elements
of the same array (including pointer one past the end of the array) may be subtracted
from each other.**

```c++
int scores[10]{11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

int *pointer0{scores + 0};
int *pointer1{scores + 8};

fmt::println("pointer1 - pointer0: {}", pointer1 - pointer0);
fmt::println("pointer0 - pointer1: {}\n", pointer0 - pointer1);
```

In the example we are:

- Declaring and initializing an array.
- Declaring & initializing two pointers
    - `int* pointer0` is being initialized with
        - `{scores + 0}`
        - Which is equivalent to the square bracket notation:
            - `int* pointer0{&scores[0]);`
            - Remember we have to pass the memory address not the value
    - `int* pointer1` similarly is being initialized with
        - `{scores + 8}`
- We then do the pointer arithmetic to find the distance
    - Between the two pointers in the same array
- `pointer1 - pointer0` returns a value
    - That represents the number of elements between `pointer1` and `pointer0`
    - The value is not represented in number of bytes
        - **It is the size of the elements that is contained in the array**
- `pointer0 - pointer1` returns a value
    - That represents the number of elements between `pointer0` and `pointer1`

#### `std::ptrdiff_t`

We can also use the type `std::ptrdiff_t`. Having a byte size of `8`

This is a signed integer type of the result of subtracting two pointers. Type is
defined in the `<cstddef>` header.

When working with C++ container libraries, `<vector>, <array>, <list>`, etc., the proper
type for the difference between _iterators_ is the member typedef `difference_type`, which
is often synonymous with `std::ptrdiff_t`.

```c++
std::ptrdiff_t pos_diff = pointer1 - pointer0;
std::ptrdiff_t neg_diff = pointer0 - pointer1;
```

The example above is equivalent to our previous distance calculation.
Except **we are storing** the result of subtraction between two pointers:

- `pos_diff` is of type `std::ptrdiff_t`
    - Storing the distance between `pointer1` and `pointer0`
- `neg_diff` is of type `std::ptrdiff_t`
    - Storing the distance between `pointer0` and `pointer1`

### Comparisons

We can also do comparisons between pointers of the same array.

```c++
int scores[10] {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
int *pointer0{&scores[0]};
int *pointer1{&scores[7]};

fmt::println("pointer0: {}", *pointer0);
fmt::println("pointer1: {}\n",*pointer1);

fmt::println("Comparing pointers:");
fmt::println("pointer0 > pointer1: {}", pointer0 > pointer1);
fmt::println("pointer0 < pointer1: {}", pointer0 < pointer1);
fmt::println("pointer0 >= pointer1: {}", pointer0 >= pointer1);
fmt::println("pointer0 <= pointer1: {}", pointer0 <= pointer1);
fmt::println("pointer0 == pointer1: {}", pointer0 == pointer1);
fmt::println("pointer0 != pointer1: {}", pointer0 != pointer1);
```

One thing to remember: We are doing a comparison between two pointers and their pointed
to address, **not the values stored**. Comparison is primarly used to determine the positioning
of elements within the same memory block (Like an array).

So we need to remember 4 aspects:

1. Same Array Guarantee
    - These comparisons are only guaranteed to work safely if both pointers point to elements within the _same_ array or
      block of dynamically allocated memory
2. Pointer Positioning
    - If `pointer0` points to an array index prior to `pointer1`, then `pointer0 < pointer1` evaluates to true
3. Equality
    - Two pointers compare equal if they point to the exact same memory location or if both are `nullptr`'s
4. Undefined Behavior
    - Comparing pointers that point to entirely different arrays, objects, or disconnected memory segments yields *
      *undefined behavior**.
    - It may evaluate to seemingly correct results, but introduces critical portability and safety risks

---

## Dynamic Memory Allocation

In this section, we will be exploring dynamic memory allocation.

> **Important** _You should rarely have to manually allocate memory, like we will be doing in this section.
> Modern C++ highly discourages such practice. One should mostly rely on RAII (Resource Acquisition Is Initialization)
> in modern C++ projects._

So far, we have learned about the heap and stack. To recap, the stack is where local variables will be stored.
Another use is to organize how function calls are carried out. The stack is limited in memory. So one can overuse
the stack and run out of memory. Which causes a program to run into problems.

To avoid this, a good solution/alternative is to use the heap. The heap is going to force one to dynamically ask for
memory. But the responsibility falls on the developer to manage the memory and return it back to the operating
system, once done using it.

This is one of the reasons people fear/avoid pointers and dynamic memory, which is justified by the huge responsibility
one has.

Before we dive into dynamic memory allocation, let us look at things that could go bad.

### Uninitialized Pointers Are Bad

One thing to avoid is declaring a pointer and not initializing it. This will cause problems, because
when you declare the pointer will be containing a junk address. Meaning, that the pointer is
essentially pointing to nothing. Especially bad if utilized unknowningly. If dereferenced it could cause
undefined behavior.

The example below demonstrates this case:

```c++
int *p_number2;
fmt::println("Assigning value 55 to pointer");
*p_number2 = 55;
fmt::println("p_number2: {}", fmt::ptr(p_number2));
fmt::println("Dereferencing bad memory");
fmt::println("*p_number2: {}", *p_number2);
```

This compiles, but when ran:

```terminaloutput
Assigning value 55 to pointer

Process finished with exit code -2147483645
```

The program crashed.

Thus, it is best practice to initialize our pointer when declared. Does not necessarily need to contain an address,
could also be initialized with `nullptr`. Or use braced initialization, since it initialized our pointer with
`nullptr` if left empty.

Something that needs to be stated prior to moving on. Just because we are initializing the pointer with `nullptr`,
does not mean we can dereference the pointer and reassign a literal.

Showcased in the example below:

```c++
int *p_number1{};
fmt::println("Assigning value to nullptr address");
*p_number1 = 5;
fmt::println("p_number1: {}", fmt::ptr(p_number1));
fmt::println("*p_number1: {}", *p_number1);
```

The example above does compile, but when ran the program crashes.
Returning the following:

```terminaloutput
Assigning value to nullptr address

Process finished with exit code -1073741819 (0xC0000005)
```

Something to remember.

### Dynamic Memory

Now let us dive into dynamic memory. As previously stated, if we want to use the heap,
we have to explicitly ask for the memory.

To do this we use the keyword `new`.

Let us look at an example:

```c++
int *p_number{nullptr};

p_number = new int;

*p_number = 7741;
fmt::println("Dynamically allocating memory:");
fmt::println("*p_number: {}", *p_number);

delete p_number;
p_number = nullptr;
```

Let us breakdown the example:

- We first declare & init a pointer: `p_numebr`
- We then ask for a piece of memory from the heap
    - Using the syntax: `p_number = new int`
    - Thus, the pointer will be pointing to a memory address
        - That will be designated to hold the data type we desire
        - Which is why we added `int` after `new`
    - In summary, the pointer is a "door" to using the memory we receive from the heap
- Now, using the address we received, we can store a literal
    - Which we do by dereferencing the pointer and assigning the value
    - Just like previously done
- We print the value stored by the pointer to confirm
- The next line is **very important**
    - Recall that we briefly stated that when we dynamically allocate memory
    - We need to return the memory back to the OS (Operating System).
        - We accomplish this by using the keyword: `delete`
        - Followed by the pointer that holds the allocated memory we desire to return
- We lastly, reset the pointer to `nullptr` to indicate that we are not using the pointer anymore

### Other Methods of Initialization for Dynamic Memory

```c++
int *ptr_number1 {new int};
int *ptr_number2 {new int(22)};
int *ptr_number3 {new int {23}};

fmt::println("ptr_number1: {}", fmt::ptr(ptr_number1));
fmt::println("*ptr_number1: {}\n", *ptr_number1);

fmt::println("ptr_number2: {}", fmt::ptr(ptr_number2));
fmt::println("*ptr_number2: {}\n", *ptr_number2);

fmt::println("ptr_number3: {}", fmt::ptr(ptr_number3));
fmt::println("*ptr_number3: {}\n", *ptr_number3);

delete ptr_number1;
ptr_number1 = nullptr;

delete ptr_number2;
ptr_number2 = nullptr;

delete ptr_number3;
ptr_number3 = nullptr;
```

- The first method simply combines our previous implementation into one line
    - We insert `new int` inside our curly braced initialization
    - Rather than initializing the pointer with `nullptr`
    - _Just remember that the pointer will be pointing to a memory location with junk data_
- The second method uses direct initialization
- With the third method utilizing uniform initialization
    - The main difference between the two is:
        - The syntax
        - How type safety is handled
        - Constructor matching
    - Direct initialization uses parentheses `()`
        - To explicitly call a matching constructor.
    - Uniform initialization uses curly braces `{}`
        - To provide a single, consistent syntax
- We then just print the memory addresses along with each respective data stored
- Lastly, we release the data back to the OS.

Running the program returns the following in the terminal

```terminaloutput
ptr_number1: 0x18e4e0689a0
*ptr_number1: -842150451

ptr_number2: 0x18e4e068320
*ptr_number2: 22

ptr_number3: 0x18e4e068b20
*ptr_number3: 23
```

### Reusing Pointers

A quick note that we can continuously use a pointer that was released.
As long as we remember to release the memory back to the OS.

```c++
ptr_number1 = new int{41};

fmt::println("ptr_number1: {}", fmt::ptr(ptr_number1));
fmt::println("*ptr_number1: {}\n", *ptr_number1);

delete ptr_number1;
ptr_number1 = nullptr;
```

```terminaloutput
ptr_number1: 0x18e4e068b20
*ptr_number1: 41
```

### Properly Pair `new` and `delete`

One major thing to remeber is to match up the `new` operator
with a `delete` operator. That means, we need to remeber to have a `delete`
for every `new` stated, but also not having too many `delete` operators for one individual
`new`.

```c++
ptr_number = new int {42134};

fmt::println("ptr_number1: {}", fmt::ptr(ptr_number1));
fmt::println("*ptr_number1: {}\n", *ptr_number1);

delete ptr_number1;
delete ptr_number1;
ptr_number1 = nullptr;
```

When we call too many `delete` operators, we are introducing a disastrous behavior that
will lead to undefined behavior. Typically resulting in our program crashing or memory corruption.
This happens because we are attempting to free memory that the uninitialized pointer does not own.
Corrupting the heap.

Running the example above results in the following terminal output:

```terminaloutput
ptr_number1: 0x1ba08c98860
*ptr_number1: 42134


Process finished with exit code -2147483645
```

Which was printed after the program crashed. This is why Modern C++ does not recommend
working with raw pointers and manual memory management.

---

## Dangling Pointers

Let us discuss various ways one could mishandle a pointer using dynamic memory allocation. We will title this
section dangling pointers. With dangling pointers being a pointer that is really not pointing to anything valid.
Summarized, we will focus on three cases: Uninitialized pointers, Deleted Pointers, & Multiple pointers pointing
to one address.

Afterward, we will look at solutions to prevent these potential (dangerous) bugs from occurring.

### Case 1: Dangling Uninitialized Pointer

This case covers the situation where we obtain dynamic memory, but do not initialize any data at the memory location.
Doing so, results in the memory address storing garbage. So, if we tried to dereference the pointer, undefined
behavior would occur. Causing subtle, hard-to-find logic bugs and security vulnerabilities.

#### Solution for Uninitialized Pointer

We could do two things. The first is avoiding the use of raw pointers. Instead, using smart pointers (have not been
covered) rather than raw pointers. Smart pointers handle memory allocation automatically to prevent such situations.

The other option is to initialize our pointer with `nullptr`. In the situation where we want to declare our pointer,
but are not ready to initialize it with certain data. Initializing the pointer with `nullptr` explicitly tells the
compiler/program that the pointer is empty. Thus, we can more explicitly check the status of our pointer.

There is another reason, but that will be explored more in the next solution section.

### Case 2: Using a Deleted Pointer

As previously seen, after using a pointer that was had dynamically allocated memory, we needed to release the memory
the OS allocated. So, we properly released the memory. Later on, we tried to reuse the pointer, forgetting we released
the memory. This action triggers undefined behavior.

When we use the `delete` operator on a pointer, we are telling the OS that we will no longer use the allocated memory
address, but the pointer continues to point to the now-invalid memory address.

That is why we need to avoid using previously deleted pointers. Also, depending on the compiler or even configurations
set for the compiler, could sometimes result in the program compiling. An even worse situation. When the compiler
fails, we know something went wrong. However, in cases where the program successfully compiles, we are ignorant to the
undefined behavior of the dangling pointer.

#### Solution for Using a Deleted Pointer

Again the best solution is to simply use smart pointers that handle the memory for you. But another solution would be
simply reassigning the pointer after using the `delete` operator.

When we reassign the pointer, we set it to `nullptr`. And, as previously stated, we can check the pointer to see if
there exists a valid memory address/data.

### Case 3: Multiple Pointers Pointing to the Same Address

This case covers a situation where we have more than one pointer, pointing to the same memory address. This would be
best showcased in an example, so let us look at one:

```c++
int *p_number{new int{41}};
int *p_number1{p_number};
int *p_number2{p_number};
int *p_number3{p_number};

fmt::println("p_number: {} contains {}", fmt::ptr(p_number), *p_number);
fmt::println("p_number1: {} contains {}", fmt::ptr(p_number1), *p_number1);
fmt::println("p_number2: {} contains {}", fmt::ptr(p_number2), *p_number2);
fmt::println("p_number3: {} contains {}", fmt::ptr(p_number3), *p_number3);

fmt::println("Release the memory address for p_number3:\n");
delete p_number3;

fmt::println("p_number1: {} contains {}", fmt::ptr(p_number1), *p_number1);
fmt::println("p_number2: {} contains {}", fmt::ptr(p_number2), *p_number2);
fmt::println("p_number3: {} contains {}", fmt::ptr(p_number3), *p_number3);
```

In the example above:

- We declare & initialize 4 pointers
    - 1: `p_number` is initialized with dynamically allocated memory
    - 2-4: are pointing to the allocated memory of `p_number`
- We then print the respective address & value being pointed to
- Use the `delete` operator to release the memory address for `p_number`
- Then we print the respective address & value being pointed to

Which results in the following:

```terminaloutput
p_number: 0x16fb0158820 contains 41
p_number1: 0x16fb0158820 contains 41
p_number2: 0x16fb0158820 contains 41
p_number3: 0x16fb0158820 contains 41

Release the memory address for p_number3:

p_number1: 0x16fb0158820 contains -572662307
p_number2: 0x16fb0158820 contains -572662307

Process finished with exit code -1073741819 (0xC0000005)
```

This showcases the biggest problem with multiple pointers pointing to the same memory address.

When we release the allocated memory for one pointer, all other pointers with the same address become
dangling pointers. This is especially dangerous if we try to use them. Even if we reassign `p_number`,
that does not apply to the remaining pointers. They still point to the now-invalid memory address. So when
we use them, we see their undefined behavior.

Or we could accidentally use one of the other pointers to manipulate the data or release the allocated memory.
Rendering all other pointers useless.

#### Solution for Multiple Pointers Pointing to the Same Address

The best solution for this case is, once again, to use smart pointers.

The other solution is to have one pointer be the sole owner of the memory. Make all other pointers be
observing entities, thus "borrow" the address by using non-owning pointers or references.

The rule-of-thumb is: The observing raw pointers must strictly have a shorter lifetime that the owner.
They must never call `delete` on the shared memory address.

So we make the other pointers "read-only". So we declare them as follows:

```c++
int* p_number {new int{5412}};
const int* p_number1{p_number};
```

---

## When `new` fails

Let us explore a situation where `new` could fail.

Why would that happen?

Memory is not unlimited, whether we are talking about the stack or heap.
In this case, we are focusing on the heap, with dynamically allocated memory existing here.
Even though the heap has more memory available than the stack, the quantity is still limited.

Thus, if we ask for more memory than a system has, `new` will fail. Which will crash the program.

Let us look at an example that could possibly break.

```c++
int* data = new int[100000000000000];
```

If we try to compile the example above, it will not succeed. When we debug the program,
we can see that an exception is thrown. An exception is something that happens if you do something
wrong in C++.

In this case, we tried to allocate for more memory than our system can provide.

There are a few things we can do to mitigate this problem.

### Use `exception`

```c++
for (size_t i {0}; i < 100; i++)
{
    try
    {
        int* data = new int[];
    }
    catch (std::exception& ex)
    {
        fmt::println("Something went wrong: {}", ex.what());
    }
}
```

The example showcases the use of `exception` in a `try-catch` statement. We will delve deeper on what
`excepetion` and `try-catch` statements are, but for now we will give a brief overview. They are a way to
force the program not to crash and to inform the developer as to why something went wrong.

Again this is not a fix, but a method of preventing the program from crashing. Since a program
crashing is undesirable, thus we want to avoid such situations.

The `try-catch` block is going to be a block of code where we write potentially problematic code
or code that could cause problems in. In `try` we write the code we want to run, `catch` is going to
inform us what went wrong.

We also need to rememeber that we need to include the `<exception>` library to utilize `std::exception`.

Now when we run the example, the following is outputted:

```terminaloutput
...
iteration: 345
iteration: 346
iteration: 347
iteration: 348
iteration: 349
Something went wrong: std::bad_alloc

Process finished with exit code 0
```

I did not include the whole output, but wanted to showcase that the program did not crash. Rather than crashing like in
the previous example, the program simply threw the exception and finished properly. As indicated by the `exit code 0`.

### Use `std::nothrow`

In situations where we do not want to throw an exception, preferring to receive a `nullptr`, we use the
`std::nothrow` option when allocating for memory.

```c++
for (size_t i{0}; i < 1000; ++i)
{
    int* data = new (std::nothrow) int[10000000];
    if (data != nullptr)
    {
        fmt::println("Data Allocated");
    } else
    {
        fmt::println("Data Allocation Failed");
    }
}
```

The example above does not use the exception mechanism. Rather, we will receive a `nullptr` in the case
where memory allocation fails. Which is why we are checking to see if `data` is a `nullptr`.

To utilize `std::nothrow` we have to include the header `<new>`.

`std::nothrow_t` is an empty class type used to disambiguate the overloads of throwing and non-throwing allocation
functions.
`std::nothrow` is a constant of it.

Running the example returns a similar output to the following (output is system dependent):

```terminaloutput
Data Allocated
Data Allocated
Data Allocation Failed
Data Allocation Failed
Data Allocation Failed
Data Allocation Failed
Data Allocation Failed
Data Allocation Failed
Data Allocation Failed
Data Allocation Failed

Process finished with exit code 0
```

---

## Tips for Pointers

These are a few tips that one can use to make one's life with memory management in C++ easier.

### `NULL` Pointer Safety

The first tip regards `nullptr` safety.

One thing people think is that deleting a `nullptr` is going to cause a crash.
Which leads to some checking for `nullptr`'s. Like in the example below:

```c++
int* p_number1{};

if (p_number1 != nullptr)
{
    delete p_number1;
}
```

Which is just unnecessary and verbose. Since using the `delete` operator on a `nullptr` would not cause any
problems. The compiler will simply ignore the call. But, needs to be stated, this works if the pointer
being used is initialized

### Memory Leaks

A leak in regard to memory, is memory that one does not have access to. Yet, the Operating System has
already allocated the memory location for the program.

#### One Does Not Release Allocated Memory

Let us look at an example:

```c++
// Non deleted memory
int* p_number{new int{56}};

// Should delete & reset (Assign nullptr) here

int number{55}; // stack variable

p_number = &number;
```

Suppose we:

- Declared & initialized some dynamically allocated memory: `p_number`
- We do whatever operations on the pointer
- Then, ideally, we `delete` and reassign `p_number`
    - So indicate we will no longer need the allocated memory
- But we forget to deallocated the memory
- We reassign `p_number` with a new address
    - In this case, an int variable `number`
- What is the problem?
    - When we reassigned `p_number` we lost access to heap memory that we allocated
    - Without releasing this memory
        - So the OS believes the allocated memory is ours
        - But we do not have access to the memory anymore
        - Thus, unable to release the memory back to the OS, even if we wanted to
- If one does this repeatedly
    - The program will consume lots of heap memory
    - Eventually, the OS is going to reach a limit
    - Killing the program as a result
- This is something we really want to avoid

So we need to remember that: _**Do not assign a pointer to a new location, if you have not released the memory yet.**_

There is another case in which memory leaks could occur.

#### Double Memory Allocation

The other situation in where memory leaks occur, is when we double allocate memory for a single pointer.

```c++
// Double allocation
int* p_number1{new int{412}};

// Use the pointer

// Should delete & reset here

p_number1 = new int{524}; // Previous memory leaked

delete p_number1;
p_number1 = nullptr;
```

- We are declaring & intializing a pointer with dynamically allocated memory: `p_number1`
- Do operations on the pointer
- Forget to `delete` the current memory allocated to the program
- Proceed to allocate new memory to the pointer
    - Thus break the connection between the program and the allocated memory
    - With the same problems arising as the previous situation
- If we repeatedly do this, the program will eventually be killed by the OS.

#### Nested Scope with Dynamically Allocated Memory

```c++
{
    int *p_number2{new int{42}};
    
    // Use pointer
    
    // Should delete & reset here
}
```

There are situations where one may use dynamically allocated memory in a `for` loop, `while` loop, a function
or other code block that has its own local scope. In these situations, we would allocate memory to use. Do some
operations on the pointer. Then continue with our program. Forgetting to `delete` the pointer and release the memory
back to the OS. Thus, once out of this local scope, we lose access to this pointer variable. Since we do not have access
to the memory.
**_In general, a memory leak occurs when one loses access to the pointer necessary to manage the memory on the heap_**.

## Dynamic Arrays

Lets us look at dynamically allocated raw arrays.

These are arrays that are allocated on the heap opposed to the stack. With the key differentiator being the operator
`new`. We can also use the `std::nothrow` version of `new` if we do not want exceptions.

```c++
double *p_salaries{new double[10]}; // Initialized with garbage data
int *p_students{new(std::nothrow) int[10]{}}; // All values init to 0
double *p_scores{new(std::nothrow) double[10]{1, 2, 3, 4, 5} }; // First 5 elements are manually init
// Remaining elements contain 0's


// nullptr check an use the allocated array
if (p_scores) {
    // Print, can use array access notation or pointer arithmetic
    for (size_t i{0}; i < 10; ++i) {
        std::println("index {}: {}", i, *(p_scores + i));
    }
}

delete []p_salaries;
p_salaries = nullptr;

delete []p_students;
p_students = nullptr;

delete []p_scores;
p_scores = nullptr;
```

In the example above, we are:

- declaring 3 different dynamic arrays
    - `p_salaries` is a dynamically allocated array with no element initialized
        - Meaning it holds garbage data
    - `p_students` and `p_scores` are both initialized
        - `p_students` holds a `0` at every element location
        - `p_scores` is manually initialized for the first 5 elements
            - Thereafter, the remaining elements hold `0`'s
        - This is due to braced initialization
- We use `p_scores`
    - Check to see that `p_scores` is not a `nullptr` before doing operations
    - Print each element in `p_scores`
        - We can use both array access notation or pointer arithmetic notation
- Once done with the dynamic array's, we need to release the memory
- We do this like other examples, except we include a new syntax
    - Add `[]` (square brackets) after `delete` to indicate that the allocated memory is an array of memory
    - Not just one single memory location.
- Then reassign all the cleared pointers to `nullptr`
    - As is best practice

### Dynamic v.s. Static Array's

Another thing to consider is the comparison between static arrays and dynamic arrays.

A static array is an array that is allocated for on the stack.

A dynamic array is an array that is allocated for on the heap.

```c++
int scores[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Stack Allocated

fmt::println("scores size: {}", std::size(scores));

for (const auto& s : scores) {
    fmt::println("value: {}", s);
}

int *p_scores {new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10} }; // Heap Allocated
```

- The first array is allocated for the stack
    - Since it does not go through the `new` operator
- We can use facilities like:
    - `std::size()` which returns the size of the container
        - Since static arrays have size information embedded into the name of the array
    - Range-based `for` loops
        - Since a range-based `for` loop will know how long to iterate
- We cannot use the previous facilities for dynamic arrays
    - Because, once the allocation is made
        - The array is essentially a pointer pointing to the first element in the array
        - Which does not have any size information embedded
- We can still use regualr `for` loops for dynamic arrays

---

## Smart Pointers

In this section, the focus will be on the concept of smart pointers. Smart pointers are a facility that was introduced
in C++11. Mainly to address memory leak issues and mitigate the difficulty of managing memory, similar to our previous
examples.

The ideal way to work with C++ objects is making them work/behave as a stack variable. With a stack variable being
managed automatically.

Smart pointers are thus, something that was introduced to deliver a similar behavior to dynamic memory.

> In Modern C++, you should use smart pointers as much as possible for memory management needs.
> Memory will be automatically released when the object goes out of scope. It is natural! Just like stack objects.

Let us first look at `std::unique_ptr`.

### `std::unique_ptr`

This is a smart pointer that is provided by Modern C++. One of the key points about this pointer is its
restriction that only one pointer can point to a memory location. If other pointers try to point to the memory location
the compiler will throw an error.

To use, we need to include the library `<memory>`.

Let's look at an example:

```c++
int* ptr_int{new int{30}};
std::unique_ptr<int> unique_int{ptr_int};

std::unique_ptr<int> unique_int1{new int{50}};
std::unique_ptr<int> unique_int2{nullptr};

fmt::println("Integer is: {}", *unique_int1);
fmt::println("Integer located at address: {}", fmt::ptr(unique_int1.get()));
```

A `unique_ptr` can also manage a previously allocated space managed by a raw pointer.
Evident in the first two lines of our example. Remember, one should not try to use the raw pointer from this point on.

We can directly initialize the `unique_ptr` with allocated memory.
And initialize the pointer to `nullptr`. Choosing to give the pointer memory later on. We will be able to do so
later on, utilizing `std::move`. For now, best to acknowledge that initializing the pointer with `nullptr` is possible.

Just like raw pointers, we can utilize the `unique_ptr`. We are able to dereference the pointer to access the data
stored.

We are also have the option to call the `get()` method/function on the unique pointer, in order to access the address
where the data is stored.

#### C++14 Updates

C++14 introduced a new facility. Which prevents us from using the `new` operator manually.

```c++
std::unique_ptr<int> unique_int2 {std::make_unique<int>(79)};
fmt::println("Value is: {}", *unique_int2);
fmt::println("Value located at address: {}\n", fmt::ptr(unique_int2.get()));
```

- We rewrote the initialization for `unique_int2`
    - Rather initializing the value with `nullptr`
    - We intialize it in the following manner
        - `std::make_unique<int>(79);`
        - We are calling `std::make_unique` instead of `new`
        - Specify the data type: `int`
        - Along with the value we want stored: `79`
- Outside of that, everything we have done still applies

#### Cannot Make Copies with `unique_ptr`

We briefly mentioned this, but idea with `unique_ptr` is that we only have one pointer pointing to our memory location.
Not allowing for more than one pointer pointing to the memory location. Hence, the name unique.

```c++
std::unique_ptr<int> unique_int2 = std::make_unique<int>(80);

// Copy's & Assignment
std::unique_ptr<int> assign_unique_ptr = unique_int2;
std::unique_ptr<int> copy_unique_ptr{unique_int2};
```

- We have a `unique_ptr` declare & intialized
- If we try to assign `unique_int2` to `assign_unique_ptr`
    - We will have an error
        - The operation does some kind of copy
        - We will learn more on this when discussing operator overloading
- If we try to copy `unique_int2` to `copy_unique_ptr`
    - The compiler will throw an error
        - Since we cannot have more than one unique pointer pointing to the same memory location.

However, we are able to move a pointer.

#### Moving a `unique_ptr`

We have a memory location and a unique pointer pointing to this location. With this situation, the `unique_ptr` is
managing the memory. In cases, where we do not want said pointer to manage the memory, we can give the responsibility
to another `unique_ptr`.

Essentially, we are moving memory management responsibility from one `unique_ptr` to another.

Let us look at an example:

```c++
std::unique_ptr<int> unique_int3 = std::make_unique<int>(110);
fmt::println("unique_int3 points at address : {}\n", fmt::ptr(unique_int3.get()));

{
    std::unique_ptr<int> unique_int4 = std::move(unique_int3);
    fmt::println("unique_int4 points at address :{}", fmt::ptr(unique_int4.get()));
    fmt::println("unique_int3 points to nullptr : {}", fmt::ptr(unique_int3.get()));

    if (unique_int3) {
        fmt::println("unique_int3 is pointing to something valid");
    } else {
        fmt::println("unique_int3 is pointing to nullptr");
    }
}
fmt::println("Outside scope\n");
```

Resulting in the output:

```terminaloutput
unique_int3 points at address : 0x161cc7e8c60

unique_int4 points at address: 0x161cc7e8c60
unique_int3 points to nullptr: 0x0
unique_int3 is pointing to nullptr
Outside the scope
```

- `unique_int3` will be managing the memory location holding `110`
    - This is the only unique pointer allowed to manage this memory
- Following line, we move the management responsibilities to a new `unique_ptr`
    - `unique_int4` now manages the memory location
    - Thereafter, `unique_int3` will be invalidated
        - Unable to manage the memory location
- We print the addresses of the `unique_ptr`'s to confirm the transfer
    - `unique_int3` prints `0x0` as its address which is synonymous to a `nullptr`
    - Further confirmed with our `if` statement

#### Resetting `unique_ptr`

One last thing we can do is reset a `unique_ptr`. Meaning, one can force the pointer to reset itself to `nullptr`.
When reset, the pointer releases the memory it was allocated and points to `nullptr` thereafter.

Example below:

```c++
std::unique_ptr<int> unique_int5 = std::make_unique<int>(140);
unique_int5.reset();

if (unique_int5) {
    fmt::println("unique_int5 points to a valid address: {}", fmt::ptr(unique_int5.get()));
} else {
    fmt::println("unique_int5 points to nullptr: {}", fmt::ptr(unique_int5.get()));
}
```

The only important part of the example is the second line. Calling `reset()` releases the memory and
point to `nullptr`. Which we confirm in our `if` statement.

#### `unique_ptr` As Function Parameters & Return Values

We will be exploring things to know when using `unique_ptr`. Specifically, using them as parameters and return values.

Let us look at an example first:

```c++
void do_something_with_int_unique(std::unique_ptr<int> unique_int_ptr) {
    fmt::println("Square of {} is {}\n", unique_int_ptr, std::pow(*unique_int_ptr, 2));
}

int main() {
    std::unique_ptr<int> ptr_u = std::make_unique<int>(4113);
    
    //do_something_with_int_unique(ptr_u);
    
    do_something_with_int_unique(std::move(ptr_u));
    
    do_something_with_int_unique(std::make_unique<int>(142));

    return 0;
}
```

We first set up our function:

- This function will be of type: `void`
    - So nothing is will be returned
    - We name our function: `do_something_with_int_unique`
- In the function parameters
    - We are taking a `unique_ptr` which we refer to the name `unique_int_ptr`
- In the `main` function
    - We make a new `unique_ptr` labeled `ptr_u`
        - Initialized with the value `41131
- Then we call the function while passing `ptr_u`
    - **However, we need to remember the main utility of a** `unique_ptr`
        - We cannot have multiple pointers pointing to the same memory location
    - With the function taking the parameter by value
        - When we pass `ptr_u`, we are creating a copy of the pointer
        - Thus, the program will crash
            - Since the pointer is being copied, rather than passed
            - Meaning there are multiple pointers pointing to the same memory
- We fix this in the next function call
    - We move the memory address from `ptr_u` to `unique_int_ptr`
        - Utilizing `std::move()` to accomplish this process
    - But this method also has a drawback
        - With the ownership over the memory moving
        - When the function returns the memory we passed will be released back to the OS
        - Which is something we typically do not want
- The following function call
    - In this call we are doing an implicit move
    - Since we are passing a new unique pointer
        - Creating a temporary object on the heap

We can aliviate this problem by passing the parameter by reference. This is a topic we will cover more in depth. But for
now we will just present the example.

```c++
void do_something_with_int_unique_2(const std::unique_ptr<int>& unique_int_ptr) {
    // unique_int_ptr.reset();
    fmt::println("Square of {} is {}\n", unique_int_ptr, std::pow(*unique_int_ptr, 2));
}
```

We will only change the function parameter, everything else is the same in our function.

- We add a `const` to indicate we do not want to alter the pointer object
    - So we can access & change the data being stored
    - However, if we try to manipulate the pointer object itself
        - The compiler will crash
        - Which we can try out by uncommenting `unique_int_ptr.reset()`
    - If we wanted to ensure that the data being pointed cannot be changed
    - we would update `std::unique_ptr<int>` to `std::unique_ptr<const int>`
- We indicate we want to reference the pointer by using `&` (ampersand)
    - Which is essentially passing the memory address of the `unique_ptr`
    - **NOT**, the memory address the `unique_ptr` is pointing to
    - So, `do_something_with_int_unique(ptr_u)` will work and compile, if uncommented

The next thing we could attempt is returning a `unique_ptr` by value. Let us look at an example:

```c++
std::unique_ptr<int> get_unique_ptr() {
    fmt::println("Inside function get_unique_ptr()");
    std::unique_ptr<int> ptr_u1 = std::make_unique<int>(142);
    fmt::println("unique_ptr address(in): {}", fmt::ptr(&ptr_u1));
    fmt::println("unique_ptr address(value): {}\n", fmt::ptr(ptr_u1.get()));
    return ptr_u1;
}

int main() {
    std::unique_ptr<int> ptr_u2 = get_unique_ptr();
    fmt::println("Outside function get_unique_ptr:");
    fmt::println("unique_ptr address(in): {}", fmt::ptr(&ptr_u2));
    fmt::println("unique_ptr address(value): {}", fmt::ptr(ptr_u2.get()));

    return 0;
}
```

- The function is of type: `std::unique_ptr<int>`
    - Meaning it will return a `unique_ptr`
    - That points to a memory address for an integer
- In the function
    - Create a new `unique_ptr` that points to an integer memory address: `ptr_u`
    - Print the address of the `ptr_u`
    - Print the address pointed to by `ptr_u`
    - Return the `unique_ptr`
        - One may think that the code would not work
            - Considering our function failed when we tried to pass a pointer by value
            - i.e., make a copy of the pointer
        - However, modern compilers are capable of making this viable
        - The compiler is returning a reference to the pointer and making it work
            - Still, this is not guaranteed across the various compilers
            - Each compiler treats such cases in their own way

The example prints the following:

```terminaloutput
Inside function get_unique_ptr()
unique_ptr address(in): 0xe3ac8ff768
unique_ptr address(value): 0x23a94a08ba0

Outside function get_unique_ptr:
unique_ptr address(in): 0xe3ac8ff768
unique_ptr address(value): 0x23a94a08ba0
```

A behavior that we can also see is showcased in the following example, using the same function:

```c++
int main() {
    fmt::println("Temporary Object Creation");
    fmt::println("unique_ptr address(value): {}", fmt::ptr(get_unique_ptr().get()));
}
```

- In this example,
    - We are calling the function independently
    - Appended is the `get()` function/method
        - Which returns the address of the `unique_ptr`
    - Then print the address
- Afterward, the `unique_ptr` that was returned by the function is destructed
    - Making it a temporary object/pointer
    - Since the pointers job is done & not being saved

This prints:

```terminaloutput
Temporary Object Creation
Inside function get_unique_ptr()
unique_ptr address(in): 0xc463eff890
unique_ptr address(value): 0x20c8f8581a0

unique_ptr address(value): 0x20c8f8581a0
```

#### `unique_ptr` and Array's

It is possible to manage arrays through `unique_ptr`'s. The syntax to do so is slightly confusing.
Let us look at an example:

```c++
int main() {
    auto arr_ptr = std::unique_ptr<int[]>(new int[4]{1, 2, 3, 4});
    
    for (size_t i{0}; i < 4; i++) {
       fmt::println("{} ", arr_ptr[i]); 
    }
    
    return 0;
}
```

- Let us break it down
    - We are utilizing `auto` to help simplify the declaration
    - Specify in the `unique_ptr` initialization
        - That the pointer will be pointing to an array of integers: `int[]`
    - Within the `()` (parentheses) we call the `new` operator
        - Then set up an array on the heap
    - Then print the values

Which prints:

```terminaloutput
1
2
3
4


Process finished with exit code 0
```

A successful output.

We can also utilize `make_unique` to do the same process. Rewriting the previous example results in:

```c++
int main() {
    auto arr_ptr = std::make_unique<int[]>(4);
    
    for (size_t i{0}; i < 4; i++) {
       fmt::println("{} ", arr_ptr[i]); 
    }
    
    return 0;
}
```

- Let us break it down
    - We are utilizing `auto` to help simplify the declaration
    - Specify in the `make_unique` initialization
        - Will be pointing to an array of integers: `int[]`
    - Within the `()` (parentheses) we indicate the size of the array: `4`
        - **However, in doing this we cannot initialize the individual elements**
    - Then print the values

As stated, we cannot initialize the elements using `std::make_unique`. Thus, the following examples will result in
compiler errors.

```c++
int main() {
    auto arr_ptr = std::make_unique<int[]>(4) {1, 2, 3, 4};
    auto arr_ptr2 = std::make_unique<int[]> {1, 2, 3, 4};
    
    for (size_t i{0}; i < 4; i++) {
       fmt::println("{} ", arr_ptr[i]); 
    }
    
    return 0;
}
```

---

### `std::shared_ptr`

We will be exploring a new type of smart pointer: `shared_ptr`. `shared_ptr` has the same foundational concept as unique
pointers. Which is managing memory automatically, in order to prevent memory errors caused by human error.

But `shared_ptr` removes the limitation of `unique_ptr`'s. Where only one `unique_ptr` could manage/point to a memory
address. With `shared_ptr`'s we can have more than one pointer pointing to the same memory address.

C++ manages this by having a reference count that increments every time we have a new pointer. If a pointer goes out of
scope, the reference count decrements. If the reference count reaches `0`, that means we do not have any pointers
pointing to a particular memory address. Only then will the memory will be released back. This could also occur, if all
pointers go out-of-scope.

The syntax for `shared_ptr`'s are very similar to `unique_ptr`. So let us look at an example:

```c++
std::shared_ptr<int> shared_int_ptr_1 {new int{30}};

fmt::println("The pointed to value is: {}", *shared_int_ptr_1);
*shared_int_ptr_1 = 40;
fmt::println("The pointed to value is: {}", *shared_int_ptr_1);
fmt::println("Use count = {}", shared_int_ptr_1.use_count());
```

Resulting in the output:

```terminaloutput
The pointed to value is: 30
The pointed to value is: 40
Use count = 1
```

- In the code example
    - We are declaring a shared_ptr: `shared_int_ptr_1`
        - Initializing a new memory address to store `int` data: `30`
    - We print the value initialized
    - Then reassign the value to `40`
    - Printing the new value
    - Lastly, we print the number of pointers pointing to the memory address we allocated
        - Which should be `1`
        - Since only `shared_int_ptr_1` is pointing to the allocated memory

The real major difference for this smart pointer, as previously mentioned, is that we can create copies.

#### Copy `shared_ptr`'s

```c++
std::shared_ptr<int> shared_int_ptr_2 = shared_int_ptr_1;

fmt::println("shared_int_ptr_2 value: {}", *shared_int_ptr_2);
*shared_int_ptr_2 = 548;
fmt::println("shared_int_ptr_2 value: {}", *shared_int_ptr_2);
fmt::println("use count for shared_int_ptr_1: {}", shared_int_ptr_1.use_count());
fmt::println("use count for shared_int_ptr_2: {}", shared_int_ptr_2.use_count());
```

```terminaloutput
shared_int_ptr_2 value: 40
shared_int_ptr_2 value: 548
use count for shared_int_ptr_1: 2
use count for shared_int_ptr_2: 2
```

- The main focus for this example
    - Is the increased count for `use_count()`
    - Indicating that there are two pointers pointing to the same memory address

#### Other Methods for Declaration & Initialization

We can also use various methods for declaring & initializing a `shared_ptr`:

```c++
std::shared_ptr<int> shared_int_ptr_3;
shared_int_ptr_3 = shared_int_ptr_1;

std::shared_ptr<int> shared_int_ptr_4{nullptr};
shared_int_ptr_4 = shared_int_ptr_1;

std::shared_ptr<int> shared_int_ptr_5{shared_int_ptr_1};

fmt::println("shared_int_ptr_5 value: {}", *shared_int_ptr_5);
*shared_int_ptr_5 = 314;
fmt::println("shared_int_ptr_5 value: {}", *shared_int_ptr_5);
fmt::println("use count for shared_int_ptr_1: {}", shared_int_ptr_1.use_count());
fmt::println("use count for shared_int_ptr_5: {}\n", shared_int_ptr_5.use_count());
```

```terminaloutput
shared_int_ptr_5 value: 548
shared_int_ptr_5 value: 314
use count for shared_int_ptr_1: 5
use count for shared_int_ptr_5: 5
```

#### Using `shared_ptr` to Manage Existing Memory

We can also manage a piece of memory that existed. Let us look at an example:

```c++
int *raw_int_ptr{new int{33}};

std::shared_ptr<int> shared_int_ptr_6{raw_int_ptr};
raw_int_ptr = nullptr;
fmt::println("Value pointed to by raw_int_ptr is(using shared_ptr): {}", *shared_int_ptr_6);
fmt::println("Use count for shared_int_ptr_6 is: {}", shared_int_ptr_6.use_count());
fmt::println("raw pointer: {}", fmt::ptr(raw_int_ptr));
fmt::println("shared_int_ptr_6.get(): {}", fmt::ptr(shared_int_ptr_6.get()));
```

```terminaloutput
Value pointed to by raw_int_ptr is(using shared_ptr): 33
Use count for shared_int_ptr_6 is: 1
raw pointer: 0x0
shared_int_ptr_6.get(): 0x7a8914004bf0
```

- We declare a raw pointer: `raw_int_ptr`
    - Dynamically Initialize the pointer
- Declare a shared pointer: `shared_int_ptr_6`
    - Initialize the pointer with `raw_int_ptr`
    - Which is essentially us telling the compiler
        - "We want to manage this memory address using the shared_ptr"
- Reassign `raw_int_ptr` with `nullptr`
- We are printing the data in the memory address that we cannot access through `raw_int_ptr`
    - Since we assigned the raw pointer to `nullptr`
    - Use `shared_int_ptr_6` to access the data
- Print the number of pointers pointing to the memory address managed by the shared pointer
- Print the address stored in the raw pointer
- Lastly, print the address stored in the shared pointer

While the previous example is interesting. There does not exist a valid reason for doing such
actions. We are mainly implementing this case for understanding how shared pointers
can take ownership of memory from a raw pointer.

#### Reset(): Decrement the Use Count & Set Ptr to `nullptr`

Let us look at `reset()` for `shared_ptr`'s. The behavior of `reset()` will be different compared to the behavior for
`unique_ptr`'s. For `shared_ptr`'s, `reset()` will decrement the `use_count`/reference count and reset the pointer to
`nullptr`.

The following is an example:

```c++
shared_int_ptr_5.reset();
fmt::println("Current shared_int_ptr_1.use_count(): {:>9}", shared_int_ptr_1.use_count());
fmt::println("Current shared_int_ptr_1.get(): {:>15}", fmt::ptr(shared_int_ptr_1.get()));
fmt::println("Current shared_int_ptr_5.use_count(): {:>9}", shared_int_ptr_5.use_count());
fmt::println("Current shared_int_ptr_5.get(): {:>15}\n", fmt::ptr(shared_int_ptr_5.get()));

```

We repeat this format for `shared_int_ptr_2` through `shared_int_ptr_4`. Which outputs:

```terminaloutput
Current shared_int_ptr_1.use_count():         4
Current shared_int_ptr_1.get():  0x70941e4cebe0
Current shared_int_ptr_5.use_count():         0
Current shared_int_ptr_5.get():             0x0

Current shared_int_ptr_1.use_count():         3
Current shared_int_ptr_1.get():  0x70941e4cebe0
Current shared_int_ptr_4.use_count():         0
Current shared_int_ptr_4.get():             0x0

Current shared_int_ptr_1.use_count():         2
Current shared_int_ptr_1.get():  0x70941e4cebe0
Current shared_int_ptr_3.use_count():         0
Current shared_int_ptr_3.get():             0x0

Current shared_int_ptr_1.use_count():         1
Current shared_int_ptr_1.get():  0x70941e4cebe0
Current shared_int_ptr_2.use_count():         0
Current shared_int_ptr_2.get():             0x0
```

Overall showcasing the behavior we previously mentioned.

#### `std::make_shared`

Similar to `unique_ptr`, we do not want to use `new` when initializing the memory that will be managed. Instead, we
utilize `std::make_shared` to initialize a new shared pointer.

The format for utilizing `std::make_shared` is the same as `std::make_unique`. Let us look at an example:

```c++
std::shared_ptr<int> shared_int_ptr_7 = std::make_shared<int>(455);
fmt::println("Value stored in shared_int_ptr_7: {}", *shared_int_ptr_7);
fmt::println("Use count for shared_int_ptr_7 is: {}\n", shared_int_ptr_7.use_count());
```

Outputting:

```terminaloutput
Value stored in shared_int_ptr_7: 455
Use count for shared_int_ptr_7 is: 1
```

Again all we are doing is:

- Instead of using `new int()`
- We are calling `std::make_unique`
    - Specify the data type: `int` in the angled brackets `<>`
    - Along with the value we want stored: `455`

Putting everything together we get:

```c++
std::shared_ptr<int> shared_int_ptr_8{shared_int_ptr_7};
fmt::println("shared_int_ptr_7.use_count(): ", shared_int_ptr_7.use_count());

fmt::println("Reset shared_int_ptr_7");
shared_int_ptr_7.reset();

fmt::println("shared_int_ptr_7.use_count(): ", shared_int_ptr_7.use_count());
fmt::println("shared_int_ptr_8.use_count(): ", shared_int_ptr_8.use_count());

```

Resulting in:

```terminaloutput
shared_int_ptr_7.use_count(): 2
Reset shared_int_ptr_7
shared_int_ptr_7.use_count(): 0
shared_int_ptr_8.use_count(): 1
```

#### Creating a `shared_ptr` from `unique_ptr`

We will be looking at how to make a `shared_ptr` from a `unique_ptr`. Let us look at an example:

```c++
std::unique_ptr<int> unique_int_ptr_1 = std::make_unique<int>(22);
std::shared_ptr<int> shared_int_ptr_1 = std::move(unique_int_ptr_1);
// std::shared_ptr<int> shared_int_ptr_2 = unique_int_ptr_1;

fmt::println("shared_int_ptr_1.use_count(): {}", shared_int_ptr_1.use_count());
fmt::println("Does unique_int_ptr_1 exist: {}", (unique_int_ptr_1 != nullptr));
```

Resulting in:

```terminaloutput
shared_int_ptr_1.use_count(): 1
Does unique_int_ptr_1 exist: false
```

Let us break down the example:

- Declare & Initialize a `unique_ptr`: `unique_int_ptr_1`
- Declare a `shared_ptr`: `shared_int_ptr_1`
    - Move ownership of the memory in `unique_int_ptr_1` to `shared_int_ptr_1`
    - Thus, resetting `unique_int_ptr_1`
- Looking at the commented out line
    - We tried to assign a `shared_ptr` (`shared_int_ptr_2`) with `unique_int_ptr_1`
    - However, this does not work
        - With the compiler crashing when trying to compile
        - Since the assignment operator does not move ownership
- Then we confirm our actions
    - Print the `use_count()` for `shared_int_ptr_1`
        - Confirming that the ownership of the memory
    - Then check if `unique_int_ptr_1` points to a valid memory address
        - If it points to `nullptr`
            - `unique_int_ptr` no longer "exist"

What if we wanted to convert a `shared_ptr` to a `unique_ptr`?

This would not work. Because at any given moment, we might have multiple `shared_ptr`'s pointing to the same
memory. If we tried to instantly make one of the said `shared_ptr`s into a `unique_ptr`, what would happen with
the remaining `shared_ptr`s. Adding in the fact that a `unique_ptr` has to have sole ownership of the memory it handles
would conflict with the behavior of `shared_ptr`'s. **Thus, the compiler prevents this from taking place.**
Looking at the following code snippet, assuming we have multiple `shared_ptr`s pointing to the same memory:

```c++
...
std::unique_ptr<int> illegal_unique_ptr_1 {shared_int_ptr_4};
std::unique_ptr<int> illegal_unique_ptr_2 = shared_int_ptr_3;
std::unique_ptr<int> illegal_unique_ptr_3 = std::move(shared_int_ptr_2);
...
```

All methods (braced initialization, assignment, and move) would result in a compiler error.

#### Returning a Smart Pointer

We previously covered the case where we could have a return value of `unique_ptr`. Which is essentially, the
function doing an implicit `std::move` to transfer the ownership. Knowing this along with the fact that we can
convert a `unique_ptr` to a `shared_ptr`, we can make a `shared_ptr` recieve a smart pointer.

In this case, we will be having a `shared_ptr` receive a `unique_ptr`.

```c++
std::unique_ptr<int> get_unique_ptr() {
    std::unique_ptr<int> ptr_u1 = std::make_unique<int>(142);
    fmt::println("unique_ptr address(in): {}", fmt::ptr(&ptr_u1));
    fmt::println("unique_ptr address(value): {}\n", fmt::ptr(ptr_u1.get()));
    return ptr_u1;
}

int main() {
    std::shared_ptr<int> shared_ptr_from_unique = get_unique_ptr();
    
    if (shared_ptr_from_unique) {
        fmt::println("shared_ptr_from_unique.use_count(): {}", shared_ptr_from_unique.use_count());
        fmt::println("shared_ptr_from_unique.get(): {}", fmt::ptr(shared_ptr_from_unique.get()));
    }
    
    return 0;
}
```

Rather than breaking down the whole example, we want to focus on the initialization of `shared_ptr_from_unique`.

- Similar to `unique_ptr`s implementation
    - We declare our `shared_ptr`: `shared_ptr_from_unique`
    - Call the function: `get_unique_ptr()`
        - This function will return a unique pointer as its name states
    - The `unique_ptr` it returns initializes the shared pointer: `shared_ptr_from_unique`
- Then we confirm if `shared_ptr_from_unique` does not point to `nullptr`
    - Printing the `use_count()` & its address
        - If valid

Which would look like the following output:

```terminaloutput
unique_ptr address(in): 0x7ffe72a6f8f8
unique_ptr address(value): 0x78a52cdf48c0

shared_ptr_from_unique.use_count(): 1
shared_ptr_from_unique.get(): 0x78a52cdf48c0
```

> Having a function return `unique_ptr` is the preferred method when using smart pointers.
> Since we can convert `unique_ptr`s to be the other smart pointer types, but the inverse is not possible.
> Thus, `unique_ptr`s are much more flexible to work with.

#### `shared_ptr` with Arrays (C++17 and above)

We will be exploring how to utilize `shared_ptr` with raw arrays. Let us look at an example:

```c++
std::shared_ptr<int[]> shared_int_arr_ptr {new int[10]{}};

for (size_t i{0}; i < 10; i++) {
    shared_int_arr_ptr[i] = i * 4;
}

for (size_t i{0}; i < 10; i++) {
    fmt::println("shared_int_arr_ptr[{}]: {}", i, shared_int_arr_ptr[i]);
}
fmt::println("");
```

Very straightforward implementation. Which is equivalent to standard dynamically allocated raw arrays.

- We declared our pointer: `shared_int_arr_ptr`
    - Define its type as an integer array: `<int[]>`
    - Then initialize the pointer using `new`
        - Adding the type & size of the dynamically allocated array: `int[10]`
    - We brace initialize the array, so all elements are defaulted to `0`
- In the `for` loops:
    - First we reassign each element in the array to be `i * 4`
    - The next `for` loop:
        - We access the data stored at each index: `i`
        - Then print the data

And that is an implementation on how to define, initialize, set an element, and read an integer array using
a `shared_ptr`.

> Reminder: This is only possible using a C++17 compiler or newer. Since the function of `operator[]` was
> added in the C++17 standard. Thus, any compiler using a standard lower than 17 will not work.

Another thing to remember is that `make_shared` is not supported for raw arrays. While there may exist some
compilers that do partially support this syntax, it is **not recommended** to use in any practical program.

Overall, there is no major need for using raw arrays with smart pointers. There are better and more practical
collection types.

#### `shared_ptr` as function parameters & return value

We will explore the use of `shared_ptr` as a function parameter and return values. We will mainly just be putting
the code example. Maybe add some information, but I do not want to go too in-depth about each method.

##### Pass by Value

```c++
void use_shared_ptr_by_value(std::shared_ptr<int> ptr_by_value) {
    fmt::println("Inside function:");
    *ptr_by_value = 41;
    fmt::println("*shared_ptr passed by value: {}", *ptr_by_value);
    fmt::println("shared_ptr use_count(): {}", ptr_by_value.use_count());
}
```

This is a valid implementation for a parameter of `shared_ptr` type, due to `shared_ptr`s being copyable.
Thus, `ptr_by_value` is a separate independent copy of the pointer we pass through to the function. Thus utilizing this
method, more memory is being used when passing a pointer.

An example output would be:

```terminaloutput
Before Passing by Value:
*shared_ptr value: 5
shared_ptr use_count(): 1

Inside function:
*shared_ptr passed by value: 41
shared_ptr use_count(): 2

After Passing by Value:
*shared_ptr value: 41
shared_ptr use_count(): 1
```

##### Pass by Non-`const` Reference

```c++
void use_shared_ptr_by_non_const_reference(std::shared_ptr<int> &ptr_by_non_const_ref) {
    fmt::println("Inside function:");
    //*ptr_by_non_const_ref = 145;
    //fmt::println("*shared_ptr passed by value: {}", *ptr_by_non_const_ref);
    ptr_by_non_const_ref.reset();
    fmt::println("shared_ptr use_count(): {}\n", ptr_by_non_const_ref.use_count());
}
```

This method is also valid. The main difference is we do not create a separate copy of the `shared_ptr` being passed.
Rather, we are simply passing the memory address of the `shared_ptr`. Which we confirm by calling the `use_count` and
the value remaining the same. We are still able to change the value of the pointer, but also `reset` it. Since we are
working with a continous pointer.

Example output:

```terminaloutput
Before Passing by Non-const Reference:
*shared_ptr value: 41
shared_ptr use_count(): 1

Inside function:
shared_ptr use_count(): 0

After Passing by Non-const Reference:
shared_ptr use_count(): 0
```

##### Pass by `const` Reference

```c++
void use_shared_ptr_by_const_reference(const std::shared_ptr<int> &ptr_by_const_ref) {
    fmt::println("Inside function:");
    *ptr_by_const_ref = 41;
    //ptr_by_const_ref.reset();
    fmt::println("*shared_ptr passed by value: {}", *ptr_by_const_ref);
    fmt::println("shared_ptr use_count(): {}\n", ptr_by_const_ref.use_count());
}
```

Again, we are not making a copy, rather passing the address of the `shared_ptr`. The main difference is the protection
of the pointer. Adding `const` prevents us from manipulating the pointer itself, not the object it points to (`int`
value). Thus, trying to run `reset()` on the pointer would make the compiler crash.

Example output:

```terminaloutput
Before Passing by const Reference:
*shared_ptr value: 145
shared_ptr use_count(): 1

Inside function:
*shared_ptr passed by value: 41
shared_ptr use_count(): 1

After Passing by const Reference:
*shared_ptr value: 41
shared_ptr use_count(): 1
```

##### Return by Value

We can also use `shared_ptr` as a function type. Returning a `shared_ptr` by value goes through return value
optimization and at the process no copy is made. Thus, a single `shared_ptr` is made. Similar to using `make_shared`
directly.

```c++
std::shared_ptr<int> get_shared_ptr() {
    fmt::println("Inside get_shared_ptr()");
    std::shared_ptr<int> shared_int_ptr = std::make_shared<int>(42);
    fmt::println("Address of new shared_ptr: {}\n", fmt::ptr(shared_int_ptr.get()));
    return shared_int_ptr;
}
```

Example output:

```terminaloutput
Inside get_shared_ptr()
Address of new shared_ptr: 0x7741a5800d60

After calling get_shared_ptr()
Address of new shared_ptr: 0x7741a5800d60
```

##### Return by Reference

**Be careful!!** We should note that returning `shared_ptr` by reference is complicated. The reference count
(`use_count`) is not going to be properly incremented. At the end, you will have a `shared_ptr` with a refernce count of
zero. Resulting in our program crashing.

```c++
std::shared_ptr<int> &get_shared_ptr_by_reference() {
    std::shared_ptr<int> shared_int_ptr = std::make_shared<int>(2);
    fmt::println("Inside get_shared_ptr_by_reference()");
    fmt::println("Address of new shared_ptr: {}\n", fmt::ptr(shared_int_ptr.get()));
    return shared_int_ptr;
}
```

This method is **NOT RECOMMENDED**. So, `shared_ptr` are not meant to be returned from functions by
reference. If attempted the following will occur:

```terminaloutput
/tmp/Module_8_Pointers/smart_ptrs.ixx:59:12: error: non-const lvalue reference to type 'shared_ptr<...>' cannot bind to a temporary of type 'shared_ptr<...>'
   59 |     return shared_int_ptr;
      |            ^~~~~~~~~~~~~~
1 error generated.
```

### `std::weak_ptr`

We will cover the last type of smart pointer currently avaliable. This smart pointer is special, in that they do not
own the data they point to. So if a `weak_ptr` goes out of scope, the memory they pointed to is not going to be
released.

Thus, these non-owning pointers do not implement the following operators: `->` or `*`. So, we cannot use them directly
to read or modify data. Let us look at an example implementing this pointer:

```c++
std::shared_ptr<int> shared_int_ptr_1 = std::make_shared<int>(200);
std::weak_ptr<int> weak_int_ptr_1(shared_int_ptr_1);

fmt::println("Pointed to value: {}", *weak_int_ptr_1); // Compiler Error, no dereference (*) operator defined
fmt::println("Pointed to address: {}", weak_int_ptr_1.get()); // No get method
```

Skipping the obvious:

- Declare a `weak_ptr` of type `int`: `weak_int_ptr_1`
    - Initialize the pointer with the `shared_ptr`: `shared_int_ptr_1`
    - Sets up another pair of pointers pointing to the same data
- But remember, `weak_ptr` cannot be used to read or write data
    - Thus, the next two line result in errors:

```terminaloutput
/tmp/Module_8_Pointers/smart_ptrs.ixx:318:46: error: indirection requires pointer operand ('std::weak_ptr<int>' invalid)
  318 |         fmt::println("Pointed to value: {}", *weak_int_ptr_1); // Compiler Error, no dereference (*) operator defined
      |                                              ^~~~~~~~~~~~~~~
/tmp/Module_8_Pointers/smart_ptrs.ixx:319:63: error: no member named 'get' in 'std::weak_ptr<int>'
  319 |         fmt::println("Pointed to address: {}", weak_int_ptr_1.get()); // No get method
      |  
```

If we really want to use a `weak_ptr`, we have no choice but to convert the pointer back into a `shared_ptr`.
We do that by using the lock method.

```c++
std::shared_ptr<int> weak_turned_shared = weak_int_ptr_1.lock();
fmt::println("Pointed to value: {}", *weak_turned_shared);
fmt::println("Pointed to address: {}", weak_turned_shared.get());
```

- We define a `shared_ptr` of type `int`: `weak_turned_shared`
    - Next, to assign data back to this `shared_ptr` we call the `lock()` method on our `weak_ptr`
    - This is going to turn what we had in our `weak_ptr` into a `shared_ptr`
- Now we are able to use the `shared_ptr` like usual

Something else to account for, if a `weak_ptr` were to go out of scope, this would not decrement the reference count.
Nor would it cause the memory to be released.

#### What is a `weak_ptr` useful for?

The main purpose of creating a `weak_ptr` in C++ is to solve a problem referred to as _Cyclic Dependency_ or
_Circular Dependency_. This occurs when two or more modules/classes/header file directly or indirectly rely
on each other to function or compile. Creating a "chicken-and-egg" loop where a supposed Component A cannot be completed
without Component B, but Component B cannot be completed without Component A.

This problem manifests in two major ways: compile-time/build issues and runtime memory management bugs.

##### Compile-Time: The Size and Include Dilemma

While most of the information discussed will not be clear now, let us continue. The C++ compiler processes files
sequentially and must know the exact memory size of an object to instantiate it. If two classes contain each other
as direct members, compilation fails. Example below:

```c++
// file: A.h
#include "B.h"

class A {
    B b_member; // Compiler needs to know the size of B
};

// file: B.h
#include "A.h"

class B {
    A a_member; // Compiler needs to know the size of A
};
```

Why does the example above fail?

Even if we were to add header guards, the compiler gets stuck. If it parses file `A.h` first, it pauses
to read file `B.h`. Inside the file `B.h`, it sees `A` used before `A` has finished defining. Triggering
"unknown type" or "incomplete type" compiler error.

How would we fix this?

Instead of nesting the entire object by value, we can store a pointer or reference. The compiler always knows the size
of a pointer (e.g. 8 bytes on a 64-bit system), regardless of what the pointer is pointing to.

```c++
// file: A.h
class B; // foward declaration telling the compiler "B is a class"

class A {
    B* b_pointer; // Valid! Compiler knows the size of pointer
};

// file: A.cpp

#include "B.h"
...
```

In the example above:

1. We use foward declaration (`class B;`) in the header
    - Rather than using `#include "B.h"`
2. Shift the actual include directive to the implementation file for `A`
    - Where the details are needed

##### Runtime: The `shared_ptr` Memory Leak

In this case, the cyclic dependencies occur at runtime using smart pointers. Creating a lock that
completely breaks automatic memory cleanup. Example below:

```c++
#include <iostream>
#include <memory>

struct Child; // Forward declaration

struct Parent {
    std::shared_ptr<Child> child_ptr;
    ~Parent() { std::cout << "Parent Destroyed\n"; }
};

struct Child {
    std::shared_ptr<Parent> parent_ptr;
    ~Child() { std::cout << "Child Destroyed\n"; }
};

int main() {
    {
        auto father = std::make_shared<Parent>(); // Parent ref_count = 1
        auto son = std::make_shared<Child>();     // Child ref_count = 1

        // Create the cycle
        father->child_ptr = son;                  // Child ref_count = 2
        son->parent_ptr = father;                 // Parent ref_count = 2
    } // father and son block variables go out of scope here

    return 0;
}

```

The example above fails because when the local variables pointing to `son` and `father` go out of scope,
the objects remain alive on the heap. Since they keep each other's reference count at `1`. Causing a
permanent memory leak. Preventing destructors from executing.

To break smart pointer reference loops, we need to change one side of the relationship to a `weak_ptr`. Thus,
simultaneously destroying the cyclic dependencies and the circular ownership loop.
A `weak_ptr` references an object without increasing its ownership count.

```c++
#include <iostream>
#include <memory>

struct Child; // Forward declaration

struct Parent {
    std::shared_ptr<Child> child_ptr; // Strong ownership: Parent owns Child
    ~Parent() { std::cout << "Parent Destroyed\n"; }
};

struct Child {
    std::weak_ptr<Parent> parent_ptr; // Weak reference: Child observes Parent (No ownership)
    ~Child() { std::cout << "Child Destroyed\n"; }
};

int main() {
    {
        auto father = std::make_shared<Parent>(); // Parent ref_count = 1
        auto son = std::make_shared<Child>();     // Child ref_count = 1

        father->child_ptr = son;                  // Child ref_count = 2
        son->parent_ptr = father;                 // Parent ref_count stays 1!
    } 
    // Out of scope: father goes away. Parent ref_count hits 0. Parent is destroyed.
    // Destroying Parent destroys its child_ptr. Child ref_count hits 0. Child is destroyed.
    return 0;
}

```

To outright avoid this problem, we need to define a clear ownership. So, we use

- a `shared_ptr`/`unique_ptr` strictly for top-down ownership (`Parent -> Child`)
- `weak_ptr` or a raw pointer for bottom-up relationship (`Child -> Parent`)
- prioritize using `unique_ptr` by default.
    - Creating cycles are more difficult to accidentally create when an object has only one true owner

---

## References
