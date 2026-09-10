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

    export [[nodiscard]] int lucky_number()
    {
        std::random_device rd;
        std::mt19937_64 gen(rd());
        std::uniform_int_distribution dis(0, 846);
        return dis(gen);
    }
}