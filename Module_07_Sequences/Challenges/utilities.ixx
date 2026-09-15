module;

#include <SFML/Graphics.hpp>
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

namespace iteration1 {
    export void app() {
        // Storing data in pre-defined variable for window and shapes
        unsigned int window_width{1920u};
        unsigned int window_height{1080u};
        const std::string window_title{"SFML Challenge 05"};
        constexpr sf::Color bg_color{255, 255, 255, 255};


        // Creating Window & setting parameters
        auto window = sf::RenderWindow(sf::VideoMode({window_width, window_height}), window_title);
        window.setFramerateLimit(60);

        // Creating a Shape
        float circle_radius{200.0f};
        sf::Color circle_color{128, 0, 0, 255};
        auto shape = sf::CircleShape{circle_radius};
        shape.setFillColor(circle_color);

        // Setting position of circle when first rendered to window
        sf::Vector2f circle_position{
            (static_cast<float>(window_width) / 2) - circle_radius,
            (static_cast<float>(window_height) / 2) - circle_radius
        };
        shape.setPosition(circle_position);


        // Main loop
        while (window.isOpen()) {
            // Checking for events
            while (const std::optional event = window.pollEvent()) {
                // Checking if window is closed
                if (event->is<sf::Event::Closed>()) {
                    window.close();
                }
                // Checking for keyboard input from user
                else if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                    if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                        window.close();
                    }

                    // When "c" is pressed the shape increases in scale
                    // with the shapes position accounting for new scale
                    if (keyPressed->scancode == sf::Keyboard::Scancode::C) {
                        shape.setRadius(circle_radius += 10.0f);
                        circle_position.x -= 10.0f;
                        circle_position.y -= 10.0f;
                        shape.setPosition(circle_position);
                    }

                    // When "d" is pressed the shape decreases in scale
                    // with the shapes position accounting for new scale
                    if (keyPressed->scancode == sf::Keyboard::Scancode::D) {
                        shape.setRadius(circle_radius -= 10.0f);
                        circle_position.x += 10.0f;
                        circle_position.y += 10.0f;
                        shape.setPosition(circle_position);
                    }

                    // Arrow keys move the shape
                    if (keyPressed->scancode == sf::Keyboard::Scancode::Left) {
                        // fmt::println("Moving Left");
                        circle_position.x -= 10;
                        shape.setPosition(circle_position);
                    }

                    if (keyPressed->scancode == sf::Keyboard::Scancode::Right) {
                        // fmt::println("Moving Right");
                        circle_position.x += 10;
                        shape.setPosition(circle_position);
                    }

                    if (keyPressed->scancode == sf::Keyboard::Scancode::Up) {
                        // fmt::println("Moving Forward");
                        circle_position.y -= 10;
                        shape.setPosition(circle_position);
                    }

                    if (keyPressed->scancode == sf::Keyboard::Scancode::Down) {
                        // fmt::println("Moving Backward");
                        circle_position.y += 10;
                        shape.setPosition(circle_position);
                    }
                }

                // Outputs new dimensions when window is resized by user
                if (const auto *resized = event->getIf<sf::Event::Resized>()) {
                    fmt::println("New Width: {}", resized->size.x);
                    fmt::println("New Height: {}", resized->size.y);
                }
            }

            // Renders to window
            window.clear(bg_color);
            // window.draw(shape);
            window.display();
        }
    }
}
