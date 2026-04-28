module;

#include <fmt/format.h>
#include <print>

export module pointer3;

namespace pointer3 {
    export void pointer_and_array_relationship() {
        std::println("Relationship Between Pointers & Array's");
        int scores[10]{11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        int *p_scores{scores};

        // std::println("{}", *scores);

        std::println("Printing the addresses:");
        std::println("scores: {}", static_cast<void *>(scores));
        std::println("p_scores: {}", static_cast<void *>(p_scores));
        std::println("&scores[0]: {}\n", static_cast<void *>(&scores[0]));

        std::println("Printing the data:");
        std::println("*scores: {}", *scores);
        std::println("*p_scores: {}", *p_scores);
        std::println("scores[0]: {}", scores[0]);
        std::println("p_scores[0]: {}\n", p_scores[0]);

        std::println("Attempting to reassign our pointer and array variable:");
        [[maybe_unused]] int number1{245};
        p_scores = &number1;
        // scores = &number1;
        std::println("p_scores: {}", static_cast<void *>(p_scores));
    }
}
