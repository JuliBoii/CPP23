module;

#include <utility>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <span>
#include "fmt/format.h"

module function_parameters;

void pass_by_value_increment_print(int a) {
    fmt::println("Pass by Value:");
    ++a;
    fmt::println("a: {}", a);
    fmt::println("a Address: {}\n", fmt::ptr(&a));
}

void pass_by_reference_increment_print(int &a) {
    fmt::println("Pass by Reference:");
    ++a;
    fmt::println("a: {}", a);
    fmt::println("a Address: {}\n", fmt::ptr(&a));
}

void pass_by_const_reference_increment_print(const int &a) {
    fmt::println("Pass by const Reference:");
    //++a;
    fmt::println("Cannot modify const data");
    fmt::println("a: {}", a);
    fmt::println("a Address: {}\n", fmt::ptr(&a));
}

void pass_by_pointer_increment_print(int *a) {
    fmt::println("Pass by Pointer:");
    ++*a;
    fmt::println("a: {}", *a);
    fmt::println("a Address: {}\n", fmt::ptr(a));
}

void pass_by_default_increment_print(int a) {
    fmt::println("Pass by Default:");
    fmt::println("Default: {}", a);
    ++a;
    fmt::println("a: {}", a);
    fmt::println("a Address: {}\n", fmt::ptr(&a));
}

void vector_print(const std::vector<int> &vec) {
    fmt::println("Vector Print:");
    for (const auto &i: vec) {
        fmt::print("{} ", i);
    }
    fmt::println("\n");
}

void raw_array_print(const int arr[], const size_t &size) {
    fmt::println("Raw Array Print:");
    for (size_t i = 0; i < size; ++i) {
        fmt::print("{} ", arr[i]);
    }
    fmt::println("\n");
}

void span_print(std::span<const int> span_view) {
    fmt::println("Span Print:");
    for (const auto &i: span_view) {
        fmt::print("{} ", i);
    }
    fmt::println("\n");
}

void command_line_argument_print(const int& count, char** argv)
{
    fmt::println("There are {} command line arguments:", count);

    for (auto i{0UZ}; std::cmp_less(i , count); ++i)
    {
        fmt::println("argv[{}] = {}", i, argv[i]);
    }
}

void calulator_example(const int &count, char **argv)
{
    // Check # of arguments
    if (std::cmp_equal(count, 4))
    {
        fmt::println("Program can only be called with 3 arguments:");
        fmt::println("You only provided {} arguments, which ", count - 1);
        for (auto i{1UZ}; std::cmp_less(i , count); ++i)
        {
            fmt::print("argv[{}] = {} ", i, argv[i]);
        }
        return;
    }

    double first_value{ std::atof(argv[1]) };
    double second_value{ std::atof(argv[3]) };

    const char* operation{ argv[2] };

    /*if (std::cmp_equal(std::strlen(operation), 1))
    {

    }*/
}