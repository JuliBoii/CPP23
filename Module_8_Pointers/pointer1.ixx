module;

#include <fmt/format.h>
// #include <print>

export module pointer1;

export void declaration_and_initialization() {
    fmt::println("Declaring & Initializing Pointers:");
    [[maybe_unused]] int *p_number{};
    [[maybe_unused]] double *p_fractional_number{nullptr};

    fmt::println("Comparing Pointer's Byte Size");
    fmt::println("sizeof(int): {}", sizeof(int));
    fmt::println("sizeof(double): {}", sizeof(double));
    fmt::println("sizeof(int*): {}", sizeof(int *));
    fmt::println("sizeof(double*): {}", sizeof(double *));
    fmt::println("sizeof(p_number): {}", sizeof(p_number));
    fmt::println("sizeof(p_fractional_number): {}", sizeof(p_fractional_number));
    fmt::println("");
}

export void assignment_and_access() {
    fmt::println("Assigning and Accessing Pointers:");

    int integer_variable{34};
    int *p_int{&integer_variable};

    fmt::println("Accessing the Address stored in a pointer:");

    // std::println("integer_variable: {}", integer_variable);
    // std::println("Address stored in p_int: {}", static_cast<void *>(p_int));
    fmt::println("Address of integer_variable: {}", static_cast<void *>(&integer_variable));
    fmt::println("Address stored in p_int: {}", static_cast<void *>(p_int));
    fmt::println("");

    fmt::println("Accessing the Value of Stored Address");
    fmt::println("Value of integer_variable: {}", integer_variable);
    fmt::println("Value of Stored Address in p_int: {}", *p_int);
    fmt::println("");

    fmt::println("Accessing the Address of the pointer:");
    fmt::println("Address of p_int: {}", static_cast<void *>(&p_int));
    fmt::println("");

    fmt::println("Pointer Address Re-assignment:");
    fmt::println("Address of p_int: {}", static_cast<void *>(p_int));

    int integer_variable_2{1451};
    p_int = &integer_variable_2;

    fmt::println("New Address of p_int: {}", static_cast<void *>(p_int));

    /*double double_variable{3.14};
    p_int = &double_variable;*/
}
