module;

#include <fmt/format.h>
#include <print>

export module pointer3;

namespace pointer3 {
    export void pointer_and_array_relationship() {
        std::println("Relationship Between Pointers & Array's");
        int scores[10]{11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        int *p_scores{scores};
    }
}
