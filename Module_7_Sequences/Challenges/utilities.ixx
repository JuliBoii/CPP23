module;

#include <fmt/format.h>
#include <random>
#include <string>
#include <vector>
#include <iostream>

export module utilities;

export void fortune_teller() {
    const std::vector<std::string> predictions{
        "I see a lot of kids running in the street!",
        "I see a lot of empty beer bottles on your work table.",
        "I see you partying too much with kids wearing weird clothes.",
        "I see you running away from something really scary",
        "I see clouds gathering in the sky with an army standing ready for war",
        "I see dogs running around in a deserted city",
        "I see a lot of cars stuck in a terrible traffic jam",
        "I see you sitting in the dark typing lots of lines of code on your dirty computer",
        "I see you yelling at your boss. And oh no! You get fired!",
        "I see you laughing your lungs out. I've never seen this before.",
        "Uhm , I don't see anything!",
        "I see you eating nice food",
        "I see you encountering a tough challenge that will significantly impact your life."
    };

    // Setting up random index generation
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<size_t> dist(0, predictions.size() - 1);

    bool end_program{false};

    // Obtaining user's name
    std::string user_name{};
    fmt::println("What is your name?");
    std::getline(std::cin, user_name);

    fmt::println("Hello {}...", user_name);
    // Loop to obtain various predictions, until user wants to end program
    while (!end_program) {
        // Generate a random index
        size_t random_index{dist(rng)};
        fmt::println("{}", predictions[random_index]);

        fmt::print("Would you like another prediction? (Y or y to continue): ");
        char continue_prediction{};
        std::cin >> continue_prediction;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

        end_program = !(continue_prediction == 'y' || continue_prediction == 'Y');
    }

    fmt::println("Thank you for stopping by! Until next time.");
}
