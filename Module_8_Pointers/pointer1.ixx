module;

#include <fmt/format.h>

export module pointer1;

export void declaration_and_initialization() {
    fmt::println("Declaring & Initializing Pointers:");
    int *p_number{};
    double *p_fractional_number{nullptr};

    fmt::println("Comparing Pointer's Byte Size");
    fmt::println("sizeof(int): {}", sizeof(int));
    fmt::println("sizeof(double): {}", sizeof(double));
    fmt::println("sizeof(int*): {}", sizeof(int *));
    fmt::println("sizeof(double*): {}", sizeof(double *));
    fmt::println("sizeof(p_number): {}", sizeof(p_number));
    fmt::println("sizeof(p_fractional_number): {}", sizeof(p_fractional_number));
}

export void assignment_and_access() {
    fmt::println("Assigning and Accessing Pointers:");
}
