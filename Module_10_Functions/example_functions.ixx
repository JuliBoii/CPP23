module;

export module example_functions;

export int add(const int &a, const int &b) {
    return a + b;
}

export int maximum(const int &a, const int &b) {
    return a > b ? a : b;
}

export int minimum(const int &a, const int &b) {
    return a < b ? a : b;
}

export int increment_and_multiply(int a, int b) {
    return ++a * ++b;
}
