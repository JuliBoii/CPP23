#include <vector>
#include <span>
#include <fmt/format.h>

import functions_interface;
import function_parameters;

int main(int argc, char **argv) {
    auto result = add(13, 52);
    fmt::println("add(13, 52): {}", result);

    result = add(11, 30);
    fmt::println("add(11, 30): {}", result);

    result = maximum(add(41, 5), add(14, 7));
    fmt::println("maximum(add(41, 5), add(14,7)): {}", result);

    result = minimum(add(41, 5), add(14, 7));
    fmt::println("minimum(add(41, 5), add(14,7)): {}", result);

    // private_function(); // Cannot be called, due to not having export keyword

    result = increment_and_multiply(14, 41);
    fmt::println("increment_and_multiply(14, 41): {}\n", result);

    auto int_value{23};
    fmt::println("int_value: {}", int_value);
    fmt::println("int_value Address: {}\n", fmt::ptr(&int_value));

    //Pass by Value
    pass_by_value_increment_print(int_value);

    //Pass by Reference
    pass_by_reference_increment_print(int_value);

    // Pass by const Reference
    pass_by_const_reference_increment_print(int_value);

    // Pass by Pointer
    pass_by_pointer_increment_print(&int_value);

    // Pass by Default Parameter
    pass_by_default_increment_print();

    // Passing sequences & raw arrays
    const std::vector<int> my_vector{14, 41, 44, 11};
    const int arr[]{1, 2, 4, 5, 6};
    size_t size = std::size(arr);

    vector_print(my_vector);
    raw_array_print(arr, size);
    span_print(my_vector);
    span_print(arr);

    // Working with constexpr & consteval
    constexpr int arr_size = square_val(3);
    int arr2[arr_size];
    static_assert(arr_size == 9);

    int arr_size_2 = square_val(5);
    int arr3[arr_size_2];

    constexpr int cubed_val = cube_val(10);
    static_assert(cubed_val == 1000);

    fmt::println("Working with Command-line Arguments:");
    for (auto i{0uz}; i < argc; i++) {
        fmt::print("argv[{}]: {}\n", i, argv[i]);
    }

    return 0;
}
