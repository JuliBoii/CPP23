module;

#include <fmt/format.h>
#include <print>

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
        fmt::println("number1 Address: {}\n", static_cast<void *>(&number1));

        fmt::println("Reassigning the value stored through a the pointer:");
        *ptr_number1 = 432;
        fmt::println("ptr_number1 Address: {}", static_cast<void *>(ptr_number1));
        fmt::println("ptr_number1 Value Pointed To: {}", *ptr_number1);
        fmt::println("number1 Value Stored: {}", number1);
        fmt::println("number1 Address: {}\n", static_cast<void *>(&number1));

        int number2{41};

        fmt::println("Reassigning the pointer");
        ptr_number1 = &number2;
        fmt::println("ptr_number1 Address: {}", static_cast<void *>(ptr_number1));
        fmt::println("ptr_number1 Value Pointed To: {}", *ptr_number1);
        fmt::println("number1 Value Stored: {}", number1);
        fmt::println("number1 Address: {}", static_cast<void *>(&number1));
        fmt::println("number2 Value Stored: {}", number2);
        fmt::println("number2 Address: {}\n", static_cast<void *>(&number2));
    }

    export void modifiable_pointer_to_const_data() {
        /*fmt::println("Case: Modifiable Pointer to Const Data");

        int *p_number1(nullptr);
        constexpr int number1{6632};
        p_number1 = &number1;*/
    }

    export void semi_const_pointer_to_modifiable_data() {
        fmt::println("Case: Const Pointer to Non-const Data");
        int number1{4214};
        const int *p_number1{&number1};

        fmt::println("p_number1 Value Pointed To: {}", *p_number1);
        fmt::println("p_number1 Address Stored: {}", static_cast<const void *>(p_number1));
        fmt::println("number1 Value Stored: {}", number1);
        fmt::println("number1 Address: {}\n", static_cast<void *>(&number1));
        // std::println("p_number1 Value Pointed To: {}", *p_number1);
        // std::println("p_number1 Address Stored: {}", static_cast<const void *>(p_number1));

        fmt::println("Modifying the value pointed to by p_number1: (Compiler Error)\n");
        // *p_number1 = 4321;

        fmt::println("Modifying number1");
        number1 = 14;
        fmt::println("p_number1 Value Pointed To: {}", *p_number1);
        fmt::println("p_number1 Address Stored: {}", static_cast<const void *>(p_number1));
        fmt::println("number1 Value Stored: {}", number1);
        fmt::println("number1 Address: {}\n", static_cast<void *>(&number1));

        fmt::println("Changing the address stored in p_number1:");
        int number2{54};
        p_number1 = &number2;
        fmt::println("p_number1 Value Pointed To: {}", *p_number1);
        fmt::println("p_number1 Address Stored: {}", static_cast<const void *>(p_number1));
        fmt::println("number1 Value Stored: {}", number1);
        fmt::println("number1 Address: {}", static_cast<void *>(&number1));
        fmt::println("number2 Value Stored: {}", number2);
        fmt::println("number2 Address: {}\n", static_cast<void *>(&number2));

        fmt::println("Making the variable explicitly constant when declaring & initializing:");
        constexpr int protected_number{4214};
        const int *p_protected_number{&protected_number};
    }

    export void const_pointer_to_const_data() {
        fmt::println("Case: Const Pointer to Const Data");
    }
}
