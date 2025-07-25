module;

// Global Module Fragment
// Where we put our include statements
#include <SFML/Graphics.hpp>
#include <string>

export module utilities; // Module definition

// Module purview

export void app() {

    // Store data in pre-defined variable
    unsigned int window_width{1920u};
    unsigned int window_height{1080u};
    constexpr float circle_radius{200.0f};
    const std::string window_title{"SFML Challenge!"};
    constexpr sf::Color circle_color{128,0,0,255};
    constexpr sf::Color background_color{255,255,255,255};

    auto window = sf::RenderWindow(sf::VideoMode({window_width, window_height}), window_title);
    window.setFramerateLimit(144);
    auto shape = sf::CircleShape(circle_radius);
    shape.setFillColor(circle_color);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear(background_color);
        window.draw(shape);
        window.display();
    }
}
