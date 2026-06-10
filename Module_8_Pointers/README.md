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

## When `new` fails´

Let us explore a situation where `new` could fail.

Why would that happen?

Memory is not unlimited, whether we are talking about the stack or heap.
In this case, we are focusing on the heap, with dynamically allocated memory existing here.
Even though the heap has more memory available than the stack, the quantity is still limited.

Thus, if we ask for more memory than a system has, `new` will fail. Which will crash the program.

Let us look at an example that could possibly break.

```c++
int* data == new int[100000000000000];

for (size_t i{0}; i < 100000000000000; ++i)
{
    std::println("Iteration: {}", i);
    int* data = new int[100000000000000];
}
```