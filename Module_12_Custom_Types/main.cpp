#include <print>

import utilities;

auto main() -> int {
    public_access_example();
    private_access_example();
    setter_and_getters_example();

    std::println("Example using Explicit Object Parameter for Recursive Lambdas:");
    std::println("fib(10) = {}", fib(10));
    std::println("fib(4) = {}", fib(4));
    return 0;
}
