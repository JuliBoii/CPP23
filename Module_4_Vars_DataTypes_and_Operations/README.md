# Variables, Data Types & Basic Operations

---

## Overview

- Exploring variables and data types
- Topics
    - Number systems for integers
        - Decimal, Octal, Hexadecimal and Binary
    - Data representation in memory
        - Integers, Floating point types
    - Type ranges for ints & floats

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

- Examples:
  - Given: `100101`

\begin{align}
37 &= 1*2^5 + 0*2^4 + 0*2^3 + 1*2^2 + 0*2^1 + 1*2^0 \\
37 &= 32 + 0 + 0 + 4 + 0 + 1
\end{align}

- Given: `10010`

  $$1*2^4 + 0*2^3 + 0*2^2 + 1*2^1 + 0*2^0$$
  $$= 16 + 0 + 0 + 2 + 0$$
  $$= 18 $$
  
- Given: `111`

  $$1*2^2 + 1*2^1 + 1*2^0$$
  $$= 4 + 2 + 1$$
  $$= 7 $$
  
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
      
        $$0110 \rightarrow 6$$ 
        $$1110 \rightarrow E$$
        $$0011 \rightarrow 3$$
        $$0000 \rightarrow 0$$
        $$1111 \rightarrow F$$
        $$0001 \rightarrow 1$$
        $$0011 \rightarrow 3$$
        $$1111 \rightarrow F$$
      
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
 
        $$01 \rightarrow 1$$
        $$101 \rightarrow 5$$
        $$110 \rightarrow 6$$
        $$001 \rightarrow 1$$
        $$100 \rightarrow 4$$
        $$001 \rightarrow 1$$
        $$111 \rightarrow 7$$
        $$000 \rightarrow 0$$
        $$100 \rightarrow 4$$
        $$111 \rightarrow 7$$
        $$111 \rightarrow 7$$
    - Which we format in Octal with the prefix `0`
      - followed by the number
    - `0 15614170477`

[Use this page for a sample table converting between Binary, Decimal, & Hexadecimal](https://servicenow.iu.edu/kb?id=kb_article_view&sysparm_article=KB0026046)

---

## Data Representation

- Now that we know how data is represented in memory
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

### Memory Representation

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
