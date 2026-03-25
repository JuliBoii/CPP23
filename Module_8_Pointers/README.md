# Pointers, Dynamic Memory, & Arrays

---

## Pointers

We will be starting to explore pointers in C++. With pointers being one of the most confusing
parts of C++. Realistically, they are not hard concepts to understand.

**A pointers is a variable that contains an address of another variable.**

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
int* ptr = &num;
```

| Pointer `var`                    |
|----------------------------------|
| Name: ptr                        |
| Value: 0x7ffe (Address of `num`) |
| Address: 0x8abc                  |

For clarity, `int` is a type and a `pointer` is a type which contains addresses pointing to other
variables. So it looks like the following (for visual aid):

| Memory Address (Hex) | Memory Value                  |
|----------------------|-------------------------------|
| 0x7ffe ->            | 42 (Value of `num`)           |
| 0x8abc ->            | 0x7ffe (Value stored by `ptr` |

Lets breakdown the syntax for declaring & initializing a pointer.

### Declaring & Initializing

```c++
int* ptr = &variable_name;
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

As previously mentioned, the stack stores our local variables and function calls.
While the heap is for dynamic memory, memory that is not prepared and assigned by the
compiler/computer.

We can utilize the heap using the `new` and `delete` operators

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

Overall, the pointers will be the same size regardless if the pointer is an `int`, `double` or other data type.