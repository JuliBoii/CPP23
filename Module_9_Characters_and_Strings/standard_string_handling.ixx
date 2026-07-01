module;

#include <string>
#include <cctype>
#include <iostream>
#include <fmt/format.h>

export module string_handling;

using namespace std::literals::string_literals;

namespace string_handling {
    export void standard_string_declaration_and_initialization() {
        fmt::println("Example of std::string declaration and initialization");
        std::string full_name;
        std::string planet{"Earth. Where the sky is blue"};
        std::string preferred_planet{planet};
        std::string message{"Hello there", 5};
        std::string weird_message(4, 'e');
        std::string greeting{"Hello World"};
        std::string saying_hello{greeting, 6, 5};

        fmt::println("full_name: {}", full_name);
        fmt::println("planet: {}", planet);
        fmt::println("preferred planet: {}", preferred_planet);
        fmt::println("message: {}", message);
        fmt::println("weird_message: {}", weird_message);
        fmt::println("greeting: {}", greeting);
        fmt::println("saying_hello: {}\n", saying_hello);

        // Reassign std::string at runtime
        planet = "Jupiter is awesome!"s;
        fmt::println("planet: {}\n", planet);
    }

    export void standard_string_concatenation() {
        fmt::println("Example of std::string concatenation");
        fmt::println("Concatenating using two string literals:");

        // auto cstyle_string = "Hello" + "World";
        // auto standard_string{"Hello" + "World"};

        auto standard_string = "Hello"s + " World";
        fmt::println("standard_string: {}\n", standard_string);

        fmt::println("Concatenating using two string variables:");
        std::string str_var_1{"Hello"s};
        std::string str_var_2{"World"s};
        fmt::println("str_var_1: {}", str_var_1);
        fmt::println("str_var_2: {}", str_var_2);
        fmt::println("result: {}", str_var_1 + str_var_2);
        fmt::println("result (With temp string added): {}\n", str_var_1 + " my " + str_var_2);

        fmt::println("Concatenation using the append() member function:");
        std::string str{"Hello"};
        str.append(" World");
        fmt::println("{}", str);

        str = "Hey";
        str.append(3, '!');
        fmt::println("{}", str);

        str = "is my name.";
        std::string name{"Angel "};
        name.append(str, 0, 11);
        fmt::println("{}", name);

        str = "Los Angeles ";
        str.append("California", 2);
        fmt::println("{}", str);

        str = "Letters: ";
        std::string letters{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
        str.append(letters.begin(), letters.begin() + 5); // +5 is the length from beginning
        fmt::println("{}\n", str);

        fmt::println("Concatenating using += operand:");
        str = "Hello"s;
        str += " World!"s;
        fmt::println("{}", str);

        str = "C++";
        str += "Programming";
        fmt::println("{}", str);

        str = "Dog";
        str += 's';
        fmt::println("{}\n", str);

        fmt::println("Concatenation using push_back() member function:");
        str = "Heyyyyyy"s;
        str.push_back('!');
        fmt::println("{}\n", str);

        fmt::println("Concatenating numbers to a std::string:");
        std::string message{"How many apples do I have? Let me check: "};
        int apples{41};
        float apple_price{1.99f};

        message.append(std::to_string(apples));
        message.append("\nI can sell them for ");
        message.append(std::to_string(apple_price));
        fmt::println("{}\n", message);
    }

    export void standard_string_memory_and_capacity() {
        fmt::println("Example of accessing the length/size of a std::string");
        std::string message{"What is the size/length of this string"};
        fmt::println("{}", message);
        fmt::println("message.size(): {}", message.size());
        fmt::println("message.length(): {}\n", message.length());

        fmt::println("Example of checking if a string is empty:");
        std::string message1;
        std::string message2{};

        fmt::println("message.empty(): {}", message.empty());
        fmt::println("message1.emtpy(): {}", message1.empty());
        fmt::println("message2.empty(): {}\n", message2.empty());

        fmt::println("Example of max_size() member function:");
        fmt::println("message.mex_size(): {}\n", message2.max_size());

        fmt::println("Example of capacity() member function:");
        fmt::println("message.capacity(): {}", message2.capacity());
        fmt::println("message.size(): {}\n", message2.size());

        fmt::println("Example of reserving space for 100 characters:");
        message2.reserve(100);
        fmt::println("message.capacity(): {}", message2.capacity());
        fmt::println("message.size(): {}\n", message2.size());

        fmt::println("Example of reducing the capacity of message:");
        message2.shrink_to_fit();
        fmt::println("message.capacity(): {}", message2.capacity());
        fmt::println("message.size(): {}\n", message2.size());

        fmt::println("Example of using clear() member function:");
        fmt::println("message: {}", message);
        fmt::println("message.capacity(): {}", message.capacity());
        fmt::println("message.size(): {}", message.size());
        fmt::println("message.length(): {}\n", message.length());

        fmt::println("Calling clear() on message");
        message.clear();
        fmt::println("message: {}", message);
        fmt::println("message.capacity(): {}", message.capacity());
        fmt::println("message.size(): {}", message.size());
        fmt::println("message.length(): {}\n", message.length());
    }

    export void standard_string_accessing_elements() {
        fmt::println("Example of accessing elements of a std::string");
        fmt::println("Subscript Operator:");
        std::string message{"Can I Access This Character."};
        fmt::println("{}", message);

        const char element{message[4]};
        message[4] = 'e';

        fmt::println("message[4] previously was: {}", element);
        fmt::println("message[4] is now: {}", message[4]);
        fmt::println("{}\n", message);

        fmt::println("Member Function at()");
        message = "Can I Access This Character.";
        fmt::println("{}", message);

        const char element1{message.at(4)};
        message.at(4) = 'e';

        fmt::println("message.at(4) previously was: {}", element1);
        fmt::println("message.at(4) is now: {}", message.at(4));
        fmt::println("{}", message);

        fmt::println("Bound Checking with at()");
        try {
            // ReSharper disable once CppDFAUnusedValue
            [[maybe_unused]] const char out_of_bound{message.at(89)};
        } catch (const std::out_of_range &e) {
            std::cerr << e.what() << std::endl;
        }
        fmt::println("");

        fmt::println("Using front() and back():");
        message = "Can I Access This Character"s;
        fmt::println("message: {}", message);
        fmt::println("First character of message: {}", message.front());
        fmt::println("Last character of message: {}\n", message.back());

        fmt::println("Example using Iterator and Range-Based For Loop:");
        fmt::println("Using Range-Based For Loop");
        message = "HEY! THIS IS A STRING.";
        fmt::println("{}", message);

        for (auto &element: message) {
            if (std::tolower(element))
                element = std::tolower(element); // NOLINT(*-narrowing-conversions)
        }

        for (const auto &element: message) {
            fmt::print("{}", element);
        }
        fmt::print("\n\n");

        fmt::println("Using an explicit Iterator");
        message = "HEY! THIS IS A STRING.";
        fmt::println("{}", message);

        for (auto it = message.begin(); it != message.end(); ++it) { // NOLINT(*-loop-convert)
            if (std::tolower(*it))
                *it = std::tolower(*it); // NOLINT(*-narrowing-conversions)
        }

        for (auto it = message.begin(); it != message.end(); ++it) { // NOLINT(*-loop-convert)
            fmt::print("{}", *it);
        }
        fmt::println("\n");

        fmt::println("Example of using insert() Member Function:");
        std::string str{"tard"};
        fmt::println("Before insert():");
        fmt::println("{}\n", str);

        // Insert a single character
        fmt::println("After insert() single character:");
        str.insert(0, "S"); // Using index
        fmt::println("{}", str);

        str.insert(str.begin(), 'C'); // Using Iterator
        fmt::println("{}", str);

        str.insert(str.begin() + 1, ' '); // Using Iterator
        fmt::println("{}\n", str);

        // Insert a single character multiple times
        fmt::println("After insert() repeating character:");
        str.insert(1, 2, '+'); // index 1, repeat 2 times
        fmt::println("{}\n", str);

        // Insert a string
        fmt::println("After insert() a string:");
        str.insert(6, "and"s);
        fmt::println("{}\n", str);

        // Insert a range from another string
        fmt::println("After insert() substring from a given string:");
        std::string substr{" is the latest standard pushed by the CPP Committee."s};
        str.insert(12, substr, 0, 23);
        fmt::println("{}\n", str);

        // Insert an iterator range
        std::string substr2{"26"s};
        fmt::println("After insert() iterator range:");
        str.insert(str.begin() + 3, substr2.begin(), substr2.end());
        fmt::println("{}", str);
    }
}
