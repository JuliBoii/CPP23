# Pointers, Dynamic Memory, & Arrays

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

```shell
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

```shell
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

```shell
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

```shell
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

```shell
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

```shell
Message: Bello World
```

The C++ code also showcases our previous point. The variable, most of the time,
is a "Pointer".