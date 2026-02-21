# Sequences

We will be exploring different collection types that
C++ provides.

---

## Topics

- `std::array`
    - Using `[]` v.s. `at()`
    - Range-based looping
    - Modifying elements
    - `fill()`
    - More Element Access:
        - `front`
        - `back`
    - Two Dimensional Arrays
    - Comparing Arrays
- `std::vector`
    - Access data in vector
        - `[]`
        - `at()`
    - Differences Between `std::array` & `std::vector`
    - Filling vector
    - Accessing First & Last Element
    - Multi-Dimensional Vectors
    - Lexicographical Comparison
    - Assignment
- `std::string`
    - Basic declaration & Initialization
    - Using Constructors
    - Accessing Characters
    - Modifying Strings
    - Appending and Concatenation
    - Substrings
    - Finding
    - Comparison
    - Inserting & Erasing
    - Length & Capacity
    - Iterating over a String
    - Clearing a string
- Raw Arrays
  - Computer Memory
    - Stack
    - Heap
  - Declaration and initialization
  - Size of an array
  - Array of `char`
  - Array bounds
  - Random Number Generation (Old Method)
  - Random Number Generation (Modern C++)
  - Multidimensional array
  - Multidimensional array of `char`

---

## `std::array`

`std::array` is a good choice if you **_know_** the size of the
container.

For example, we know the number of students in class,
and want to store the names of each student. We can make a
`std::array` of desired size to store our list of names.

Some benefits of using `std::array` are:

- Each collection knows its size
- Easy to pass to functions
    - Since the size does not need to be included separately
- Convenient functions to get:
    - First Element
    - Last Element
- Can be compared using comparison operators
- Can assign a `std::array` to another `std::array`
- Can store an `std::array` in another container
- Don't have to mess with low lever arrays and pointers

To start off, let us look at an example in declaring an array.

```c++
// Declaration and init 
std::array<int, 5> arr{1, 2, 3, 4, 5};
```

- Notice that we have to declare two parameters:
    - The data type of the information contained
        - _Remember we cannot mix data types_
    - Array size

Once done we would be able to use the `std::array`.
We are now able to access the information contained in our
array, given we added data. We can access this information
in one of two ways:

### Using `[]` (square brackets):

```c++
// Accessing elements using []
for (size_t i = 0; i < arr.size(); ++i) {
    fmt::println("arr[{}] = {}", i, arr[i]);
}
```

In our `for` loop we can see another benefit of `std::array`.
We can obtain the `size` of the array using the called function:
`.size()`. So we do not have to maintain a separate variable for the
array's size.

- We will loop through the array
    - Then access elements in the array using square brackets
    - Printing out each value
    - Along with the current iteration count

### Using `.at()`

```c++
for (size_t i = 0; i < arr.size(); ++i) {
    fmt::println("arr.at({}) = {}", i, arr.at(i));
}
```

In the other method, we utilize another function of `std::array`.
Using `.at()` to call certain elements, like the brackets.
Again, we will:

- Loop through the array
    - Access elements in the array using `.at()`
    - Print each value
    - Along with the current iteration count

With the `.at()` function, we are essentially stating that we
want to print the element at `i` index.

### Difference between `[]` and `.at()`

The `.at()` notation is going to warn you or throw an error if you
happen to go out of bounds. While `[]` bracket notation will **not** be
bound-checking.

Using our previous examples, we modify the code to use an `i` that exceeds
our `std::array` size:

```c++
fmt::println("arr[{}] = {}", i, arr[10]);
```

Which results in the following output:

```shell
/usr/lib/gcc/x86_64-alpine-linux-musl/15.2.0/../../../../include/c++/15.2.0/array:210: reference std::array<int, 5>::operator[](size_type) [_Tp = int, _Nm = 5]: Assertion '__n < this->size()' failed.

Process finished with exit code 139
```

While doing the same modification to our `.at()` example:

```c++
fmt::println("arr.at({}) = {}", i, arr.at(10));
```

