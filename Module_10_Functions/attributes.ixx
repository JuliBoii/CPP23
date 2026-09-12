module;

#include <fmt/format.h>
#include <cstdlib>
#include <random>

export module attributes;

namespace attributes {
    export [[noreturn]] void exit_program() {
        std::exit(1);
    }

    export [[deprecated("Use new_function()")]] void old_function() {
        fmt::println("This is the old function");
    }

    export void new_function() {
        fmt::println("New function");
    }

    export [[nodiscard("This result is important")]] auto nodiscard_example() -> int {
        std::random_device rd;
        std::mt19937_64 gen(rd());
        std::uniform_int_distribution dis(0, 846);
        return dis(gen);
    }

    export auto fallthrough_attribute_example(int value) -> void {
        switch (value) {
            case 1:
                fmt::println("Handling: 1");
                [[fallthrough]];
            case 2:
                fmt::println("Handling: 2");
                break;
            default:
                fmt::println("Unhandled value: {}", value);
        }
    }

    export auto likely_and_unlikely_example(int value) -> int {
        if (value == 42) [[likely]] {
            return value * 2;
        } else [[unlikely]] {
            return value / 2;
        }

        fmt::println("Unhandled value: {}", value);
        return -1;
    }

    export auto assume_attribute_example(int value) -> void {
        [[assume(value > 0)]];
        fmt::println("Value is greater than 0: {}", value);
    }
}
