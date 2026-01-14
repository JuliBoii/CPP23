# Sequences

We will be exploring different collection types that
C++ provides.

---

## Topics

- `std::array`
    - Using `[]` v.s. `.at()`
    - Range-based looping
    - Modifying elements
    - `.fill()`
    - More Element Access:
        - `front`
        - `back`
    - Two Dimensional Arrays
    - Comparing Arrays
- `std::vector`
- `std::string`

---

## `std::array`

`std::array` is a good choice if you **_know_** the size of the
container.

For example, we know the number of students in class,
and want to store the names of each student. We can make a
`std::array` of desired size to store our list of names.

Some of the benefits of using `std::array` are:

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
We are able to obtain the `size` of the array using the called function:
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

_**We also want to take note that on [cppreference](https://en.cppreference.com/w/cpp/container/array.html)
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

##### Less than or equal to (<=)

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

###