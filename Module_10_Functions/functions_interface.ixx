export module functions_interface;

/*
 * This is just the declarations of functions
 * Similar to a header file, prior to C++20
 * We can separate the implementation and interface
 */

export int add(const int &a, const int &b);

export int maximum(const int &a, const int &b);

export int minimum(const int &a, const int &b);

export int increment_and_multiply(int a, int b);

void private_function();

// Have to be defined completely
// Cannot be defined here and implemented in the functions_implementation.cpp file

export constexpr int square_val(const int &a)
{
    return a * a;
}

export consteval int cube_val(const int &a)
{
    return a * a * a;
}