#include <print>

import utilities;

auto main() -> int {
    public_access_example();
    private_access_example();
    setter_and_getters_example();

    std::println("\nExample using Explicit Object Parameter for Recursive Lambdas:");
    std::println("fib(10) = {}", fib(10));
    std::println("fib(4) = {}\n", fib(4));

    constructor_delegation_example();
    explicit_conversion_example();

    return 0;
}