We obtain the following output:

```shell
terminate called after throwing an instance of 'std::out_of_range'
  what():  array::at: __n (which is 10) >= _Nm (which is 5)

Process finished with exit code 139
```

So, using an out-of-bounds index with `[]` square brackets
results in undefined behavior.

While using an out-of-bounds index with `.at()` results in a
`std::out_of_range` exception being thrown. So, we can catch
such and error and handle it.

**However, the cost of bounds checking does affect the performance
when calling a value.**

### Range-based loop

We can also utilize the range-based `for` loop format to iterate
through an `std::array`.

```c++
for (const auto &element: arr) {
    fmt::println("{}", element);
}
```

### Modifying elements

To modify elements in our `std::array`, we would do the following:

```c++
arr[0] = 10;
arr.at(1) = 20;
```

Similar to how we printed our array, we state the index (with-in bounds)
that we want to modify. Again, we can use either square brackets `[]` or
the `.at()` function.

### Filling `std::array`

We can also fill a `std::array` with a value. Using the `.fill()` function.

```c++
std::array<int, 5> arr2{};
arr2.fill(7);
```

In the example above, we declare a `std::array` that is initialized with `0`'s.
Then, utilizing the `.fill()` function, fill the container with our specified
value of `7`. So, all elements will have the value of `7`.

When printed results in the following:

```shell
Printing Filled Array:
7
7
7
7
7
```

### More Element Access

We have two other member functions to access data in a `std::array`.

1. `front()`
    - This member function will return the first element in the `std::array`
2. `back()`
    - This member function will return the last element in the `std::array`

Example below:

```c++
fmt::println("arr.front() = {}", arr.front());
fmt::println("arr2.front() = {}", arr2.front());

fmt::println("arr.back() = {}", arr.back());
fmt::println("arr2.back() = {}", arr2.back());
```

Which prints the following:

```shell
arr.front() = 10
arr2.front() = 7
arr.back() = 5
arr2.back() = 7
```

### Two Dimensional Arrays

Now, we can also set up a 2D array. So far, we have only worked with
simple one dimensional arrays. Great for data collections that we know
the size of.

Example below:

```c++
constexpr std::array<std::array<int, 2>, 3> arr3{{ {1, 2}, {3, 4}, {5,6} }};

for (const auto& row : arr3) {
    for (const auto& col : row) {
        fmt::print("{} ", col);
    }
    fmt::println("");
}
```

For the printing section, notice how we access the elements in the array.
We first access each "row" within `arr3`. Then, within each row,
we access a "column"/element. That's how we access each individual
element in a 2D array.

Which prints the following:

```shell
1 2 
3 4 
5 6 
```

### Comparing Arrays

What if we want to compare two or more different arrays.
First we define a set of arrays to test:

```c++
std::array<int, 3> arr4{1, 2, 3};
std::array<int, 3> arr5{1, 2, 3};
std::array<int, 3> arr6{1, 2, 4};
std::array<int, 3> arr7{0, 2, 4};
```

