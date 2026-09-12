#include <fmt/format.h>
#include <string>
#include <vector>

import utilities;
import functions_interface;
import attributes;

auto main(int argc, char **argv) -> int {
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

    /*// using_command_line_arguments(argc, argv);
    std::vector<int> vec{1, 41, 51, 813, 613, 8145, 88, 1134, 256};

    overloading_example::print(4);
    overloading_example::print(41.145);
    overloading_example::print("This is a string");
    overloading_example::print(vec);

    fmt::println("Rolling a 6-sided dice: {}", dice_roll_overloading::roll());
    fmt::println("Rolling a 20-sided dice: {}", dice_roll_overloading::roll(20));
    fmt::println("Rolling 5 6-sided die: {}", dice_roll_overloading::roll(6, 5));*/

    // lambda_examples();
    // lambda_capture_list_examples();

    fmt::println("Exiting the program");
    // attributes::exit_program();
    fmt::println("Program did not terminate\n"); // Will not run if line above is not commented out

    // attributes::old_function(); // This will generate a warning
    attributes::new_function(); // Does not generate a warning
    fmt::println("");

    // attributes::nodiscard_example(); // Generates a warning
    fmt::println("What is my lucky number for today: {}\n", attributes::nodiscard_example());
    // Does not generate a warning
    [[maybe_unused]] int lucky_num{attributes::nodiscard_example()}; // valid

    attributes::fallthrough_attribute_example(5);
    attributes::fallthrough_attribute_example(1);
    attributes::fallthrough_attribute_example(2);
    fmt::println("");

    fmt::println("process_value(43) = {}\nprocess_value(42) = {}\n", attributes::likely_and_unlikely_example(43),
                 attributes::likely_and_unlikely_example(42));

    attributes::assume_attribute_example(5);
    // attributes::assume_attribute_example(-14); // Still compiles, but again could have runtime undefined behavior


    return 0;
}
