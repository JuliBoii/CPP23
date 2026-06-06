module;

#include <fmt/format.h>
#include <print>

export module dynamic_memory_allocation;

namespace dynamic_memory_allocation {
    export void pointers_gone_bad() {
        // Bad
        // Writing into uninitialized pointer through dereference
        /*int *p_number2; // Contains junk address: could be anything
        fmt::println("Assigning value 55 to pointer");
        *p_number2 = 55;
        fmt::println("p_number2: {}", fmt::ptr(p_number2)); // Reading from junk address
        fmt::println("Dereferencing bad memory");
        fmt::println("*p_number2: {}", *p_number2);*/

        int *p_number1{};
        fmt::println("Assigning value to nullptr address");
        // *p_number1 = 5;
        fmt::println("p_number1: {}\n", fmt::ptr(p_number1));
        // fmt::println("*p_number1: {}", *p_number1);
    }

    export void dynamic_heap_memory() {
        int *p_number{nullptr};

        p_number = new int;

        *p_number = 7741;
        fmt::println("Dynamically allocating memory:");
        fmt::println("*p_number: {}\n", *p_number);

        delete p_number;
        p_number = nullptr;


        fmt::println("Alternate Methods for Initializing Dynamically Allocated Memory:");
        int *ptr_number1{new int};
        int *ptr_number2{new int(22)};
        int *ptr_number3{new int{23}};

        fmt::println("ptr_number1: {}", fmt::ptr(ptr_number1));
        fmt::println("*ptr_number1: {}\n", *ptr_number1);

        fmt::println("ptr_number2: {}", fmt::ptr(ptr_number2));
        fmt::println("*ptr_number2: {}\n", *ptr_number2);

        fmt::println("ptr_number3: {}", fmt::ptr(ptr_number3));
        fmt::println("*ptr_number3: {}\n", *ptr_number3);

        delete ptr_number1;
        ptr_number1 = nullptr;

        delete ptr_number2;
        ptr_number2 = nullptr;

        delete ptr_number3;
        ptr_number3 = nullptr;

        fmt::println("Resuing ptr_number1");
        ptr_number1 = new int{41};

        fmt::println("ptr_number1: {}", fmt::ptr(ptr_number1));
        fmt::println("*ptr_number1: {}\n", *ptr_number1);

        delete ptr_number1;
        ptr_number1 = nullptr;

        // Calling the delete operator twice on a single dynamically allocated pointer
        /*ptr_number1 = new int{42134};

        fmt::println("ptr_number1: {}", fmt::ptr(ptr_number1));
        fmt::println("*ptr_number1: {}\n", *ptr_number1);

        delete ptr_number1;
        delete ptr_number1;
        ptr_number1 = nullptr;*/
    }
}
