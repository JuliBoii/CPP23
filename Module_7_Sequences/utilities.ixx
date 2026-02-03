module;

#include <fmt/format.h>
#include <array>
#include <vector>
#include <algorithm>
#include <ranges>

export module utilities;

export void std_array_example() {
    fmt::println("Example of std::array:");

    // Declaration and init
    std::array<int, 5> arr{1, 2, 3, 4, 5};

    fmt::println("Using Square Brackets [] With std::array:");
    // Accessing elements using []
    for (size_t i = 0; i < arr.size(); ++i) {
        fmt::println("arr[{}] = {}", i, arr[i]);
    }
    fmt::println("");

    fmt::println("Using Range-based for Loops With std::array:");
    // Use range based for loop
    for (const auto &element: arr) {
        fmt::println("{}", element);
    }
    fmt::println("");

    fmt::println("Using .at() With std::array:");
    // Accessing elements using at()
    for (size_t i = 0; i < arr.size(); ++i) {
        fmt::println("arr.at({}) = {}", i, arr.at(i));
    }
    fmt::println("");

    fmt::println("Modifying Elements In Our Array:");
    //Modifying elements in the array
    arr[0] = 10;
    arr.at(1) = 20;
    fmt::println("arr[0] = 10");
    fmt::println("arr.at(1) = 20");
    fmt::println("");

    fmt::println("Printing Modified Array:");
    // Printing modified array
    for (const auto &element: arr) {
        fmt::println("{}", element);
    }
    fmt::println("");

    fmt::println("Filling An Array With A Value:");
    fmt::println("Declare an empty array (arr2)");
    std::array<int, 5> arr2{};
    fmt::println("Filling An Array With a Single Value (7):");
    // Filling array with a single value
    arr2.fill(7);
    fmt::println("");

    fmt::println("Printing Filled Array:");
    // Printing filled array
    for (const auto &element: arr2) {
        fmt::println("{}", element);
    }
    fmt::println("");

    fmt::println("Printing the First Element in An Array");
    fmt::println("arr.front() = {}", arr.front());
    fmt::println("arr2.front() = {}", arr2.front());
    fmt::println("");

    fmt::println("Printing the Last Element in An Array");
    fmt::println("arr.back() = {}", arr.back());
    fmt::println("arr2.back() = {}", arr2.back());
    fmt::println("");

    fmt::println("Making 2D Arrays:");
    constexpr std::array<std::array<int, 2>, 3> arr3{{ {1, 2}, {3, 4}, {5,6} }};

    fmt::println("Printing 2D Array:");
    for (const auto& row : arr3) {
        for (const auto& col : row) {
            fmt::print("{} ", col);
        }
        fmt::println("");
    }

    fmt::println("Comparing Arrays:");
    std::array<int, 3> arr4{1, 2, 3};
    std::array<int, 3> arr5{1, 2, 3};
    std::array<int, 3> arr6{1, 2, 4};

    // Comparing for equality
    fmt::println("Comparing for equality:");
    if (arr4 == arr5)
    {
        fmt::println("arr4 is equal to arr5");
    } else
    {
        fmt::println("arr4 is not equal to arr5");
    }
    fmt::println("");

    // Comparing for inequality
    fmt::println("Comparing for inequality:");
    if (arr4 != arr6)
    {
        fmt::println("arr4 is not equal to arr6");
    } else
    {
        fmt::println("arr4 is equal to arr6");
    }
    fmt::println("");

    //Lexicographical comparison
    fmt::println("Lexicographical array comparison:");
    if (arr4 < arr6)
    {
        fmt::println("arr4 is less than arr6");
    } else
    {
        fmt::println("arr4 is not less than arr6");
    }
    fmt::println("");
}

export void vector_example()
{
    fmt::println("Vectors Example:");
    std::vector<int> vec{1, 2, 3, 4, 5};

    // Accessing Elements using []
    fmt::println("Accessing Elements Using []:");
    for (size_t i = 0; i < vec.size(); ++i)
    {
        fmt::println("vec[{}] = {}", i, vec[i]);
    }
    fmt::println("");

    // Accessing elements using .at()
    fmt::println("Accessing Elements using .at():");
    for (size_t i = 0; i < vec.size(); ++i)
    {
        fmt::println("vec.at({}) = {}", i, vec.at(i));
    }
    fmt::println("");

    // Modifying elements in the vector
    fmt::println("Modifying Elements in the Vector:");
    fmt::println("Modifying Element 0.");
    vec[0] = 10;
    fmt::println("Modifying Element 3.");
    vec[3] = 34;
    fmt::println("");

    fmt::println("Printing Modified Vector:");
    for (size_t i = 0; i < vec.size(); ++i)
    {
        fmt::println("vec[{}] = {}", i, vec[i]);
    }
    fmt::println("");

    // Using range-based for loops
    fmt::println("Using Range-based For Loops:");
    for (const auto& element : vec)
    {
        fmt::println("{}", element);
    }
    fmt::println("");


    fmt::println("Filling A Vector With A Value:");
    fmt::println("Declaring An Empty Vector");
    // Declaring a vector with initial length 5
    std::vector<int> vec2(5);

    fmt::println("Filling Vector with a Single Value (7):");
    // Filling vector with a single value
    std::fill(vec2.begin(), vec2.end(), 7);
    fmt::println("");

    fmt::println("Printing filled Vector:");
    for (const auto& element : vec2)
    {
        fmt::println("{}", element);
    }
    fmt::println("");

    fmt::println("Accessing First & Last Elements:");
    fmt::println("First element: {}", vec.front());
    fmt::println("Last element: {}", vec.back());
    fmt::println("");


    fmt::println("Multi-Dimensional Vector:");
    std::vector<std::vector<int>> multi {{1, 2}, {3, 4}, {5, 6}};

    for (const auto& row : multi)
    {
        for (const auto& col : row)
        {
            fmt::print("{} ", col);
        }
        fmt::println("");
    }
    fmt::println("");
}
