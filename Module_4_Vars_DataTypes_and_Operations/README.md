# Variables, Data Types & Basic Operations

---

## Overview

Part 1

- Exploring variables and data types
- Topics
  - Number systems for integers
    - Decimal, Octal, Hexadecimal and Binary
  - Data representation in memory
    - Integers, Floating point types
  - Type ranges for ints & floats

Part 2

- Integer Modifies, Characters, Text, & `auto`
- Topics
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
  - `auto`
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
-2^{n-1} ~ 2^{n-1}-1
```

- `n` is the number of bits for a type in memory

### Unsigned

- Modifier makes sure a variable can **_only_** store positive values
  - If you attempt to store negative values, the compiler will throw an error
- The range of values they can store is:

```math
0 ~ 2^{n}-1
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

## Fractional Numbers