module;

#include <cctype>
#include <fmt/format.h>

export module character_handling;

namespace character_handling {
    export void check_if_alphanumeric()
    {
        fmt::println("Example using std::isalnum:");
        fmt::println("C is alphanumeric: {}", (std::isalnum('C') ? "True" : "False"));
        fmt::println("^ is alphanumeric: {}", (std::isalnum('^') ? "True" : "False"));
        fmt::println("7 is alphanumeric: {}\n", (std::isalnum('7') ? "True" : "False"));

        fmt::println("Used in an if statement");
        if (std::isalnum('['))
        {
            fmt::println("Is alphanumeric\n");
        } else
        {
            fmt::println("Is not alphanumeric\n");
        }
    }

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

    export void check_if_blank()
    {
        fmt::println("Example using std::isblank:");
        char message[] {"This is a string of characters.\nHow is your day?\n"};
        fmt::println("{}",message);

        size_t blank_count{};

        for (size_t index{0}; index < std::size(message); ++index)
        {
            if (std::isblank(message[index]))
            {
                fmt::println("Blank character at index: {}", index);
                blank_count++;
            }
        }
        fmt::println("\nTotal number of blank characters: {}\n", blank_count);
    }
}
