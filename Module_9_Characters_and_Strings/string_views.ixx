module;

#include <string>
#include <string_view>
#include <fmt/format.h>

export module string_views;

using namespace std::literals::string_literals;

// ReSharper disable once CppUseInternalLinkage
void print(std::string str) {
    fmt::println("{}", str);
}

// ReSharper disable once CppUseInternalLinkage
void print_ref(std::string &str) {
    fmt::println("{}", str);
}

// ReSharper disable once CppUseInternalLinkage
void print_const_ref(const std::string &str) {
    fmt::println("{}", str);
}

// ReSharper disable once CppUseInternalLinkage
void print_view(std::string_view str_v) {
    fmt::println("{}", str_v);
}

auto get_name_of_bool(const bool &bval) -> std::string_view {
    std::string t{"true"};
    std::string f{"false"};

    if (bval) {
        return t;
    }

    return f;
}

namespace string_views {
    export void problem_with_standard_string() {
        fmt::println("Showcasing the problem with std::string:");
        fmt::println("Making copies when initializing:");
        std::string str{"New string!"};
        std::string str1{str};
        std::string str2{str};
        fmt::println("str: {}", str);
        fmt::println("str1: {}", str1);
        fmt::println("str2: {}\n", str2);

        fmt::println("str Address: {}", fmt::ptr(&str));
        fmt::println("str1 Address: {}", fmt::ptr(&str1));
        fmt::println("str2 Address: {}\n", fmt::ptr(&str2));

        fmt::println("Solution: use std::string_view, to prevent copies being made:");
        std::string_view str_v{"New string!"};
        std::string_view str_v1{str_v};
        std::string_view str_v2{str_v1};
        fmt::println("str_v: {}", str_v);
        // ReSharper disable once CppDFAInvalidatedMemory
        fmt::println("str_v1: {}", str_v1);
        // ReSharper disable once CppDFAInvalidatedMemory
        fmt::println("str_v2: {}\n", str_v2);

        fmt::println("str_v Address: {}", fmt::ptr(&str_v));
        fmt::println("str_v1 Address: {}", fmt::ptr(&str_v1));
        fmt::println("str_v2 Address: {}\n", fmt::ptr(&str_v2));
    }

    export void example_of_initialization() {
        // 1. Braced Initialization using c-string
        std::string_view str_v1{"Braced Initialized!"};
        fmt::println("string_view: {}", str_v1);

        // 2. Assignment with c-string
        std::string_view str_v2 = "Assignment Initialization";
        fmt::println("string_view: {}", str_v2);

        // 3. Using a std::string
        std::string str1{"String Variable Initialization"};
        std::string_view str_v3{str1};
        // std::string_view str_v4{"String Literal Initialization (Not Recommended)"s};
        fmt::println("string_view: {}", str_v3);
        // fmt::println("string_view: {}", str_v4);

        // 4. Using a c-string
        const char *cstr{"Using a const char point"};
        std::string_view str_v5{cstr};
        fmt::println("string_view: {}", str_v5);

        // 5. Using a const char array
        // ReSharper disable once CppVariableCanBeMadeConstexpr
        const char carr[]{"Using a const char []"}; // NOLINT(*-avoid-c-arrays)
        std::string_view str_v6{carr};
        fmt::println("string_view: {}", str_v6);

        // 6. Using a non-null terminating char array
        char carr2[]{ // NOLINT(*-avoid-c-arrays)
            'N', 'o', 'n', '-', 'n', 'u', 'l', 'l', ' ', 't', 'e', 'r', 'm', 'i', 'n', 'a', 't', 'i', 'n', 'g', ' ',
            's', 't', 'r', 'i', 'n', 'g',
        };
        std::string_view str_v7{carr2, std::size(carr2)}; // Array size needs to be passed
        fmt::println("string_view: {}", str_v7);

        // 7. Using another string view
        std::string_view str_v8{"Using a string view"};
        std::string_view str_v9{str_v8};
        fmt::println("string_view: {}\n", str_v9);
    }

    export void assignment_operator_changes_view() {
        fmt::println("Example of how assignment operator changes what std::string_view is viewing");
        std::string original_str{"Will I change?"};
        std::string_view viewing{original_str};

        fmt::println("Currently viewing: {}\n", viewing);

        viewing = "Did I change original_str?";

        fmt::println("Currently viewing: {}", viewing);
        fmt::println("original_str: {}\n", original_str);
    }

    export void changing_what_string_view_is_viewing() {
        fmt::println("Example of changing the view of a std::string_view:");
        std::string_view view_window{"The range in the distance is beautiful!"};
        fmt::println("Original View:");
        fmt::println("view_window: {}\n", view_window);

        // Shrinking view on the left-side
        view_window.remove_prefix(4); // Removes "The "
        fmt::println("Shrinking view on the left-side:");
        fmt::println("view_window: {}\n", view_window);

        // Shrinking view on the right-side
        view_window.remove_suffix(14); // Removes " is beautiful!" NOLINT(*-magic-numbers)
        fmt::println("Shrinking view on the right-side:");
        fmt::println("view_window: {}\n", view_window);

        fmt::println("Example of a std::string_view viewing a substring");
        std::string_view str_v{"snowball"};
        view_window = str_v.substr(0, 4);
        fmt::println("view_window: {}\n", view_window);
    }

    export void string_view_passed_to_other_data_type() {
        fmt::println("Example of passing a std::string_view to functions, that accept std::string objects");
        std::string_view str_v{"Hello!"};

        // Cannot implicitly convert std::string_view to std::string
        //print(str_v);

        // Cannot accept a std::string_view, under any circumstance
        // print_ref(str_v);

        // Cannot directly accept a std::string_view
        // Can be accepted if explicitly converted to std::string
        print_const_ref(std::string(str_v));
        fmt::println("");
    }

    export void string_view_parameter_example() {
        fmt::println("Example of function with std::string_view parameter:");
        std::string str{"std::string was passed!"};
        std::string_view sv{"std::string_view was passed!"}; // NOLINT(*-identifier-length)
        const char *cstr{"c-string was passed!"};

        print_view(str);
        print_view(sv);
        print_view(cstr);
        fmt::println("");
    }

    export void string_view_problems() {
        fmt::println("Problem: string_view Lifetime");
        fmt::println("Example 1 (Destroyed String Object):");
        std::string_view str_v{};

        {
            std::string str{"Can I be printed?"};
            str_v = str;
        }

        fmt::println("{}", str_v);
        fmt::println("");

        fmt::println("Example 2 (Temporary String Object):");
        std::string_view str_v2{"I'm a temporary string literal"s};
        fmt::println("{}", str_v2);
        fmt::println("");

        fmt::println("Problem: Modifying Underlying String Being Viewed");
        std::string original_string{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
        std::string_view viewing_original_string{original_string};

        original_string = "abcdefghijklmnopqrstuvwxyz1234567890";
        fmt::println("{}\n", viewing_original_string);

        fmt::println("Example 3 (std::string_view function)");
        fmt::println("Problem: Returning a std::string_view object");
        fmt::println("{}", get_name_of_bool(true));
        fmt::println("{}\n", get_name_of_bool(false));
    }
}
