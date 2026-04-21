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

The C++ code also showcases our previous point. The variable name, most of the time,
is a "Pointer".

## `const` Pointers & Pointer to `const`

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

```shell
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

```shell
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

```shell
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

```shell
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


```shell
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

```shell
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

```shell
p_number1 Value Pointed To: 4214
p_number1 Address Stored: 0x306e6ff9d4
number1 Value Stored: 4214
number1 Address: 0x306e6ff9d4
```

Similar to our previous examples.

Now, what if we want to change the value stored in `number1`.

Let us try modifying the value of `number1` through the pointer:

```c++
*p_number1 = 4321;
```

When compiled, the compiler fails. Returning the following in the terminal:

```shell
pointer2.ixx(77): error C3892: 'p_number1': you cannot assign to a variable that is const
```

Demonstrating that the pointer is not able to modify the data located
at the address being pointed at. Thus, "limiting" the capability of the
pointer.

Let us look at what is being stated by the compiler first.

```shell
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

```shell
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

---