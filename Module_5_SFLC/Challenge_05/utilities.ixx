module;

#include <SMFL/Graphics.hpp>
#include <string>

export module utilities;

export void app()
{
    // Store data in pre-defined variable
    size_t window_width{1920u};
    size_t window_height{1080u};
    constexpr float circle_radius{200.0f};
    const std::string window_title{"SFML Challenge 05"};
    constexpr sf::Color circle_color{128, 0, 0, 255};
    constexpr sf::Color bg_color{255, 255, 255, 255};

    auto window = sf::RenderWindow(sf::VideoMode({window_width, window_height}), window_title);
    window.setFramerateLimit(60);
    auto shape = sf::CircleShape{circle_radius};
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
        window.clear(bg_color);
        window.draw(shape);
        window.display();
    }
}