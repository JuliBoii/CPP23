module;

#include <fmt/format.h>
#include <memory>
#include <cmath>

export module smart_ptrs;

std::unique_ptr<int> get_unique_ptr() {
    fmt::println("Inside function get_unique_ptr()");
    std::unique_ptr<int> ptr_u1 = std::make_unique<int>(142);
    fmt::println("unique_ptr address(in): {}", fmt::ptr(&ptr_u1));
    fmt::println("unique_ptr address(value): {}\n", fmt::ptr(ptr_u1.get()));
    return ptr_u1;
}

void do_something_with_int_unique(const std::unique_ptr<int> &unique_int_ptr) {
    // *unique_int_ptr = 42; // This does work
    // unique_int_ptr.reset(); // This will cause a compiler error
    fmt::println("Square of {} is {}\n", *unique_int_ptr, std::pow(*unique_int_ptr, 2));
}

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

    export void unique_ptr_as_parameter_or_return_value() {
        std::unique_ptr<int> ptr_u = std::make_unique<int>(4113);

        do_something_with_int_unique(ptr_u);

        do_something_with_int_unique(std::move(ptr_u));

        do_something_with_int_unique(std::make_unique<int>(142));

        std::unique_ptr<int> ptr_u2 = get_unique_ptr();
        fmt::println("Outside function get_unique_ptr:");
        fmt::println("unique_ptr address(in): {}", fmt::ptr(&ptr_u2));
        fmt::println("unique_ptr address(value): {}\n", fmt::ptr(ptr_u2.get()));

        fmt::println("Temporary Object Creation");
        fmt::println("unique_ptr address(value): {}", fmt::ptr(get_unique_ptr().get()));
    }

    export void unique_ptrs_and_arrays() {
        fmt::println("Using unique_ptr with arrays");
        // auto arr_ptr = std::unique_ptr<int[]>(new int[4]{1, 2, 3, 4});
        auto arr_ptr = std::make_unique<int[]>(4);
        // auto arr_ptr = std::make_unique<int[]>(4) {1, 2, 3, 4}; // Compiler Error
        // auto arr_ptr = std::make_unique<int[]>{1, 2, 3, 4}; // Compiler Error

        fmt::println("Printing array values");
        for (size_t i{0}; i < 4; i++) {
            fmt::println("{} ", arr_ptr[i]);
        }
        fmt::println("");
    }

    export void shared_ptr_example() {
        fmt::println("Example for Shared Pointers:");
        std::shared_ptr<int> shared_int_ptr_1{new int{30}};

        fmt::println("The pointed to value is: {}", *shared_int_ptr_1);
        *shared_int_ptr_1 = 40;
        fmt::println("The pointed to value is: {}", *shared_int_ptr_1);
        fmt::println("Use count = {}\n", shared_int_ptr_1.use_count());

        fmt::println("Copy Example:");
        std::shared_ptr<int> shared_int_ptr_2 = shared_int_ptr_1;

        fmt::println("shared_int_ptr_2 value: {}", *shared_int_ptr_2);
        *shared_int_ptr_2 = 548;
        fmt::println("shared_int_ptr_2 value: {}", *shared_int_ptr_2);
        fmt::println("use count for shared_int_ptr_1: {}", shared_int_ptr_1.use_count());
        fmt::println("use count for shared_int_ptr_2: {}\n", shared_int_ptr_2.use_count());

        fmt::println("Other Methods for Initialization:");
        fmt::println("Declared & Initialized shared_int_ptr_3");
        std::shared_ptr<int> shared_int_ptr_3;
        shared_int_ptr_3 = shared_int_ptr_1;

        fmt::println("Declared & Initialized shared_int_ptr_4");
        std::shared_ptr<int> shared_int_ptr_4{nullptr};
        shared_int_ptr_4 = shared_int_ptr_1;

        fmt::println("Declared & Initialized shared_int_ptr_5");
        std::shared_ptr<int> shared_int_ptr_5{shared_int_ptr_1};

        fmt::println("shared_int_ptr_5 value: {}", *shared_int_ptr_5);
        *shared_int_ptr_5 = 314;
        fmt::println("shared_int_ptr_5 value: {}", *shared_int_ptr_5);
        fmt::println("use count for shared_int_ptr_1: {}", shared_int_ptr_1.use_count());
        fmt::println("use count for shared_int_ptr_5: {}\n", shared_int_ptr_5.use_count());

        fmt::println("Use a Shared Pointer to Manage An Already Existing Piece of Memory:");
        auto raw_int_ptr{new int{33}};

        std::shared_ptr<int> shared_int_ptr_6{raw_int_ptr};
        raw_int_ptr = nullptr;
        fmt::println("Value pointed to by raw_int_ptr is(using shared_ptr): {}", *shared_int_ptr_6);
        fmt::println("Use count for shared_int_ptr_6 is: {}", shared_int_ptr_6.use_count());
        fmt::println("raw pointer: {}", fmt::ptr(raw_int_ptr));
        fmt::println("shared_int_ptr_6.get(): {}\n", fmt::ptr(shared_int_ptr_6.get()));

        fmt::println("Using Reset on Shared Pointers:");
        shared_int_ptr_5.reset();
        fmt::println("Current shared_int_ptr_1.use_count(): {:>9}", shared_int_ptr_1.use_count());
        fmt::println("Current shared_int_ptr_1.get(): {:>15}", fmt::ptr(shared_int_ptr_1.get()));
        fmt::println("Current shared_int_ptr_5.use_count(): {:>9}", shared_int_ptr_5.use_count());
        fmt::println("Current shared_int_ptr_5.get(): {:>15}\n", fmt::ptr(shared_int_ptr_5.get()));

        shared_int_ptr_4.reset();
        fmt::println("Current shared_int_ptr_1.use_count(): {:>9}", shared_int_ptr_1.use_count());
        fmt::println("Current shared_int_ptr_1.get(): {:>15}", fmt::ptr(shared_int_ptr_1.get()));
        fmt::println("Current shared_int_ptr_4.use_count(): {:>9}", shared_int_ptr_4.use_count());
        fmt::println("Current shared_int_ptr_4.get(): {:>15}\n", fmt::ptr(shared_int_ptr_4.get()));

        shared_int_ptr_3.reset();
        fmt::println("Current shared_int_ptr_1.use_count(): {:>9}", shared_int_ptr_1.use_count());
        fmt::println("Current shared_int_ptr_1.get(): {:>15}", fmt::ptr(shared_int_ptr_1.get()));
        fmt::println("Current shared_int_ptr_3.use_count(): {:>9}", shared_int_ptr_3.use_count());
        fmt::println("Current shared_int_ptr_3.get(): {:>15}\n", fmt::ptr(shared_int_ptr_3.get()));

        shared_int_ptr_2.reset();
        fmt::println("Current shared_int_ptr_1.use_count(): {:>9}", shared_int_ptr_1.use_count());
        fmt::println("Current shared_int_ptr_1.get(): {:>15}", fmt::ptr(shared_int_ptr_1.get()));
        fmt::println("Current shared_int_ptr_2.use_count(): {:>9}", shared_int_ptr_2.use_count());
        fmt::println("Current shared_int_ptr_2.get(): {:>15}\n", fmt::ptr(shared_int_ptr_2.get()));

        fmt::println("Current shared_int_ptr_1.use_count(): {:>9}", shared_int_ptr_1.use_count());
        fmt::println("Current shared_int_ptr_1.get(): {:>15}\n", fmt::ptr(shared_int_ptr_1.get()));

        fmt::println("Using std::make_shared:");
        std::shared_ptr<int> shared_int_ptr_7 = std::make_shared<int>(455);
        fmt::println("Value stored in shared_int_ptr_7: {}", *shared_int_ptr_7);
        fmt::println("Use count for shared_int_ptr_7 is: {}\n", shared_int_ptr_7.use_count());

        fmt::println("Overall example:");
        std::shared_ptr<int> shared_int_ptr_8{shared_int_ptr_7};
        fmt::println("shared_int_ptr_7.use_count(): {}", shared_int_ptr_7.use_count());

        fmt::println("Reset shared_int_ptr_7");
        shared_int_ptr_7.reset();

        fmt::println("shared_int_ptr_7.use_count(): {}", shared_int_ptr_7.use_count());
        fmt::println("shared_int_ptr_8.use_count(): {}", shared_int_ptr_8.use_count());
    }
}
