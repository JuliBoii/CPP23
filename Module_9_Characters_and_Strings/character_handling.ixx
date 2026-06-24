module;

#include <cctype>
#include <fmt/format.h>

export module character_handling;

bool my_isprint(char c) {
    return std::isprint(static_cast<unsigned char>(c));
}

namespace character_handling {
    export void check_if_alphanumeric() {
        fmt::println("Example using std::isalnum:");
        fmt::println("C is alphanumeric: {}", (std::isalnum('C') ? "True" : "False"));
        fmt::println("^ is alphanumeric: {}", (std::isalnum('^') ? "True" : "False"));
        fmt::println("7 is alphanumeric: {}\n", (std::isalnum('7') ? "True" : "False"));

        fmt::println("Used in an if statement");
        if (std::isalnum('[')) {
            fmt::println("Is alphanumeric\n");
        } else {
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

    export void check_if_blank() {
        fmt::println("Example using std::isblank:");
        char message[]{"This is a string of characters.\nHow is your day?\n"};
        fmt::println("{}", message);

        size_t blank_count{0};

        for (size_t index{0}; index < std::size(message); ++index) {
            if (std::isblank(message[index])) {
                fmt::println("Blank character at index: {}", index);
                blank_count++;
            }
        }
        fmt::println("\nTotal number of blank characters: {}\n", blank_count);
    }

    export void check_uppercase() {
        fmt::println("Example using std::isupper & std::toupper:");
        char message[]{"This is a string of characters.\nHow is your day?\n"};
        fmt::println("Original message: \n{}", message);
        size_t upper_count{0};

        for (size_t index{0}; index < std::size(message); ++index) {
            if (std::isupper(message[index])) {
                fmt::println("Uppercase character at index: {}", index);
                upper_count++;
            }
        }
        fmt::println("\nTotal number of upper case characters: {}\n", upper_count);

        for (size_t index{0}; index < std::size(message); ++index) {
            if (std::isupper(message[index])) {
                continue;
            }
            message[index] = std::toupper(message[index]); // NOLINT(*-narrowing-conversions)
        }
        fmt::println("Modified message (using std::toupper): \n{}", message);
    }

    export void check_lowercase() {
        fmt::println("Example using std::islower and std::tolower:");
        char message[]{"This MESSAGE is nOT fully LowERCASE.\nTHus, WE Must Fix IT!\n"};
        fmt::println("Original message: \n{}", message);

        size_t lower_count{0};
        for (size_t index{0}; index < std::size(message); ++index) {
            if (std::islower(message[index])) {
                fmt::println("Lower case character at index: {}", index);
                lower_count++;
            }
        }
        fmt::println("\nTotal number of lowercase characters: {}\n", lower_count);

        for (size_t index{0}; index < std::size(message); ++index) {
            if (std::islower(message[index])) {
                continue;
            }
            message[index] = std::tolower(message[index]); // NOLINT(*-narrowing-conversions)
        }
        fmt::println("Modified message (using std::tolower):\n{}", message);
    }

    export void check_if_decimal_and_hexadecimal() {
        fmt::println("Example using std::isdigit:");
        char message[]{"abcdefghijklmnopqrstuvwxyz0123456789\n"};
        fmt::println("Original message: \n{}", message);

        size_t decimal_count{0};
        for (size_t index{0}; index < std::size(message); ++index) {
            if (std::isdigit(message[index])) {
                fmt::println("Decimal character at index: {}", index);
                decimal_count++;
            }
        }
        fmt::println("\nTotal number of decimal characters: {}\n", decimal_count);

        size_t hexadecimal_count{0};
        for (size_t index{0}; index < std::size(message); ++index) {
            if (std::isxdigit(message[index])) {
                fmt::println("Hexadecimal character at index: {}", index);
                hexadecimal_count++;
            }
        }
        fmt::println("\nTotal hexadecimal characters: {}\n", hexadecimal_count);
    }

    export void check_if_whitespace_character() {
        fmt::println("Example using std::isspace:");
        char message[]{"Are any of these characters a whitespace \fcharacter\t.\n\v\r"};
        fmt::println("Original message: \n{}", message);

        size_t whitespace_count{0};
        for (size_t index{0}; index < std::size(message); ++index) {
            if (std::isspace(message[index])) {
                fmt::println("Whitespace character at index: {}", index);
                whitespace_count++;
            }
        }
        fmt::println("\nTotal whitespace characters: {}\n", whitespace_count);
    }

    export void check_if_punctuation() {
        fmt::println("Example using std::ispunct:");
        char message[]{
            "Hey,\nHow have you been? Are you still in California?"
            "\nI always loved going to Yosemite with you on the weekends."
            "\nLet's go again, if you are still there.\nHope to hear from you!\n"
        };
        fmt::println("Original message: \n{}", message);

        size_t punctuation_count{0};
        for (size_t index{0}; index < std::size(message); ++index) {
            if (std::ispunct(message[index])) {
                fmt::println("Punctuation character at index: {}", index);
                punctuation_count++;
            }
        }
        fmt::println("\nTotal punctuation characters: {}\n", punctuation_count);
    }

    export void check_if_printable_character() {
        fmt::println("Example using std::isprint:");
        char message[]{
            "!\"§ $%& /() =?* \'<> #|; ²³~ @`´ ©«» ¤¼× /() =?*<> #|; ²³~"
        };
        fmt::println("Total size of message: {}", std::size(message));

        size_t printable_character_count{0};
        for (size_t index{0}; index < std::size(message); ++index) {
            if (my_isprint(message[index])) {
                printable_character_count++;
            }
        }
        fmt::println("Total printable characters: {}\n", printable_character_count);
    }
}
