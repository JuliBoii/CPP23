module;

#include <fmt/format.h>

export module pointer2;

namespace pointer2 {
    export void modifiable_raw_data() {
        fmt::println("Case: Modifiable Variable");

        int number{5}; // Not const

        fmt::println("Number: {}", number);
        fmt::println("Number Address: {}", static_cast<void *>(&number));
        fmt::println("");

        fmt::println("Modifying 'number':");
        number = 12;
        number += 13;

        fmt::println("New Number: {}", number);
        fmt::println("Number Address: {}\n", static_cast<void *>(&number));
    }

    export void modifiable_data_and_modifiable_pointer() {
        fmt::println("Case: Modifiable Variable & Pointer");
        int *ptr_number1(nullptr);
        int number1{23};

        ptr_number1 = &number1;
        fmt::println("ptr_number1 Address: {}", static_cast<void *>(ptr_number1));
        fmt::println("ptr_number1 Value Pointed To: {}", *ptr_number1);
        fmt::println("number1 Value Stored: {}", number1);
    }
}
