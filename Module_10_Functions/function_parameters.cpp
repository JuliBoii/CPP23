module;

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
