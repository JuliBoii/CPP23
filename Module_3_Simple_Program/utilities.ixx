module;

// Global Module Fragment
// Where we put our include statements
# include <string_view>
# include <string>
# include <fmt/format.h>

export module utilities; // Module definition

// Module purview
export void print_msg(std::string_view str) {
    fmt::print("{}\n", static_cast<std::string>(str));
}

export int add_numbers(const int& a, const int& b) {
    return a + b;
}

export void print_number(const int& num) {
    fmt::print("Number is: {}\n", num);
}