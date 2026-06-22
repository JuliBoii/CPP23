module;

#include <cctype>
#include <fmt/format.h>

export module character_handling;

namespace character_handling {
    export void check_if_alphabetic() {
        fmt::println("Example using std::isalpha:");
        fmt::println("C is alphabetic: {}", (std::isalpha('C') ? "True" : "False"));
        fmt::println("^ is alphabetic: {}", (std::isalpha('^') ? "True" : "False"));
        fmt::println("7 is alphabetic: {}\n", (std::isalpha('7') ? "True" : "False"));

        fmt::println("Used in an if statement");
        if (std::isalpha('a')) {
            fmt::println("Is alphabetic\n");
        } else {
            fmt::println("Is not alphabetic\n");
        }
    }
}
