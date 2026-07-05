module;

#include <string>
#include <fmt/format.h>

export module string_literal;

using namespace std::literals::string_literals;

namespace string_literals {
    export void handling_escape_sequences() {
        fmt::println("Example of Raw String Literals:");
        std::string path = "C:\\Program Files\\App\\"; // NOLINT(*-raw-string-literal)
        std::string windows_path = R"(C:\Program Files\App\)";
        std::string unix_path = R"unixpath(/usr/bin/cmake)unixpath";

        fmt::println("Old method:");
        fmt::println("path: {}\n", path);

        fmt::println("Since C++11 and beyond:");
        fmt::println("windows_path: {}", windows_path);
        fmt::println("unix_path: {}\n", unix_path);

        const char *c_string_raw_literal{
            R"(    Clean the house
    Walk the dog
    Do Laundry
    Pick up groceries
        )"
        };

        fmt::println("Can also be used with C-Strings:");
        fmt::println("{}", c_string_raw_literal);
    }
}
