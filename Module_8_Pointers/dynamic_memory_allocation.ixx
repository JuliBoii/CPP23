module;

#include <fmt/format.h>
#include <print>
#include <exception>
#include <new>

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

    export void dynamic_memory_dangling_pointers() {
        /* // Case: uninitialized pointer
         * int * p_number; // Dangling uninitialized pointer
         *
         * fmt::println( "Case 1: Uninitialized pointer." );
         * fmt::println( "p_number: {}", fmt::ptr(p_number));
         * fmt::println( "*p_number: {}" , *p_number); //CRASH!
         *
        */

        /* //Case: Deleted Pointer
         * fmt::println( "Case 2: Deleted pointer" );
         * int * p_number1 {new int{67}};
         *
         * fmt::println( "*p_number1 (before delete): {}", *p_number1 );
         * delete p_number1;
         * fmt::println( "*p_number1(after delete): {}", *p_number1 );
         *
         */

        // Solution 1 & 2 : Initialize your pointers immediately upon declaration & deletion
        fmt::println("Solution (Uninitialized & Deleted Pointers):");
        int *p_number5{nullptr};
        int *p_number6{new int(87)};

        if (p_number6 != nullptr) {
            fmt::println("p_number6 - {} - {}", fmt::ptr(p_number6), *p_number6);
        } else {
            fmt::println("Invalid address");
        }

        // Simplified variation of previous if statement
        // "if p_number5 is not 0/nullptr"
        if (p_number5) {
            fmt::println("p_number5 - {} - {}", fmt::ptr(p_number5), *p_number5);
        } else {
            fmt::println("Invalid address: p_number5");
        }

        delete p_number6;
        p_number6 = nullptr;

        if (!(p_number6 == nullptr)) {
            fmt::println("p_number6 - {} - {}\n", fmt::ptr(p_number6), *p_number6);
        } else {
            fmt::println("Invalid address: p_number6\n");
        }

        // Case 3 : Multiple pointers pointing to same address
        /*int *p_number{new int{41}};
        int *p_number1{p_number};
        int *p_number2{p_number};
        int *p_number3{p_number};

        fmt::println("p_number: {} contains {}", fmt::ptr(p_number), *p_number);
        fmt::println("p_number1: {} contains {}", fmt::ptr(p_number1), *p_number1);
        fmt::println("p_number2: {} contains {}", fmt::ptr(p_number2), *p_number2);
        fmt::println("p_number3: {} contains {}\n", fmt::ptr(p_number3), *p_number3);

        fmt::println("Release the memory address for p_number3:\n");
        delete p_number3;
        p_number3 = nullptr;

        // fmt::println("p_number: {} contains {}", fmt::ptr(p_number), *p_number);
        fmt::println("p_number1: {} contains {}", fmt::ptr(p_number1), *p_number1);
        fmt::println("p_number2: {} contains {}", fmt::ptr(p_number2), *p_number2);
        fmt::println("p_number3: {} contains {}\n", fmt::ptr(p_number3), *p_number3);*/

        // Solution 3
        fmt::println("Solution (Multiple Pointers Pointing to Same Memory Address): ");
        int *p_number{new int{382}};
        const int *p_number1{p_number};

        // Dereference the pointers and use them
        fmt::println("p_number - {} : {}", fmt::ptr(p_number), *p_number);

        if (!(p_number == nullptr)) {
            fmt::println("p_number1 - {} : {}", fmt::ptr(p_number1), *p_number1);
        }

        delete p_number;
        p_number = nullptr;

        // *p_number1 = 1341; // Cannot manipulate data

        if (!(p_number == nullptr)) {
            fmt::println("p_number1 - {} : {}\n", fmt::ptr(p_number1), *p_number1);
        } else {
            fmt::println("WARNING : Trying to use an invalid pointer\n");
        }
    }

    export void new_fail_examples() {
        // int* data = new int[100000000000000];

        // for (size_t i{0}; i < 100000000000000; ++i)
        // {
        //     std::println("Iteration: {}", i);
        //     int* data = new int[100000000000000];
        // }

        /*try
        {
            for (size_t index = 0; index < 10000000; index++)
            {
                fmt::println("iteration: {}", index);
                int *p_number = new int[100000000000];
            }
        }
        catch (std::exception& e)
        {
            fmt::println("Something went wrong: {}", e.what());
        }*/

        for (size_t i{0}; i < 10; ++i) {
            int *data = new(std::nothrow) int[10000000000000];
            if (data != nullptr) {
                fmt::println("Data Allocated");
            } else {
                fmt::println("Data Allocation Failed");
            }
        }
        fmt::println("");
    }

    export void using_delete_on_nullptr() {
        fmt::println("Using delete operator on nullptr");
        int *data{nullptr}; // Better to be explicit when initializing a pointer to nullptr
        // int* data {};

        fmt::println("Deleting pointer:\n");
        delete data;

        fmt::println("Checking if data contains nullptr:");
        if (data != nullptr) {
            fmt::println("Does not contain nullptr.\n");
            delete data;
        } else {
            fmt::println("Contains nullptr.\n");
        }
    }
}
