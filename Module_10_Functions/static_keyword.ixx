module;

#include <fmt/format.h>

export module static_keyword;

static auto global_variable_count{0UZ};
// export static auto global_variable_count{0UZ}; // Fails to compile since the program is ill-formed.

namespace static_keyword
{
    export auto login_without_static() -> void
    {
        auto login_count{0UZ};
        login_count++;
        fmt::println("Current Login Count: {}", login_count);
    }

    export auto login_with_static() -> void
    {
        static auto login_count{0UZ};
        login_count++;
        fmt::println("Current Login Count: {}", login_count);
    }

    export auto using_global_static_variable() -> void
    {
        global_variable_count++;
        fmt::println("Current Global Static Variable: {}", global_variable_count);
    }
}