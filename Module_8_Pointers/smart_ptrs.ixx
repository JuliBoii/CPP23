module;

#include <fmt/format.h>
#include <memory>

export module smart_ptrs;

namespace smart_ptrs {
    export void unique_ptr_example() {
        fmt::println("Unique Pointer Example:");
        int *ptr_int{new int{30}};
        std::unique_ptr<int> unique_int{ptr_int};

        fmt::println("Unique Pointer Initialized with Stack Variable:");
        fmt::println("Value is: {}", *unique_int);
        fmt::println("Value located at address: {}\n", fmt::ptr(unique_int.get()));

        std::unique_ptr<int> unique_int1{new int{50}};
        // std::unique_ptr<int> unique_int2{nullptr};
        const std::unique_ptr<int> unique_int2{std::make_unique<int>(79)};

        fmt::println("Unique Pointer Initialized with Dynamically Allocated Memory:");
        fmt::println("Value is: {}", *unique_int1);
        fmt::println("Value located at address: {}\n", fmt::ptr(unique_int1.get()));

        fmt::println("Unique Pointer Initialized with nullptr or make_unique:");
        if (unique_int2) {
            fmt::println("Value is: {}", *unique_int2);
            fmt::println("Value located at address: {}\n", fmt::ptr(unique_int2.get()));
        } else {
            fmt::println("nullptr.\n");
        }
    }
}
