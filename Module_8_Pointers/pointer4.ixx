module;

#include <print>
#include <fmt/format.h>

export module pointer4;


namespace pointer4 {
    export void pointer_arithmetic_navigation() {
        int scores[10]{11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

        // scores++;

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
    }
}