_**We also want to take note that on [cpp reference](https://en.cppreference.com/w/cpp/container/array.html)
in the information for `std::array`. It has been noted that some operators, we will be using in our
example, have been removed. So its best not to use them despite a compiler working — if using
newer versions of C++.**_

#### Comparing for Equality

```c++
fmt::println("Comparing for equality:");
if (arr4 == arr5) {
    fmt::println("arr4 is equal to arr5");
} else {
    fmt::println("arr4 is not equal to arr5");
}
```

#### Comparing for Inequality

```c++
if (arr4 != arr6) {
    fmt::println("arr4 is not equal to arr6");
} else {
    fmt::println("arr4 is equal to arr6");
}
```

#### Lexicographical Comparison

##### Less than (<)

```c++
if (arr4 < arr6) {
    fmt::println("arr4 is less than arr6");
} else {
    fmt::println("arr4 is not less than arr6");
}
```

##### Less than or equal to (≤)

```c++
if (arr4 <= arr5) {
    fmt::println("arr4 is less than or equal to arr5");
} else {
    fmt::println("arr4 is not less than or equal to arr5");
}
```

##### Greater than (>)

```c++
if (arr6 > arr7) {
    fmt::println("arr6 is greater than arr7");
} else {
    fmt::println("arr6 is not greater than arr7");
}
```

##### Greater than or equal to (>=)

```c++
if (arr6 >= arr4) {
    fmt::println("arr6 is greater than or equal to arr4");
} else {
    fmt::println("arr6 is not greater than or equal to arr4");
}
```

## `std::vector`

This is a good alternative to the `std::array` type. There are clear
differences, but still similar.

To start off, let us look at an example in declaring an array.

```c++
// Declaration and init 
std::vector<int> vec{1, 2, 3, 4, 5};
```

- Notice that we have to declare **_only_** one parameter:
    - The data type of the information contained
        - _Remember we cannot mix data types_

Once done we would be able to use the `std::vector`.
We are now able to access the information contained in our
array, given we added data. We can access this information
in one of two ways:

### Using `[]` (square brackets):

```c++
// Accessing elements using []
for (size_t i = 0; i < vec.size(); ++i) {
    fmt::println("vec[{}] = {}", i, vec[i]);
}
```

In our `for` loop we can see another benefit of `std::vector`.
We can obtain the `size` of the vector using the called function:
`size()`. So we do not have to maintain a separate variable for the
vector's size.

- We will loop through the vector
    - Then access elements in the vector using square brackets
    - Printing out each value
    - Along with the current iteration count

### Using `at()`

```c++
for (size_t i = 0; i < vec.size(); ++i) {
    fmt::println("vec.at({}) = {}", i, vec.at(i));
}
```

In the other method, we utilize another function of `std::vector`.
Using `at()` to call certain elements, like the brackets.
Again, we will:

- Loop through the vector
    - Access elements in the array using `at()`
    - Print each value
    - Along with the current iteration count

With the `at()` function, we are essentially stating that we
want to print the element at `i` index.

### Differences Between `std::array` & `std::vector`

**Let us focus on the differences present in `std::vector`**

| `std::array`                                                                                                                 | `std::vector`                                                                                                                |
|------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------|
| Fixed Size:<br/>The size of `std::array` is fixed at compile time and cannot be changed                                      | Dynamic Size:<br/>The size of `std::vector` can be changed at runtime; it can grow and shrink dynamically                    |
| Memory Allocation:<br/>Allocates memeory on the stack                                                                        | Memory Allocation:<br/>Allocates memory on the heap                                                                          |
| Performance:<br/>Generally faster access due to stack allocation and no need for dynamic memory allocation                   | Performance:<br/>Slightly slower access due to dynamic memory allocation and potential reallocations                         |
| Initialization:<br/>Can be initialized with a list of values                                                                 | Initialization:<br/>Can be initialized witha list of values, default constructor, or by specifying the size                  |
| Bound-Checking:<br/>Provides `.at()` method for bound-checking access; out-of-bounds access using `[]` is undefined behavior | Bound-Checking:<br/>Provides `.at()` method for bound-checking access; out-of-bounds access using `[]` is undefined behavior |
| Usage:<br/>Suitable for fixed-sized collections where the size is known at compile-time                                      | Usage:<br/>Suitable for collections where the size can vary or is not known at compile time.                                 |
| Syntax:<br/>Requires specifying the size as a template parameter: `std::array<int, 5>`                                       | Syntax:<br/>Does not require specifying the size as a template parameter: `std::vector<int>`                                 |
| Iterators:<br/>Supports iterators for range-based loops and standard algorithms                                              | Iterators:<br/>Supports iterators for range-based loops and standard algorithms                                              |
| Assignment:<br/>Supports direct assignment from another `std::array` of the same type and size                               | Assignment:<br/>Supports direct assignment from another `std::vector` of the same type                                       |
| Comparison:<br/>Supports comparison operators `(==, !=, <, <=, >, >=)`                                                       | Comparison:<br/>Supports comparison operators `(==, !=, <, <=, >, >=)`                                                       |

### Filling Vector

One other difference would be the lack of a member function `fill()`.
`std::vector` does not have a built-in function to fill our vector.
To fill, we utilize other C++ features to replicate the action.
In this case, we utilize `std::fill()`, located in the `<algorithm>` library.

Example below:

```c++
// Declaring a vector with initial length 5
std::vector<int> vec(5);

// Filling vector with a single value
std::fill(vec.begin(), vec.end(), 7);
```

- Here we are just filling in the parameters:
    - `first`
    - `last`
        - The pair of iterators defining the range of elements to modify
    - `value`
        - The value to be assigned

The key difference is that `std::fill` can be used with any container.

### Accessing First & Last Elements

The container provides member functions that allow us to access the first or
last element available.

Example:

```c++
std::vector<int> vec{1, 2, 3, 4, 5, 6, 7};

std::println("First element: {}", vec.front());
std::println("Last element: {}", vec.back());
```

- `front()`: returns the first element in the container
- `back()`: returns the last element in the container

### Multi-Dimensional Vectors

First off, we set up a `std::vector` containing another `std::vector`,
of a desired type.

```c++
std::vector<std::vector<int>> vec {{1, 2}, {3, 4}, {5, 6}};

for (const auto& row : vec)
{
    for (const auto& col : row)
    {
        std::print("{} ", col);
    }
    std::println("");
}
```

### Lexicographical Comparison

Similar to `std::array`'s we can do Lexicographical Comparisons. But for sake
of repetitiveness, I will just skip the examples.

### Assignment

We can also assign one `std::vector` to another `std::vector`.

```c++
std::vector<int> vec1 {1, 2, 3, 4};
std::vector<int> vec2 {5, 5, 6, 7};

vec2 = vec1;
```

---

## `std::string`

`std::string` is another collection type. While many do not think of
strings as a collection type, it is since it's a collection of `char`
data. We can think of `std::string` as a vector. Due to sharing many
behaviors with `std::vector`.

### `std::string` compared to `std::array` & `std::vector`

| Feature                 | `std::vector<T>`                          | `std::array<T, n>`              | `std::string`                               |
|-------------------------|-------------------------------------------|---------------------------------|---------------------------------------------|
| Memory Layout           | Dynamic (Heap)                            | Fixed size (stack or embedded)  | Dynamic (Heap)                              |
| Resizable               | Yes (automatic resizing)                  | No (fixed size)                 | Yes (automatic resizing)                    |
| Element Type            | Generic (`T` can be any type)             | Generic (`T` can be any type)   | Only `char` ot `wchar_t` (text data)        |
| Insertion Complexity    | `O(1)` at end, `O(n)` elsewhere           | N/A (Fixed Size)                | `O(1)` at end, `O(n)` elsewhere             |
| Access Time             | `O(1)` Random access                      | `O(1)` Random access            | `O(1)` Random access                        |
| Memory Efficeny         | Efficent, but may over-allocate           | Most efficent (fixed size)      | Efficent, but may over-allocate             |
| Best for                | Dynamic arrays of any type                | Fixed-size arrays               | Handling and manipulating text              |
| Supports Move Semantics | Yes                                       | Yes                             | Yes                                         |
| Thread Safety           | Not thread-safe                           | Not thread-safe                 | Not thread-safe                             |
| Contiguous Mmemory      | Yes                                       | Yes                             | Yes                                         |
| Iterator Invalidations  | Invalidation on reallocation or insertion | N/A                             | Invalidation on reallocation or insertion   |
| Default initializations | Elements are default-initialized          | Must be initialized with values | N/A (initialized to empty string by default |
| Speacial Functions      | `resize`, `push_back`, `pop_back`         | N/A (fixed size, no resizing)   | `append`, `substr`, `find`, `replace`       |
| Best for String Use     | Not ideal (stores generic types)          | Not applicable                  | Specifically designed for strings           |

### Basic Declaration & Initialization

Example:

```c++
// Assign to initialize
std::string str1 = "Hello World!";
std::println("str1: {}", str1);

// Curly Initialization
std::string str2{"Hello World!"};
std::println("str2: {}", str2);
```

- Following previous data types, declaring a `std::string` we:
    - State the data type we will store
    - Give the variable a name
- To initialize, we:
    - Either assign a collection of characters
    - Or, use curly braces, passing a string of characters

### Using Constructors

```c++
// Creating a std::string using various constructors
std::string str2(str1);          // Copy constructor
std::string str3(str1, 7, 5);   // Substring constructor
std::string str4(10, 'A');      // Fill constructor
```

In the example above, we are using various constructors to make new strings.

- For `str2`
  - We use the copy constructor
    - Where we use parentheses and pass a `std::string` to copy
- For `str3`
  - We use the sub-string constructor
    - Passing a `std::string`
    - An index for the passed `std::string` where to start copying
    - Length of how much we want to copy
- For `str4`
  - Using fill constructor
    - Length of the new `std::string`
    - Character we want to fill our `std::string` with

### Accessing Characters

```c++
// Accessing individual characters using the [] operator and at() method
std::println("Accessing Elements in a string:");
std::println("First character of str1 using []: {}", str1[0]);
std::println("Second character of str1 using at(): {}", str1.at(1));
std::println("");
```

Notice we can utilize the two accessing methods similar to `std::vector`
and `std::array`. With the same behaviors as previously stated.

### Modifying Strings

```c++
// Modifying characters in the string
std::println("Modifying Elements in a string:");
str1[0] = 't';
std::println("Modified str1 using []: {}", str1);
str1.at(7) = 'w';
std::println("Modified str1 using at(): {}", str1);
std::println("");
```

We can utilize both methods of accessing data to modify our `std::string`.

### Appending and Concatenation

```c++
// Appending
str1 += " How are you?";
str2.append(" Goodbye!");
std::println("Appended str1: {}", str1);
std::println("Appended str2: {}", str2);

// Concatenation
str3 = "How are you.";
std::string str5 = str3 + " Everyone!";
fmt::println("Concatenated str5: {}", str5);
```

- Looking at `str1`
  - We do `+=` to `str1`
  - This makes `str1` contain the original data plus the new data
  - **This works because the operator is defined into the `std::string` type**
    - We can verify this looking at our C++ Reference
- Looking at `str2`
  - We utilize the `append()` function
  - This appends to the string
    - Adding additional characters to the string
- The initialization of `str5` is a concatenation
  - With `str5` being an entirely new object containing the combined data of:
    - `str3` and `"Everyone!"`
- With the main difference between **appending** and **concatenation** being:
  - Appending:
    - Usually modifies the original object in-place
  - Concatenation:
    - Typically, creates an entirely new object containing combined data
    - So, original objects are unchanged
- With this in mind
  - The modification of `str1` is actually a concatenation

### Substrings

```c++
std::string subStr = str1.substr(7, 5);
```

Fairly straightforward, if we have a `std::string` containing a string,
we can grab a substring of the original and do whatever we want.

In the example above:
- We use `str1`, containing `"tello Wwrld! How are you?"`
  - Utilizing the `substr()` function we declare two parameters
    - `7`, the starting index
      - Where we want to begin the new string we will be making
    - `5`, the length of the string

### Finding

```c++
size_t pos = str2.find("World");

if (pos != std::string::npos) {
    fmt::println("'World' found at position: {}", pos);
} else {
    fmt::println("'World' not found");
}
```

This example does not seem straightforward, but it is.
The `find()` function does not check if our desired substring,
`"World"`, exist. `find()` finds the first substring equal to the given
parameter, then and returns the first character of the found substring
or `npos` if no such substring is found.

- `size_t pos` is an unsigned integer variable with name `pos`
  - We look for the first instance of our desired substring
  - If found we assign the first character's position (index) to `pos`
  - Otherwise, `npos` is assigned to `pos`
    - With `npos` simply being a special value
      - Which is equal to the maximum value representable by the type `size_type`
      - For more information look at [CPP Reference](https://en.cppreference.com/w/cpp/string/basic_string/npos.html)
- We then use an `if` statement to check our `pos` variable
  - We have to explicitly compare our `pos` variable with the defined `npos`
  - Which we do by using `std::string::npos`

### Comparison

```c++
std::string str6 {"Hello"};
std::string str7 {"World"};

if (str6.compare(str7) == 0) {
    fmt::println("str6 is equal to str7");
} else {
    fmt::println("str6 is not equal to str7");
}

if(str6.compare(str7) > 0){
    fmt::println("str6 is greater");
}else{
    fmt::println("str7 is greater");
}
```

We can compare strings. Utilizing the `compare()` function in the
`std::string` class/type. Specifically, it compares two character sequences,
i.e., strings.

It returns a negative value if `*this` appears before the character sequence
specified by the arguments, in lexicographical order. Or, returns zero if 
both character sequences compare equivalent. Or, returns positive if `*this` appears
after the character sequence specified by the argument, in lexicographical order.

- We define two variables `str6` and `str7`
  - Initialized with strings
- We define an `if` statement
  - We compare `str6` to `str7` using `compare()` function
  - The result is then checked
    - In the first `if` statement
      - We check if the result is `0`
    - In the second `if` statement
      - We check if the result is greater than `0`

We can also do the following rather than using the `compare()` function.

```c++
    if (str6 == str7) {
        fmt::println("str6 is equal to str7");
    } else {
        fmt::println("str6 is not equal to str7");
    }

    if(str6 > str7){
        fmt::println("str6 is greater");
    }else{
        fmt::println("str7 is greater");
    }
```

Running either example will result in the following output:

```shell
str6 is not equal to str7
str7 is greater
```

One may wonder why `str6` is not greater than `str7` despite the 
length of each being the same and `H` coming before `W`. This is
due to the ASCII code for `W` being larger than `H`. Thus, resulting
as such.

### Inserting & Erasing

How do we insert into a `std::string`. We would utilize the `insert()`
function, that is defined in the `string` library.

```c++
str6.insert(5, ", Beautiful");
```

We utilize the `str6` we defined for our comparison example.

- We utilize the `insert()` function
  - We add the following parameters
    - `5` is the index we want to begin inserting
    - `", Beautiful"` is the `char`'s we want to insert

The following is a visual example of what would occur:

```shell
Before insertion: Hello
After insertion: Hello, Beautiful
```

For erasing, a similar process is followed. We would utilize the `erase()`
function, that is defined in the `string` library.

```c++
str6.erase(5, 11);
```

- Utilizing the `erase()` 
  - We add the following parameters:
    - `5` is the index we want to begin erasing
    - `11` is the number of characters we want to erase

Which results in the following:

```shell
Before erasing: Hello, Beautiful
After erasing: Hello
```

### Length & Capacity

Now we want to get the length and capacity of a string. Again, this
is fairly simple. We use the respectively defined functions `length()` or `size()` and
`capacity()`.

```c++
std::println("Length of str6: {}", str6.length());
std::println("Size of str6: {}", str6.size());
```

We can utilize either `length()` or `size()` to obtain the length
of a string. In the example above:

- `size()` and `length()` return the number of `char` elements in the string
  - Of `size_type`
- Thus, we print the result from using the respective functions

Capacity on the other hand, is the allocated space for the string variable.

```c++
std::println("Capacity of str6: {}", str6.capacity());
```

In the example above:

- `capacity()` returns the number of characters that the string has currently allocated space for
  - Of `size_type`
- Thus, we print the result from using the `capacity()` function

### Iterating over a String

We can also iterate over a string. A simple example is using the
range-based `for` loops:

```c++
std::println("Characters in str6: ");
for (const auto& ch : str6) {
    std::print("{} ", ch);
}
```

### Clearing a string

To clear a string we utilize the `clear` function defined for 
`string`. This function removes all characters from the string.

```c++
str6.clear()
std::println("Cleared str6, new length: {}", str6.length());
std::println("{}", str6.empty() ? "empty" : "not empty");
```

- In the example
- We are calling the clear function
- Then using a print statement
  - To verify that `str6` is empty
    - We call the `length()` function
    - To make sure the length of the `str6` is `0`
- We can also use a different method
  - Where we call the `empty()` function
  - Depending on the result we print the following
    - If empty:
      - `"empty"`
    - Else:
      - `"not empty"`

The example above results in the following:

```shell
Cleared str6, new length: 0
empty
```

An interesting thing to note. Unlike other clearing functions
defined within C++. The function `clear()` for strings are not
explicitly required that `capacity` be changed when clearing.
The C++ standard does not explicitly require that `capacity` is
unchanged by this function.


Meaning, the capacity, or allocated space, for the variable remains
the same despite removing all existing characters.

The example below is a quick showcase of that:

```c++
std::println("Capacity of str6 before clearing: {}", str6.capacity());
str6.clear();
std::println("Capacity of str6 after clearing: {}", str6.capacity());
```

Which would result in the following output:

```shell
Capacity of str6 before clearing: 30
Capacity of str6 after clearing: 30
```

**I would like for it to be known that all previous sections have so much more depth to them.
What I am doing is simply learning the general information first, then diving further into more
complex subsections/applications.**

---

## Raw Arrays

**_In Modern C++, it is generally not recommended to use raw arrays due to their limitations and
potential safety risks. Instead, one should prefer standard library containers like `std::vector`,
`std::array`, or other container types, as they provide better safety, flexibility and ease of 
use._**

A raw array is a construct that allows you to store collections of data.
A raw array is a very low-level tool in C++. Raw arrays are the lowest form to put information
in the computer, mapping directly to the data that we have in memory.

Side note: "low-level"/"lowest" simply signifies writing code with little to no abstraction
from a computer's physical hardware, operating directly on processor instruction and memory.

So, tools like `std::vector` and `std::array` are higher-level tools, because they are 
abstractions that simplify the process of storing data and manipulating said data.

We have seen that arrays are collections of data. Raw arrays are going to be using data on the
_stack_.

### Computer Memory

The following will be some notes on the **Stack** and **Heap**. These are the two distinct regions of 
computer memory used during program runtime. Which we so far have worked with, but have not explicitly
defined.

### Stack

The stack is linear. The data that comes in last, leaves first.

Memory management is automatic. Memory is allocated and deallocated when functions are called/return.
Stack memory is stored in contiguous blocks and is assigned much larger memory addresses in descending
order.

Known to be faster, but a limited size is available. Thus, we are not able to use so much of it. When
we do overuse the stack, it results in a "stack overflow".

This region of computer memory stores local variables, function parameters, and return addresses.

Overall, the stack is safe, and an inexpensive option to store the memory, but is limited to the local
scope and is fixed in size, which may lead to shortage problems.


### Heap


#### Declaration & Initialization

We will be declaring a raw array, which is going to be using the stack.

```c++
constexpr size_t array_size {5};
int scores[array_size];
```

- The first thing we specify is the `size` of the array
  - Which is `size_t`
    - To keep track of the length/size of our array
  - The `size` is also `constexpr`
    - Since it is good practice
- We now declare our array
  - Like always, we declare the data type
  - Give the array a name
  - Followed by square brackets
    - With the `size` variable in between the brackets
- Once the line is executed
  - An array will be allocated in memory
  - Recalling the byte size of an integer (4 bytes)
    - The array will be 20 bytes in total
- 
