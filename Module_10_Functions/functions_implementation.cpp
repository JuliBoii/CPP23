module;

#include <print>

module functions_interface;

int add(const int &a, const int &b) {
    return a + b;
}

int maximum(const int &a, const int &b) {
    return a > b ? a : b;
}

int minimum(const int &a, const int &b) {
    return a < b ? a : b;
}

int increment_and_multiply(int a, int b) {
    private_function(); // Can be called
    return ++a * ++b;
}

void private_function() {
    std::print("hello\n");
}
