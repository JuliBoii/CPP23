#include <fmt/format.h>
#include <string>
#include <vector>

import utilities;
import functions_interface;

int main(int argc, char **argv) {
    // running_example_functions();
    // passing_parameters_to_functions();

    // Working with constexpr & consteval
    /*constexpr int arr_size = square_val(3);
    int arr2[arr_size];
    static_assert(arr_size == 9);

    int arr_size_2 = square_val(5);
    int arr3[arr_size_2];

    constexpr int cubed_val = cube_val(10);
    static_assert(cubed_val == 1000);*/

    // using_command_line_arguments(argc, argv);
    std::vector<int> vec{1, 41, 51, 813, 613, 8145, 88, 1134, 256};

    overloading_example::print(4);
    overloading_example::print(41.145);
    overloading_example::print("This is a string");
    overloading_example::print(vec);

    return 0;
}
