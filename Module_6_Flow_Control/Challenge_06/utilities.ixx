module;

#include <SFML/Graphics.hpp>
#include <fmt/format.h>
#include <string>

export module utilities;

export void app() {
    // Storing data in pre-defined variable for window and shapes
    unsigned int window_width{1920u};
    unsigned int window_height{1080u};
    float circle_radius{200.0f};
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

            // Added Mouse Button Events
            if (const auto *mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                // Each button on the mouse changes the color of the shape
                if (mousePressed->button == sf::Mouse::Button::Left) {
                    // Checks if we already changed the color
                    // So we do not have to redo the command
                    if (shape.getFillColor() != sf::Color::Magenta)
                        shape.setFillColor(sf::Color::Magenta);
                }

                if (mousePressed->button == sf::Mouse::Button::Right) {
                    if (shape.getFillColor() != sf::Color::Cyan)
                        shape.setFillColor(sf::Color::Cyan);
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
