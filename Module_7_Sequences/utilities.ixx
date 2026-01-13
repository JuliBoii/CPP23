module;

#include <fmt/format.h>
#include <array>

export module utilities;


export void std_array_example()
{
    fmt::println("Example of std::array");

    // Declaration and init
    std::array<int, 5> arr{1, 2, 3, 4, 5};

    // Accessing elements using []
    for (size_t i = 0; i < arr.size(); ++i)
    {
        fmt::println("arr[{}] = {}", i, arr[i]);
    }

    // Use range based for loop
    for (const auto& element : arr)
    {
        fmt::println("{}", element);
    }

    // Accessing elements using at()
    for (size_t i = 0; i < arr.size(); ++i)
    {
        fmt::println("arr.at({}) = {}", i, arr[i]);
    }
}