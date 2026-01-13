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
- `std::vector`
- `std::string`

---

## `std::array`

`std::array` is a good choice if you **_know_** the size of the
container.

For example, we know the number of students in class,
and want to store the names of each student. We can make a
`std::array` of desired size to store our list of names.

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
2. `back()`