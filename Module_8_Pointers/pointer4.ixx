module;

#include <print>
#include <cstddef>
#include <fmt/format.h>

export module pointer4;


namespace pointer4 {
    export void pointer_arithmetic_navigation() {
        int scores[10]{11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

        // scores++; // Compiler Error

        int *p_score{scores};
        fmt::println("Values in scores array (p_score pointer increment): ");
        fmt::println("Address: {}, Value: {}", fmt::ptr(p_score), *p_score);

        ++p_score; // Moves forward by sizeof(int): 4 bytes
        fmt::println("Address: {}, Value: {}", fmt::ptr(p_score), *p_score);

        ++p_score; // Moves forward by sizeof(int): 4 bytes
        fmt::println("Address: {}, Value: {}", fmt::ptr(p_score), *p_score);

        ++p_score; // Moves forward by sizeof(int): 4 bytes
        fmt::println("Address: {}, Value: {}", fmt::ptr(p_score), *p_score);

        ++p_score; // Moves forward by sizeof(int): 4 bytes
        fmt::println("Address: {}, Value: {}", fmt::ptr(p_score), *p_score);

        ++p_score; // Moves forward by sizeof(int): 4 bytes
        fmt::println("Address: {}, Value: {}", fmt::ptr(p_score), *p_score);

        fmt::println("\nExplicit Addition of Integer:");
        p_score = scores; // Reset the pointer to the start of the array.
        fmt::println("scores[4]: {}", *(p_score + 4)); // Moves forward by 4 * sizeof(int) = 16 bytes

        fmt::println("\nPrinting Array using pointer arithmetic:");
        p_score = scores;
        for (size_t i{0}; i < std::size(scores); ++i) {
            fmt::println("Value: {}", *(p_score + i)); // scores[i]
        }

        fmt::println("");
        for (size_t i{0}; i < std::size(scores); ++i) {
            fmt::println("Value: {}", *(scores + i));
        }
        fmt::println("");
    }

    export void pointer_arithmetic_distance() {
        int scores[10]{11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

        /*
         * Array index notation
         * int *pointer1 {&scores[0]};
         * int *pointer2 {&scores[1]};
         */

        int *pointer0{scores + 0};
        int *pointer1{scores + 8};

        fmt::println("pointer1 - pointer0: {}", pointer1 - pointer0);
        fmt::println("pointer0 - pointer1: {}\n", pointer0 - pointer1);

        std::ptrdiff_t pos_diff = pointer1 - pointer0;
        std::ptrdiff_t neg_diff = pointer0 - pointer1;
        fmt::println("pointer1 - pointer0: {}", pos_diff);
        fmt::println("pointer0 - pointer1: {}\n", neg_diff);

        fmt::println("sizeof(std::ptrdiff_t): {}\n", sizeof(std::ptrdiff_t));
        }

    export void pointer_arithmetic_comparisons()
    {
        int scores[10] {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        int *pointer0{&scores[0]};
        int *pointer1{&scores[7]};

        fmt::println("pointer0: {}", *pointer0);
        fmt::println("pointer0: {}", fmt::ptr(pointer0));
        fmt::println("pointer1: {}",*pointer1);
        fmt::println("pointer1: {}\n",fmt::ptr(pointer1));

        // Can also do comparisons
        // Further you go in the array, the bigger the address
        fmt::println("Comparing pointers:");
        fmt::println("pointer0 > pointer1: {}", pointer0 > pointer1);
        fmt::println("pointer0 < pointer1: {}", pointer0 < pointer1);
        fmt::println("pointer0 >= pointer1: {}", pointer0 >= pointer1);
        fmt::println("pointer0 <= pointer1: {}", pointer0 <= pointer1);
        fmt::println("pointer0 == pointer1: {}", pointer0 == pointer1);
        fmt::println("pointer0 != pointer1: {}", pointer0 != pointer1);
    }
}
