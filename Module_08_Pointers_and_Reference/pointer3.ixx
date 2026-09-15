module;

#include <fmt/format.h>
#include <print>
#include <vector>

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
        std::println("p_scores: {}\n", static_cast<void *>(p_scores));

        std::println("Attempting to print the size of a raw array:");
        // std::println("size: {}", std::size(p_scores));
        std::println("size: {}\n", std::size(scores));
    }

    export void swapping_addresses_example() {
        std::println("Swapping Addresses");
        int arr0[5]{1, 2, 3, 4, 5};
        int arr1[5]{6, 7, 8, 9, 10};
        int *p_arr0{arr0};
        int *p_arr1{arr1};
        int *temp_ptr{nullptr};

        std::println("Before Swap:");
        std::println("arr0:");
        for (const auto &item: arr0) {
            std::print("{}, ", item);
        }
        std::println("");

        std::println("arr1:");
        for (const auto &item: arr1) {
            std::print("{}, ", item);
        }
        std::println("");

        // Array name is not assignable so:
        // We work with pointers to swap
        temp_ptr = p_arr1;
        p_arr1 = p_arr0;
        p_arr0 = temp_ptr;

        std::println("\nAfter Swap:");
        std::println("arr0:");
        for (size_t i = 0; i < std::size(arr0); ++i) {
            std::print("{}, ", p_arr0[i]);
        }
        std::println("");

        std::println("arr1:");
        for (size_t i = 0; i < std::size(arr1); ++i) {
            std::print("{}, ", p_arr1[i]);
        }
        std::println("\n");

        std::println("Swapping Data (More Verbose):");
        int temp_arr[5]{};

        // Make a copy of arr0
        for (size_t i = 0; i < std::size(arr0); ++i) {
            temp_arr[i] = arr0[i];
        }

        // Swap Data
        for (size_t i = 0; i < std::size(arr1); ++i) {
            arr0[i] = arr1[i];
            arr1[i] = temp_arr[i];
        }

        std::println("After Data Swap:");
        std::println("arr0:");
        for (const auto &item: arr0) {
            std::print("{}, ", item);
        }
        std::println("");

        std::println("arr1:");
        for (const auto &item: arr1) {
            std::print("{}, ", item);
        }
        std::println("");

        /*
         * The swap goes from being O(1) to O(n)
         * That is why it is more efficient to work with pointers
         * Rather than manually swapping each element
         */
    }
}
