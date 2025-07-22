# Variables, Data Types & Basic Operations

---

## Overview

Part 1

Exploring variables and data types
- Topics:
  - Number systems for integers
    - Decimal, Octal, Hexadecimal and Binary
  - Data representation in memory
    - Integers, Floating point types
  - Type ranges for ints & floats

Part 2

Integer Modifies, Characters, Text, & `auto`
- Topics:
  - Initialization:
    - Braced initialization
    - Function style initialization
    - Assignment initialization
  - Integer modifiers
  - Floating point numbers:
    - Precision
    - Scientific notation
    - Infinity and NaN
  - Booleans
  - Characters & Text
    - `char`
  - Collections
    - `std::vector`
    - `std::array`
    - `std::string`
  - `auto`

Part 3

Operations, Math Functions, and Weird Integer Types
- Topics:
  - Basic Operations
    - Addition
    - Subtraction
    - Multiplication
    - Division
    - Modulus
  - Precedence & Associativity
  - Increment & Decrement (Prefix & Postfix)
  - Compound Assignment Operators
  - Relational Operators
  - Logical Operators
  - Math Functions
  - Weird Integral Types
  - Data Conversion
    - Implicit
    - Explicit
  - Overflow & Underflow

Part 4

Bitwise Operators
- Topics
  - Printing Integers in Binary
  - Shift Operators
  - Logical Bitwise Operators
  - Compound Bitwise Operators
  - Masks

---

## Number Systems

- Give us a way to interpret the data that is stored in memory
  - Anything our computer works with will be stored as `0`'s and `1`'s
  - **_Does not matter if_** it is a whole number, floating point, string, character
- In our case the RAM will be storing our data as `0`'s and `1`'s
  - So, you can interpret this data as an:
    - Integer
    - Decimal
    - String
    - Or anything else we want to work with

### Decimal

- Let us look at the number systems, starting with decimal
- Referred to as Base Ten, in some cases
  - Why?
    - We multiply our digits by 10 raised to the position of the digit starting
  - The digits we use are between 0-9
  - Given a whole number, we can deduce it using the formula:

$$\mathbb{W} = \sum_{n=0}^{\text{digits}}\left(\mathbb{w}_n*10^{n}\right)$$

- Example 1:
  - Say we have the number `2371`
  - We can deduce it using the following formula:

```math
2371 = 2*10^{3} + 3*10^{2} + 7*10^{1} + 1*10^{0}
```

- Example 2:
  - Say we have the number `924`
  - We can deduce it as:

```math
924 = 9*10^{2} + 2*10^{1} + 4*10^{0}
```

- Example 3:
  - For `47` it would be:

```math
47 = 4*10^{1} + 7*10^{0}
```

### Binary

- Now we are looking at the binary number system
- Follows a similar idea to decimal, but we are working with two digits
  - The digits we use are either 0 or 1
- We use a similar formula, however we use the formula to decipher the decimal representation
  - We use the following formula:

$$\mathbb{N} = B = \sum_{n=0}^{\text{digits}}\left(B_n*2^{n}\right)$$

- Example 1:
  - Given: `100101`

``` math
\begin{matrix} = 1*2^{5} + 0*2^{4} + 0*2^{3} + 1*2^{2} + 0*2^{1} + 1*2^{0} \\ = 32 + 0 + 0 + 4 + 0 + 1 \\ = 37 \end{matrix}
```

- Example 2:
  - Given: `10010`

``` math
\begin{matrix} = 1*2^{4} + 0*2^{3} + 0*2^{2} + 1*2^{1} + 0*2^{0} \\ = 16 + 0 + 0 + 2 + 0 \\ = 18 \end{matrix}
```
- Example 3:
  - Given: `111`

``` math
\begin{matrix} = 1*2^{2} + 1*2^{1} + 1*2^{0} \\ = 4 + 2 + 1 \\ = 7 \end{matrix}
```

- With binary, we can group the number of bits we want
  - Thus, the possible data representation can vary
  - Looking at the table below
    - We can see the possible data representation dependent on the number of bits we group

| Digits |        Data Range        |
|:------:|:------------------------:|
|   1    |           0~1            |
|   2    |           0~3            |
|   3    |           0~7            |
|   4    |           0~15           |
|   5    |           0~31           |
|  ...   |           ...            |
|   n    | 0~$`2^\left(n\right)-1`$ |

- There also exist some practical groupings of data in modern computers
  - Shown below:

| Digits | Bytes | Data Range                   |
|:------:|:-----:|:-----------------------------|
|   8    |   1   | 0~255                        |
|   16   |   2   | 0~65,535                     |
|   32   |   4   | 0~34,359,738,367             |
|   64   |   8   | 0~18,446,744,073,709,551,615 |

### Hexadecimal

- Another common method to interpret data
- Works like this:
  - Binary data is going to be grouped in groups of four
  - Decimal data is going to range from `0` to `15`
  - Hexadecimal will be represented with both integers and characters
    - Integers range: `0~9`
    - Chars range: `A~F`
- The equivalent between the number systems is shown below:

| Binary | Decimal | Hex |
|:------:|:-------:|:---:|
|  0000  |    0    |  0  |
|  0001  |    1    |  1  |
|  0010  |    2    |  2  |
|  0011  |    3    |  3  |
|  0100  |    4    |  4  |
|  0101  |    5    |  5  |
|  0110  |    6    |  6  |
|  0111  |    7    |  7  |
|  1000  |    8    |  8  |
|  1001  |    9    |  9  |
|  1010  |   10    |  A  |
|  1011  |   11    |  B  |
|  1100  |   12    |  C  |
|  1101  |   13    |  D  |
|  1110  |   14    |  E  |
|  1111  |   15    |  F  |

