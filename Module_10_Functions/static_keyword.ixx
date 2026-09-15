module;

#include <utility>
#include <vector>
#include <fmt/format.h>

export module static_keyword;

static auto global_variable_count{0UZ};
// export static auto global_variable_count{0UZ}; // Fails to compile since the program is ill-formed.

namespace static_keyword {
    export auto login_without_static() -> void {
        auto login_count{0UZ};
        login_count++;
        fmt::println("Current Login Count: {}", login_count);
    }

    export auto login_with_static() -> void {
        static auto login_count{0UZ};
        login_count++;
        fmt::println("Current Login Count: {}", login_count);
    }

    export auto using_global_static_variable() -> void {
        global_variable_count++;
        fmt::println("Current Global Static Variable: {}", global_variable_count);
    }

    // Making the lambda function recursive (C++23 Compiler Needed)
    export auto fibonacci_memorization_lambda = [](this auto &self, const int n) -> int {
        static std::vector memo(100, -1); // Init with -1 to indicate uncomputed values

        if (std::cmp_equal(n, 0)) {
            return 0;
        }
        if (std::cmp_equal(n, 1)) {
            return 1;
        }

        if (std::cmp_not_equal(memo[n], -1)) {
            return memo[n];
        }

        memo[n] = self(n - 1) + self(n - 2);

        return memo[n];
    };
}
