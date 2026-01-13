# Sequences

We will be exploring different collection types that
C++ provides.

---

## Topics

- `std::array`
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

Using `[]` (square brackets):

```c++
// Accessing elements using []
for (size_t i = 0; i < arr.size(); ++i)
{
    fmt::println("arr[{}] = {}", i, arr[i]);
}
```

In our `for` loop we can see another benefit of `std::array`. 
We are able to obtain the `size` of the array using the function:
`.size()`.