- Example:
  - Given `0110 1110 0011 0000 1111 0001 0011 1111`
    - How would we represent this in Hexadecimal?
    - Using the table above we find the equivalent representation:

``` math
\begin{matrix} 0110 \rightarrow 6 \\ 1110 \rightarrow E \\ 0011 \rightarrow 3 \\ 0000 \rightarrow 0 \\ 1111 \rightarrow F \\ 0001 \rightarrow 1 \\ 0011 \rightarrow 3 \\ 1111 \rightarrow F \end{matrix}
```

- Which we format in Hexadecimal with the prefix `0x`
  - So it would look like: `0x6E30F13F`

### Octal

- Octal is sort of the little brother of the hexadecimal system
  - Because groups data in blocks of three
  - So it works like this:
    - Binary data is going to be grouped in groups of three
    - Decimal data is going to range from `0` to `7`
    - Octal data is going to range from `0` to `7`

| Binary | Decimal | Octal |
|:------:|:-------:|:-----:|
|  0000  |    0    |   0   |
|  0001  |    1    |   1   |
|  0010  |    2    |   2   |
|  0011  |    3    |   3   |
|  0100  |    4    |   4   |
|  0101  |    5    |   5   |
|  0110  |    6    |   6   |
|  0111  |    7    |   7   |

- Example:
  - Given `01 101 110 001 100 001 111 000 100 111 111`
    - How do we represent this in Octal?
    - Using the table above we find the equivalent representation:

``` math
\begin{matrix} 01 \rightarrow 1 \\ 101 \rightarrow 5 \\ 110 \rightarrow 6 \\ 001 \rightarrow 1 \\ 100 \rightarrow 4 \\ 001 \rightarrow 1 \\ 111 \rightarrow 7 \\ 000 \rightarrow 0 \\ 100 \rightarrow 4 \\ 111 \rightarrow 7 \\ 111 \rightarrow 7 \end{matrix}
```

- Which we format in Octal with the prefix `0`
  - followed by the number
- `0 15614170477`

