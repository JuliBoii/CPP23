module;

#include <fmt/format.h>
#include <cstdlib>
#include <random>

export module attributes;

namespace attributes
{
    export [[noreturn]] void exit_program()
    {
        std::exit(1);
    }

    export [[deprecated("Use new_function()")]] void old_function()
    {
        fmt::println("This is the old function");
    }

    export void new_function()
    {
        fmt::println("New function");
    }

    export [[nodiscard]] auto lucky_number() -> int
    {
        std::random_device rd;
        std::mt19937_64 gen(rd());
        std::uniform_int_distribution dis(0, 846);
        return dis(gen);
    }

    export auto handle_switch(int value) -> void
    {
        switch (value)
        {
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

    export auto process_value(int value) -> int
    {
        if (value == 42) [[likely]]
        {
            return value * 2;
        } else [[unlikely]]
        {
            return value/2;
        }
    }
}