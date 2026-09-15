module;

#include <SFML/Graphics.hpp>
#include <fmt/format.h>
#include <string>

export module utilities;

export void app() {
    // Storing data in pre-defined variable for window and shapes
    unsigned int window_width{1920u};
    unsigned int window_height{1080u};
    constexpr float circle_radius{200.0f};
    const std::string window_title{"SFML Challenge 05"};
    sf::Color circle_color{128, 0, 0, 255};
    sf::Color bg_color{255, 255, 255, 255};

    // Creating Window & setting parameters
    auto window = sf::RenderWindow(sf::VideoMode({window_width, window_height}), window_title);
    window.setFramerateLimit(60);

    // Creating a Shape
    auto shape = sf::CircleShape{circle_radius};
    shape.setFillColor(circle_color);

    // Setting position of circle when first rendered to window
    sf::Vector2f circle_position{
        (static_cast<float>(window_width) / 2) - circle_radius, (static_cast<float>(window_height) / 2) - circle_radius
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
        window.draw(shape);
        window.display();
    }
}