[Use this page for a sample table converting between Binary, Decimal, & Hexadecimal](https://servicenow.iu.edu/kb?id=kb_article_view&sysparm_article=KB0026046)

---

## Data Representation

- Now we know how data is represented in memory
- We will start and working with real data
- Starting by showing how we work with decimal numbers in C++
- C++ provides three fundamental types that you use to represent data
  - In regards to decimal types.
    - We have:
      - `float`
      - `double`
      - `long double`

### Float

- `float` offers 6 digits of precision (after decimal)
- Range of `float` is `-3.4028235e+38` to `3.4028235e+38`

### Double

- `double` offers 15 digits of precision (after decimal)
- Range of `double` is `-1.79769e+308` to `1.79769e+308`

### Long Double

- `long double` offers 18 digits of precision (after decimal)
- Range of `long double` is `-1.189731495357231765e+4932` to `1.189731495357231765e+4932`

|    Type     |     Size     | Precision              | Notes                                |
|:-----------:|:------------:|:-----------------------|:-------------------------------------|
|    float    |   4 bytes    | ~6 digits              | IEEE 754 single precision            |
|   double    |   8 bytes    | ~15 digits             | IEEE 754 double precision            |
| long double |   8 bytes    | ~15 digits (MSVC)      | Same as double on Windows/MSVC       |
| long double | 10/16 bytes  | ~18 digits (GCC/Clang) | 80-bit or 128-bit extended precision |

## Memory Representation

- A single-precision float (float) in C++ is stored as a 32-bit binary value
  - Divided into 3 components:
    - Signed Bit:
      - 1 bit (the most significant bit)
    - Exponent:
      - 8 bits
    - Mantissa (fraction):
      - 23 bits

|  Sign (1 bit)   |     Exponent (8 bits)      |    Mantissa (23 bits)     |
|:---------------:|:--------------------------:|:-------------------------:|
| $`31^{st}`$ bit | $`30^{th}`$ to $`23^{rd}`$ | $`22^{nd}`$ to $`0^{th}`$ |

- In other words, even floating-point types are also represented as `0`'s and `1`'s
  - _Going from a binary representation to the float representation requires to follow the [procedure stipulated by IEEE](https://www.geeksforgeeks.org/ieee-standard-754-floating-point-numbers/)_
  - **Will not be discussed**

---

## Initialization

### Braced Initialization (Recommended)

The first type of initialization we will look at is braced initialization.

- The syntax is just putting the initializer value in a pair of curly braces: `{value}`
- If you do not put in a value

``` c++
int temp{};
```

  - The compiler will recognize that the curly braces are empty and initialize the variable with either `0/false/nullptr`
    - Depends on the variable type
  - **_Note this only occurs for braced initialization_**
    - Thus, if we did:

  ```c++
  int elephant_count;
  ```
  
  - Dependent on the compiler, the variable will be initialized with junk
  - **Thus, it is recommended to put an initialized value in variables, when declared**
- We can also use an expression as an initializer
  - For example:
  
    ```c++
    int domesticated_animals{dog_count + cat_count};
    ```
    
    - We use the result from `dog_count + cat_count` as the initializer value
- We **cannot** initialize a value, or a variable with a variable that does not exist
  - For example:
  
    ```c++
    int new_number{doesnt_exit};
    ```
    
    - We use `doesnt_exist` as the initializer value
    - But we never declared the variable nor initialized it
    - **If we tried to, the compiler will throw an error and fail**
- Braced will also warn you if you try to implicitly type convert
  - For example:
  
    ```c++
    int conversion_var{2.9};
    ```
    
    - In this case, we are trying to initialize an integer variable with a floating-point number
      - In other words, we are using two different types
      - In some cases, the compiler will try to drop the decimal points, but this is not guaranteed behavior
        - That is why it is not recommended to do implicit conversion
    - Another reason, to use braced initialization
      - The compiler will see this situation and throw an error, depending on the compiler
        - Some may throw a warning

### Functional Initialization

Next type of initialization is functional initialization

- The syntax is just putting the initializer value in a pair of parentheses: `(value)`
- This type of initialization will not have a default initialization behavior like braced
  - Thus writing `int varA();` will throw an error
  - Since the compiler will assume you are trying to declare or use a function
- Similar to braced initialization
  - We can also use an expression as an initializer
    - For example:
      ```c++
      int domesticated_animals(dog_count + cat_count);
      ```
      - We use the result from `dog_count + cat_count` as the initializer value
  - We **cannot** initialize a variable with another variable that does not exist
    - For example:
      ```c++
      int new_number(doesnt_exit2 + doesnt_exist3);
      ```
      - We use `doesnt_exist2` and `doesnt_exist3` as the initializer values
      - But we never declared the variables nor initialized them
      - **If we tried to, the compiler will throw an error and fail**
- Unlike braced initialization, functional initialization **will allow** you to implicitly type convert
  - For example:

    ```c++
    int conversion_var(2.9);
    ```
    
    - In this case, we are trying to initialize an integer variable with a floating-point number
      - The compiler will try to drop the decimal point and only store the integer
      - However, this is **not** an ideal way to do things in Modern C++
        - Again, it is recommended to use braced initialization

### Assignment Initialization

The next type of initialization is assignment initialization

- The syntax is just putting the initializer value on the right side of the `=` operator: `int temp = 8;`
  - This is also an old manner of initializing variables in C++
    - It is also recommended to not use this method, when possible
- This method requires a value on the right side of the operator, otherwise the compiler will throw an error
- Similar to the previous methods, we can also use an expression as an initializer
  - For example:
    ```c++
	int domesticated_animals = dog_count + cat_count;
	```
    
- Like functional initialization, assignment initialization **will allow** you to implicitly type convert
  - For example:

    ```c++
    int conversion_var = 2.9;
    ```

    - In this case, we are trying to initialize an integer variable with a floating-point number
      - The compiler will try to drop the decimal point and only store the integer

---

## Integer Modifiers

Integer modifiers are words that you can prepend to the variable type to change how it behaves by default.

### Signed

- Modifier makes sure a variable can store both negative and positive values
  - This is typically the _**default**_ behavior for variables
  - Thus, even if you do not put the `signed` modifier
    - The variable will work as if the variable did have the modifier
- The range of values they can store is:

```math
-2^{n-1} \thicksim 2^{n-1}-1
```

- `n` is the number of bits for a type in memory

### Unsigned

- Modifier makes sure a variable can **_only_** store positive values
  - If you attempt to store negative values, the compiler will throw an error
- The range of values they can store is:

```math
0 \thicksim 2^{n}-1
```

- `n` is the number of bits for a type in memory
- Looking at both value modifiers:

|  Type with modifier |  Bytes in memory  |               Range               |
|--------------------:|:-----------------:|:---------------------------------:|
|        unsigned int |         4         |        [0, 4,294,967,295]         |
|          signed int |         4         |  [-2,147,483,648, 2,147,483,647]  |

These are not the only modifiers in C++. The following two can also be used

### Short

- `short` is going to shorten the range or the size of a type in memory
- Normally, an integer takes 4 bytes of memory
  - But, if you prefix the `short` modifier to an integer
    - It will become a `short int`, thus will only occupy 2 bytes of memory

### Long

- `long` is going to try to extend the size of a type in C++
- We know that a standard integer will take 4 bytes
  - But, if you prefix the `long` modifier to an integer
    - It will _probably_ take 4 or 8 bytes.
    - **_This strongly depends on the compiler & system_**
- You can also use `long long`, which should also be 8 bytes
  - Although they can be combined, the behavior will be equivalent to a singular `long`


It should be noted, the previous sets can be used together. Looking in the `utilities.ixx` file,
navigating to the `export void integer_mods()` function, we can see examples of the possible combinations.

---

## Fractional Number Representation

### Precision

The following is an example of how we declare and initialize floating-point variables

``` c++
float number1{1.12345678901234567890f}; // Precision: 7
double number2{1.12345678901234567890}; // Precision: 15
long double number3{1.12345678901234567890L};

// Print out the size
std::cout << "Size of float: " << sizeof(float) << "\n";
std::cout << "Size of double: " << sizeof(double) << "\n";
std::cout << "Size of long double: " << sizeof(long double) << "\n";

// Precision
std::cout << "number1 is: " << number1 << "\n"; // 7 digits
std::cout << "number2 is: " << number2 << "\n"; // ~15 digits
std::cout << "number3 is: " << number3 << "\n"; // 15+ digits
```

- The problem:
  - With `float` the precision is usually too limited
    - for various applications

```c++
float number4{192400023.0f};    // Error: Narrowing conversion
```

- In these examples, we are focusing on the representation we use to signal the types we are working with
  - The example above used `fixed notation`

### Scientific Notation

If we want to represent our data in scientific notation
- We grab the location where the decimal point is
  - Add an exponent
  - `e` meaning how many zeros or how many digit places we will have to go after the decimal point
- Looking at our example below, we compare fixed- & scientific notation

``` c++
double number5{192400023};
double number6{1.92400023e8}; // fixed notation
double number7{1.924e8};  // Scientific notation
```

- `e` is equivalent to $`1 * 10^{n}`$
  - Where `n` is the number of decimal places to move forward or backward
  - Thus, number7 is represented as $`1.924 * 10^{8}`$
- You may also notice that we are purposely losing data by dropping `00023` from the scientific notation
  - It is something that we have to deal with
- Overall, we can use fixed or scientific notation to initialize our floating-point variables
- **It is handy if you have really huge numbers or small numbers to represent**

### Infinity & NaN

- You get infinity when you try to divide a big number with a small number
  - _This is a very simple and general explanation_
  - When we do the supposed scenario, the result is a number so big
    - That the computer is unable to represent it
    - Resulting in `inf`
      - The representation of infinity
  - We also provide an example where if you add a number to infinity: $`\infty + n = \infty`$
    - You get infinity
  - The same applies if you subtract a number to infinity: $`\infty - n = \infty`$
    - You get infinity
  - A concept that is shown in math
- The other concept is `NaN`, which you get when you try to divide a zero by zero
  - Resulting in a "Not a Number"
    - Something that cannot be accurately represented
  - Which is represented as `nan` in C++

---

## Boolean

Booleans are types that you use to store `true` and `false` values

- This type has two states:
  - True
  - False
- Example:
  - We have a variable that tracks if we are happy or sad
  - So at any point we could be happy or sad
  - This would be a boolean
    - Since there are two possible states
- We represent booleans using the `bool` type
  - We specify the type `bool`
  - Give it a variable name `some_name`
  - Then initialize the variable with `true` or `false`
    - We could also initialize the bool with integers other than `0` and `1`
      - But they would be considered equivalent to `1`, which is `true`
- If you try to print out a bool
  - They will be printed out as a `0` or `1`
    - Rather than `false` or `true`, respectively
  - _In our code example `fmt` automatically formats bool output as true or false_
- In summary, we use bools to store information that has a binary state
  - The value is going to be true or false

---

## Characters & Text

### Char

We will be exploring the type that C++ provides to store characters.

- C++ stores characters in the data type `char`
- To use the data type, we first type `char`
  - Followed by a variable name `some_name`
  - Then initialized with a character literal surrounded by single quotes
  - Example below:

```c++
char char_variable_name{'a'};
```

- In most cases, `char` is going to occupy 1 byte of memory
  - So, its range is $`2^{8} = 256`$ different values: `(0 ~ 255)`
- We can also store an integer equivalent of a character
- Using the ASCII System, numbers are mapped to characters
  - Looking at an [ASCII table](https://www.asciitable.com/), we can see such information
  - Lowercase letters are mapped between `97 ~ 122`
  - Uppercase letters are mapped between `65 ~ 90`

### Collections

Collections are facilities that allow you to store groups of data.

We want to the ways we can group things together and treat them as a single unity. Think of it as 
putting items in a box, and handling them as a single thing.

- We are introduced to two types
  - `std::vector`
  - `std::array`
    - If we want a more detailed information we can use [CPP Reference](https://cppreference.com/)

#### `std::vector`

- Is a sequence container that encapsulates dynamic sized arrays
- This will be storing elements in a sequence
  - Thus being aligned in sequence in memory
- To use a vector we declare it like the following:
  - But first, we have to declare that we are using the `vector` library

```c++
#include <vector>

//std::vector<data_type> some_name{};
std::vector<char> some_name{'s','f','g','r','l'};
```

#### `std::array`

- Is a container that encapsulates fixed sized arrays
- This container is _"fixed"_, so we have to define the size of the array
  - Additionally, once defined, we cannot increase nor decrease the size of the array
- To use an array we declare it like the following:
  - But first, we have to declare that we are using the `array` library

```c++
#include <array>

//std::array<data_type, array_size> some_name{};
std::array<char, 5> some_name{'s','f','g','r','l'};
```

_An important thing to remember is that each container can **only** hold a single type of data_

So we cannot add various types of data into either container, if we do, it will result in a compiler error

#### std::string

There is another method to group characters. We use the `string` type

- This type is can print the collection of characters as one output.
- To use a string, we declare it like the following:
  - But first, we have to declare that we are using the `string` library

```c++
#include <string>

std::string some_name{"A string"};
```

- We specify a variable name
- Then we specify our characters within double quotes

_Not mentioned, but each of these containers have additional functions that can manipulate
each container. Each have their independent functions that can be found respectively using the
resource mentioned earlier (CPP Reference)._

---

## `auto` Keyword

A way to declare variables without explicitly specifying their types.

- Handy especially in generic programming
- The compiler deduces the variable type based on what you initialize your variable with
- If we want the compiler to use a more specific type of variable
  - We can provide modifier suffixes

---

## Basic Operations

### Addition

```c++
int a{5};
int b{25};

int result = a + b;
std::cout << result << std::endl;
```

### Subtraction

```c++
int a{13};
int b{24};

int result = b - a;
std::cout << result << std::endl;
```

### Multiplication

```c++
int a{7};
int b{41};

int result = a * b;
std::cout << result << std::endl;
```

### Division

```c++
int a{45};
int b{25};

int result = a / b;
std::cout << result << std::endl;
```

### Modulus

```c++
int a{17};
int b{25};

int result = b % a;
std::cout << result << std::endl;
```

---

## Precedence & Associativity

A concept in C++ that allows you to know from where to start if you happen to have a compound expression.
Like the one below:

```c++
const int a{25};
const int b{32};
const int c{814};
const int d{-14};

int result{a + b * c - d / b};
```

What precedence & associativity gives us is:

- a set of rules to follow to know the correct result of a compound expression.
- Looking at [CPP Reference](https://cppreference.com/w/cpp/language/operator_precedence.html) we can find a precedence & associativity chart
  - Giving us detailed information about the precedence order
- Precedence & associativity are compile-time concepts
- Associativity will determine the order things are done if the operators have the same precedence level
  - That is why the example above does not give us the result: `1450`
    - Instead, we get the result: `26073`
  - That is why, using parentheses is necessary to structure the behavior of operators, in some cases
    - Which we show a minor example in `utilities.ixx`, in the `precedence_and_associativity()` function
      - How parentheses can change the outcome

---

## Prefix & Postfix Increment/Decrement

- These operators can be used with numeric data types (`int, double, float,` etc.)
- When we talk about incrementing `++`
  - We mean the operation of adding one to a value
  - Thus, adding is incrementing
- When we talk about decrementing `--`
  - We mean the operation of subtracting one to a value
  - Thus, subtracting is decrementing

### Prefix

- In Prefix operations, the operator is used as the prefix of the variable
- The decrementing/incrementing occurs as soon as the operator is encountered
- Syntax of Prefix:

```c++
int value{5};

// For pre-decrementing
--value; // value = 4

// For pre-incrementing
++value; // value = 5
```

### Postfix

- In Postfix operations, the operator is used as the postfix of the variable
- The decrementing/incrementing occurs after all the other operations are performed
  - In other words, other operators are evaluated
- Syntax of Postfix:

```c++
int value {5};

// For post-decrementing
value--; // value = 4

// For post-incrementing
value++; // value = 5
```

- Both examples above are equivalent to the following:

```c++
int value{5};

value = value - 1; // value = 4

value = value + 1 // value = 5
```

- Looking at `prefix_postfix_increment_and_decrement_operators()` in `utilities.ixx`
  - The pre-decrement & post-decrement example, the output shows us:
    - the value of `postNum` is 10, which is not the decremented value of `value2`
      - Because post-decrement assigns the value before the decrement.
      - Thus, when we print `value2` it is decremented by 1
    - On the other hand, `preNum` and `value` are 4
      - Because pre-decrement first decreased the value by 1 and then assigned its value to another variable (in this case)

---

## Compound Assignment Operators

Suppose we have a value in our variable:

- We take whatever value we have in our variable
- Then want to do some operation on it
- Take the result, and assign it to the same (initial) variable
- Which would look like the following:

```c++
int value {5};
value = value + 5;
```

Compound assignment has a special syntax that simplifies the verbosity

```c++
int value{5};

// Addition
value += 5;
std::cout << value << '\n';

// Subtraction
value -= 5;
std::cout << value << '\n';

// Multiplication
value *= 5;
std::cout << value << '\n';

// Division
value /= 5;
std::cout << value << '\n';

// Modulus
value %= 3;
std::cout << value << '\n';
```

---

## Relational Operators

These are operators that we use to compare things.

```c++
int num1{20};
int num2{10};

// Less than
std::cout << "num1 < num2: " <<  num1 < num2 << '\n';

// Less than or equal to
std::cout << "num1 <= num2: " <<  num1 <= num2 << '\n';

// Greater than
std::cout << "num1 > num2: " <<  num1 > num2 << '\n';

// Greater than or equal to
std::cout << "num1 >= num2: " <<  num1 >= num2 << '\n';

// Equal to
std::cout << "num1 == num2: " <<  num1 == num2 << '\n';

// Not Equal to
std::cout << "num1 != num2: " <<  num1 != num2 << '\n';
```

---

## Logical Operators

Are useful if you try to make decisions dependent on varying results in a program

### && (AND)

`AND` operator evaluates to `true` when **_all_** operands are `true`.

- A single `false` operand will drag the entire expression to evaluating `false`

```c++
bool a{true}, b{false}, c{true};

std::cout << "a && b: " << a && b << '\n'; // false
std::cout << "a && c: " << a && c << '\n'; // true
std::cout << "a && b && c: " << a && b && c << '\n'; // false
```

### || (OR)

`OR` evaluates to `true` when **_at least_** one operand is `true`

- A single `true` operand will push the entire expression to evaluating `true`

```c++
bool a{true}, b{false}, c{true};

std::cout << "a || b: " << a || b << '\n'; // true
std::cout << "a || c: " << a || c << '\n'; // true
std::cout << "a || b && c: " << a || b || c << '\n'; // true
```

### ! (NOT and combinations)

`!` negates whatever operand you combine it with

- So it prefixes an operand: `!bool_value`
  - Thus, a `true` value becomes `false` with the operand added
  - And `false` becomes `true` with the operand added
- This can also be added to longer logical operation

```c++
bool a{true}, b{false};

std::cout << "a: " << a << "\n!a" << !a << '\n';
std::cout << "b: " << b << "\n!b" << !b << '\n';
std::cout << "a && b: " << a && b << "\n!(a && b)" << !(a && b) << '\n';
std::cout << "a && b: " << a && b << "\na && !b" << a && !b << '\n';
```

---

## Math Functions

We are exploring a few math functions in the `cmath` library that we can utilize. Like
in previous instances, we need to state that we are using the `cmath` library, to access
the functions. Thus, we write the following in our code:

```c++
#include <cmath>
```

### `std::floor` (Flooring)

- Used to round down a decimal number
- We use it to compute the largest integer value
  - That is not greater than our number

```c++
double num{14.143315};

std::cout << num << " is floored to: " << std::floor(num) << '\n';
// num is floored to: 14
```

### `std::ceil` (Ceiling)

- Used to round up a decimal number
- We use it to compute the least integer value
  - That is not less than our number

```c++
double num{14.143315};

std::cout << num << " is ceiled to: " << std::ceil(num) << '\n';
// num is ceiled to: 15
```

### `std::abs` (Absolute Value)

- Used to obtain the absolute value of a floating-point value
  - Meaning, the value is exact and does not depend on any rounding modes
  - So, if we input a negative value, we will receive a positive equivalent of the value

```c++
double num{-148.145};

std::cout << "ABS of num is: " << std::abs(num) << '\n';
// ABS of num is: 148.145 
```

### `std::exp` (Exponential)

- This is how we use the provided exponential function: $`f\left(x\right) = e^{x}`$
  - Where $`e`$ is equal to `2.7182818...`
- This command computes Euler's Number raised to the given power, `x`, that we provide

```c++
double result{std::exp(10)};

std::cout << "The exponential of 10 is: " << result << '\n';
// The exponential of 10 is: 22026.465794806718
```

### `std::pow` (Power)

- This is how we raise a value to a desired power: $`base^{x}`$
  - Where `base` is the base, and it is raised to the power of `x`
  - Base can be a floating-point or integer value
  - Exponent `x` is a floating-point or integer value

```c++
double result{std::pow(5, 7)};

std::cout << "5^7 is: " << result << '\n';
// 5^7 is: 78125
```

### `std::log`, `std::log10`, & `std::log2` (Logarithms)

- `std::log` computes the natural (base-$`e`$) logarithm of a number, `x`: $`\log(x)`$
  - `x` can be a floating-point or integer value

```c++
double result{std::log(1)};

std::cout << "base-e log of 1 = " << result << '\n';
// base-e log of 1 = 0
```

- `std::log10` computes the common (base-10) logarithm of a number, `x`: $`\log_{10}(x)`$
  - `x` can be a floating-point or integer value

```c++
double result{std::log10(1000)};

std::cout << "base-10 log of 1000 = " << result << '\n';
// base-10 log of 1000 = 3
```

- `std::log2` computes the binary (base-2) logarithm of a number, `x`: $`\log_{2}(x)`$
  - `x` can be a floating-point or integer value

```c++
double result{std::log2(65536)};

std::cout << "base-2 log of 65536 = " << result << '\n';
// base-2 log of 65536 = 16
```

### `std::sqrt` (Square Root)

- Computes the square root of a number: $`\sqrt{x}`$
  - `x` can be a floating-point or integer value

```c++
double result{std::sqrt(100)};

std::cout << "Square root of 100 is: " << result << '\n';
// Square root of 100 is: 10
```

---

## Weird Integral Types

Looking at some integers, one may find weird

- Example:
  - Suppose we have two `short int` variables
  - If we do an operation on these variables, the result will not be the same type
    - And we can see this, just from the size of the result in comparison to the initial variables
    - In this case, we receive an integer back
  - So, despite the variables being the same type we do not receive the same type back

```c++
short int var1{10}; // 2 Bytes
short int var2{20};

std::cout << "Size of var1: " <<  sizeof(var1) << '\n'; // 2
std::cout << "Size of var2: " <<  sizeof(var2) << '\n'; // 2

auto result1{var1 + var2};

std::cout << "Size of resul1t: " << sizeof(result1) << '\n'; // 4
```

- Why?
  - When we do an operation on the values, the computer processor converts the type
  - The smallest unit with which it can do operations it can do operations is 4 bytes
    - But we are giving it something that contains two bytes
  - So, that is why the computer takes our value type and pads zeros in front to make them a full 4 bytes
    - Since, 4 bytes is the smallest unit it can do operations with
  - That is why the same behavior occurs with any data type that is smaller than 4 bytes.

```c++
char value3{40};
char value4{50};

std::cout << "Size of var3: " << sizeof(var3) << '\n';
std::cout << "Size of var4: " << sizeof(var4) << '\n';

auto result2{var3 + var4};

std::cout << "Size of result2: " << sizeof(result2) << '\n';
```

---

## Data Conversions

### Implicit Conversion in Expressions

- Compiler applies implicit conversion when types are different in an expression
- Conversions are always done from the smallest to the largest type
- Suppose we have an integer as the first operand, and you have a double as the second
  - We want to add both values
  - So what is the resulting data type?
    - In the case below, `int` is transformed to double before the expression is evaluated
    - _Unless we are doing an assignment_

```c++
double price{41.14};
int units{10};

auto total_price{price * units};

std::cout << "Total price: " << total_price << '\n';
std::cout << "sizeof(total_price): " << sizeof(total_price) << '\n';
```

- In C++, when an operation involves two different numeric types
  - The operand of the smaller type is implicitly converted to the larger type before the operation is performed
- This is known as **_type promotion_**
- In the case above, `units` is implicitly converted to `double` before the multiplication
  - So the result of the operation is also a `double`
  - Therefore, `total_price` is deduced to be of type `double`

### Implicit Conversions in Assignment

- Assignment operation is also going to cause an implicit narrowing conversion
- In the example below
  - `y` is converted to `int` before assignment

```c++
int x{};
double y{148.13};

x = y; // double to int

std::cout << "The value of x is: " << x << '\n';
std::cout << "sizeof(x): " << sizeof(x) << '\n';
```

- We are taking a `double` and assigning that to something that is an integer
- For this to occur
  - Compiler is going to have to transform the `double` to an `integer`
  - Before the assignment, since the compiler can't assign things of different types

### Explicit Conversion in Expressions

What if we want to convert variables explicitly, without hoping for the compiler to possibly make the conversion.
One of those facilities is `static_cast<>`

- `static_cast<target-type>(x)`
- Converts between types using a combination of implicit and user-defined conversions
- This command returns a value of `target-type`, i.e., `int, float, double, etc.`
  - For full detail about `static_cast` conversion rules, refer to [CPP Reference](https://www.en.cppreference.com/w/cpp/language/static_cast.html)

```c++
double x{12.5};
double y{34.6};

// Convert then sum
int sum1 = static_cast<int>(x) + static_cast<int>(y);

// Sum then convert
int sum2 = static_cast<int>(x + y);

std::cout << "Sum1 = " << sum1 << '\n';
std::cout << "Sum2 = " << sum2 << '\n';
```

- As shown above, when we choose to cast can cause differing results
  - In the first case
    - We are dropping the decimal points in the values to convert them to `int`
    - But, doing so, results in smaller values
  - In the second case
    - We are summing the values first
    - Retaining data we dropped in the first case
    - Then converting the sum into an `int`
      - Once again, dropping the decimal values

---

## Overflow & Underflow

- Overflow is a phenomenon that happens if you try to go over the range that is available for a data type
- Underflow is a phenomenon that happens if you try to go under the range that is available for a data type
- In C++, data types are allocated with a certain number of bits
  - If a variable takes more bits than it can allocate
    - We may encounter an overflow or underflow
- This is a harmful type of numerical error
- For example
  - A `char` is 1 byte, which is 8 bits in memory
  - So the possible values for an `unsigned char` type is:
    - All `0`'s: `00000000` (Decimal 0)
    - ...
    - All `1`'s: `11111111` (Decimal 255)
  - What happens if we try to store something lower than 0 (negative), or greater than 255?
    - Underflow & Overflow, respectively
    - For Underflow
      - It will try to set the lower value to the `unsigned char`, but since the data type cannot be lower
      - It will reset the value to the maximum value for the data type
    - For Overflow
      - It will try to set the higher value to the `unsigned char`, but since the data type cannot be higher
      - It will reset the value to the minimum value for the data type
- This can be seen in our example below:

```c++
unsigned char data{255};

std::cout << "Data: " << static_cast<int>(data) << '\n';
data++;
std::cout << "Overflow: " << static_cast<int>(data) << '\n';

std::cout << "Reset to data to zero" << '\n';
data = 0;
std::cout << "Data: " << static_cast<int>(data) << '\n';

data--;
std::cout << "Underflow: " << static_cast<int>(data) << '\n';
```

---

The following part cover operations that are going to be manipulating your data at the bit level

## Printing Integers in Binary



Realistically, for the standard printing library in C++, there is no manner of printing in a binary format.
You can control the type of literal you put in your data, as you initialize it. But, `std::cout` falls short on
how we can do this in a binary form. So we introduce a new function that helps to print items in a binary format.
First, we need to include the necessary library to access needed functions

```c++
#include <bitset>

int main() {
  unsigned short int data {15};
  
  std::cout << "Data (dec): " << std::dec << data << '\n';
  std::cout << "Data (hex): " << std::hex << << std::showbase<< data << '\n';
  std::cout << "Data (bin): " << std::bitset<16>(data) << '\n';
  return 0;
}
```

---

## Shift Operators

Shift operators are things you use to move your data left or right, with the data being in binary form.

- Binary bitwise operators
  - Used to shift the bits either left or right of the first operand by the number of positions specified by the second operand
  - Allowing efficient data manipulation
  - `<<`, left shift
    - Is a binary operator that takes two numbers
    - left shifts the bits of the first operand
    - the second operand decides the number of places to shift
      - i.e., left shifting an integer `a` with an integer `b` denoted as `a << b`
      - Which is equivalent to multiplying `a` with $`2^{b}`$
    - Applications of Left Shift Operator
      - Multiplication by Powers of Two
      - Efficient Calculations
      - Bit Manipulation
  - `>>`, right shift
    - Is a binary operator that takes two numbers
    - right shifts the bits of the first operand
    - the second operand decides the number of places to shift
      - i.e., right shifting an integer `a` with an integer `b` denoted as `a >> b`
      - Which is equivalent to dividing `a` with $`2^{b}`$
    - Application of Right Shift Operator
      - Division by Powers of Two
      - Efficient Calculations
      - Bit Manipulation
- **_Important Notes_**
  - **Left-shift and right-shift operators should not be used for negative numbers**
    - Results in undefined behavior, if any of the operands is a negative number
  - **If the number is shifted more than the size of the integer, the behavior is undefined**
    - Results in Overflow in left-shifts and Underflow in right-shift
  - **The left-shift by 1 and right-shift by 1 are equivalent to the product of the first term and 2 to the power given element**
    - i.e., `1 << 3` is equal to `1 * pow(2,3)` and `1 >> 3` is equal to `1 / pow(2,3)`
- Below is an example of bit shifting
  - As stated in the important notes, when we shift more bits than the data type has
  - We lose data (`1`'s), that cannot be recovered, when we shift right

|    Binary Value     | Decimal Value | Note                                    |
|:-------------------:|:--------------|:----------------------------------------|
| 0000 1111 1111 0000 | 4000          | Initial Value                           |
| 0001 1111 1110 0000 | 8160          | Shift left by 1 bit                     |
| 0011 1111 1100 0000 | 16320         | Shift left by 1 bit                     |
| 0111 1111 1000 0000 | 32640         | Shift left by 1 bit                     |
| 1111 1111 0000 0000 | 65280         | Shift left by 1 bit                     |
| 1111 1110 0000 0000 | 65024         | Shift left by 1 bit (truncation occurs) |
| 0111 1111 0000 0000 | 32512         | Shift right by 1 bit                    |
| 0000 0111 1111 0000 | 2032          | Shift right by 4 bit                    |

---

## Logical Bitwise Operators

Logical operators specialized to **_work on each bit in a byte_**

We have the following:
- Bitwise AND (`&`)
  - Works like the logical AND (`&&`)
  - The result will only be `1` if both operands are `1`

| value1 (bit) | value2 (bit) | value1 & value2 |
|--------------|--------------|-----------------|
| 0            | 0            | 0               |
| 0            | 1            | 0               |
| 1            | 0            | 0               |
| 1            | 1            | 1               |

- Bitwise OR (`|`)
  - Works like the logical OR (`||`)
  - The result will only be `1` if either operands are `1`
  - So, we only get `0` if both operands are `0`

| value1 (bit) | value2 (bit) | value1 \| value2 |
|--------------|--------------|------------------|
| 0            | 0            | 0                |
| 0            | 1            | 1                |
| 1            | 0            | 1                |
| 1            | 1            | 1                |

- Bitwise NOT (`~`)
  - Result will be the inverse of original operand
  - So if the operand was `1`, the result will be `0` and vice versa

| value1 (bit) | ~value1 (bit) |
|--------------|---------------|
| 0            | 1             |
| 0            | 1             |
| 1            | 0             |
| 1            | 0             |

- Bitwise XOR (`^`)
- Bitwise OR (`|`)
  - The result will only be `1` if one operand is `1` and other is `0`
  - So, we get `0` if both operands are `0` or `1`, respectively

| value1 (bit) | value2 (bit) | value1 ^ value2 |
|--------------|--------------|-----------------|
| 0            | 0            | 0               |
| 0            | 1            | 1               |
| 1            | 0            | 1               |
| 1            | 1            | 0               |

---

## Compound Bitwise Operators

We will be compounding bitwise and logical operators.
We will be using the compound operator to immediately assign the result into our operand.

```c++
unsigned int sandbox_var{0b00110100};

// Compound Left Shift by 2
sandbox_var <<= 2;
std::cout << std::bitset<32>(sandbox_var) << '\n';

// Compound Right Shift by 4
sandbox_var >>= 4;
std::cout << std::bitset<32>(sandbox_var) << '\n';

// Compound OR with 0000 0010
sandbox_var |= 0b00001111;
std::cout << std::bitset<32>(sandbox_var) << '\n';

// Compound AND with 0000 1100
sandbox_var &= 0b00001100;
std::cout << std::bitset<32>(sandbox_var) << '\n';

// Compound XOR with 0000 0011
sandbox_var &= 0b00000011;
std::cout << std::bitset<32>(sandbox_var) << '\n';
```

---

## Masks

A mask is a sequence of bits, used to highlight or hide a value inside another bit. It is a technique
used in programming to perform operations more efficiently on binary data.

Bit-masking in C++ involves manipulating individual bits of a number to achieve the desired output.
It is achieved by generating a bit mask and doing the following operations:
- **Bit Toggle**: If a bit is set to `0`
  - It can be toggled to `1` and vice versa
- **Bit Setting**: If a bit is set to `0` then it's called 'bit is NOT set'
  - We can change it to `0` by performing a toggle operation this is called a 'Bit-clearing' operation
- **Checking specific bit is on or off**: A bit is said to be on if it is `1` and off it is `0`

Bit mask is the fundamental technique to achieve bit-masking.
It is basically a binary pattern used to perform various bit-level operations.
The mask is created in the following ways:
_Assuming we have the set of numbers, whose binary representation has 8 bits in it_

```text
// Focusing on right-most (least significant) bit
mask example: 0000 0001
```

- The mask above will only manipulate the bit in the right-most position
- But realistically, the mask can be used to manipulate any bit we want

```c++
constexpr unsigned int mask_bit_0{ 0b00000001 }; // bit 0
constexpr unsigned int mask_bit_1{ 0b00000010 }; // bit 1
constexpr unsigned int mask_bit_2{ 0b00000100 }; // bit 2
constexpr unsigned int mask_bit_3{ 0b00001000 }; // bit 3
constexpr unsigned int mask_bit_4{ 0b00010000 }; // bit 4
constexpr unsigned int mask_bit_5{ 0b00100000 }; // bit 5
constexpr unsigned int mask_bit_6{ 0b01000000 }; // bit 6
constexpr unsigned int mask_bit_7{ 0b10000000 }; // bit 7
```

Bit-masking is done by creating a bit mask for the operation that we need to perform.
This bit mask will then be followed by a bitwise operation to achieve the desired output.

### Setting a Specific Bit

Setting a specific bit basically means changing it from `0` to `1`.
Achieved by utilizing the Bitwise OR and Bitwise Left Shift.
We use bitwise OR for its property to give `1` if either of the bits is set to `1`.
So, we will shift the bit of `1` to the specified position that we want to set and then perform a bitwise OR operation.

```text
//Option 1
integer | (1 << bit_position_to_be_set)

// Option 2
unsigned int mask_position_to_set{0b00000001}
integer | mask_position_to_be_set
```

### Resetting Bits

Clearing/Resetting a bit means we set the bit to `0`, if it is `1`. 
Without touching or affecting any other bit.
This is done by using Bitwise AND and the negation operator (Bitwise NOT).
Bitwise NOT flips all the bits that are `1` to `0` and `0` to `1`.
Which helps us in clearing a set bit.

```text
//Option 1
integer & ~(1 << bit_position_to_be_clear)

// Option 2
unsigned int mask_position_to_clear{0b00000001}
integer & ~mask_position_to_be_set
```

### Toggle A Bit

Toggling a bit is where we flip a bit.
If a bit is set to `1`, we set it to `0`.
If a bit is set to `0`, we set it to `1`.
We achieve this by the Bitwise XOR and the Bitwise Left Shift.
Utilizing the property of the XOR operator to flip the bits, given that the bits of 2 different numbers are not the same.

```text
// Option 1
integer ^ (1 << bit_position_to_be_toggle)

// Option 2
unsigned int mask_position_to_toggle {0b}
integer ^ mask_position_to_toggle
```

### Checking if a Bit is a Set or Not

Check if a bit at a specific position is set or not.
This is done by using the Bitwise AND and Bitwise Left Shift.
We are essentially left shifting the set bit of `1` to the specified position for which we want to perform a check.
Then perform a Bitwise AND.
If the bit is set, then the answer will be: $`2^{\text{Bit_Position}}`$.
---