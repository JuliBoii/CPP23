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

        fmt::println("Moving a unique_ptr to another unique_ptr:");
        std::unique_ptr<int> unique_int3 = std::make_unique<int>(110);
        fmt::println("unique_int3 points at address : {}\n", fmt::ptr(unique_int3.get()));
        {
            std::unique_ptr<int> unique_int4 = std::move(unique_int3);
            fmt::println("unique_int4 points at address: {}", fmt::ptr(unique_int4.get()));
            fmt::println("unique_int3 points to nullptr: {}", fmt::ptr(unique_int3.get()));

            if (unique_int3) {
                fmt::println("unique_int3 is pointing to something valid");
            } else {
                fmt::println("unique_int3 is pointing to nullptr");
            }
        }
        fmt::println("Outside the scope\n");

        fmt::println("Resetting a unique_ptr:");
        std::unique_ptr<int> unique_int5 = std::make_unique<int>(140);

        unique_int5.reset();

        if (unique_int5) {
            fmt::println("unique_int5 points to a valid address: {}\n", fmt::ptr(unique_int5.get()));
        } else {
            fmt::println("unique_int5 points to nullptr: {}\n", fmt::ptr(unique_int5.get()));
        }
    }
}
