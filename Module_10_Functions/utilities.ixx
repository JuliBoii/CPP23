module;

#include <utility>
#include <vector>
#include <string>
#include <random>
#include <fmt/format.h>

export module utilities;

import functions_interface;
import function_parameters;

export void running_example_functions() {
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
}

export void passing_parameters_to_functions() {
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
}

export void using_command_line_arguments(const int &argc, char *argv[]) {
    // fmt::println("Working with Command-line Arguments:");
    // for (auto i{0uz}; i < argc; i++) {
    //     fmt::print("argv[{}]: {}\n", i, argv[i]);
    // }

    calculator_example(argc, argv);
}

namespace overloading_example {
    export void print(int value) {
        fmt::println("Integer: {}", value);
    }

    export void print(double value) {
        fmt::println("Double: {}", value);
    }

    export void print(const std::string &value) {
        fmt::println("String: {}", value);
    }

    export void print(const std::vector<int> &value) {
        fmt::print("Vector: ");
        for (const auto &item: value) {
            fmt::print("{}, ", item);
        }
        fmt::println("");
    }
}

namespace dice_roll_overloading {
    std::mt19937 generator{std::random_device{}()};

    export auto roll() -> int {
        std::uniform_int_distribution distribution{1, 6};
        return distribution(generator);
    }

    export auto roll(int side_count) -> int {
        std::uniform_int_distribution distribution{1, side_count};
        return distribution(generator);
    }

    export auto roll(int sides_count, int die_count) -> int {
        int result{0};
        for (auto i{0UZ}; std::cmp_less(i , die_count); ++i) {
            result += roll(sides_count);
        }
        return result;
    }
}

export void lambda_examples() {
    // Declaring & Calling Lambda Function
    auto say_hello = [] -> void {
        fmt::println("Hello!");
    };

    say_hello();
    say_hello();
    say_hello();

    // Declaring & Using Lambda Right Away
    [] -> void {
        fmt::println("I was called!!");
    }();

    // Passing Arguments to a quick Lambda Function
    fmt::println("lambda multiplication function, passed 41 & 14: {}", [](int a, int b) -> int {
        return a * b;
    }(41, 14));

    // Using Lambda Function from module (functions_interface)
    fmt::println("lambda_add(14, 41): {}", lambda_add(14, 41));

    // Using result from lambda function
    auto result = [](int x, int y) -> int {
        return x - y;
    }(62, 26);

    fmt::println("result of subtraction lambda function: {}", result);
}
