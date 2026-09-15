module;

// Global Module Fragment
// Where we put our include statements
# include <string_view>
# include <SFML/Graphics.hpp>
# include <fmt/format.h>

export module utilities; // Module definition

// Module purview
export void print_msg(std::string_view str) {
    fmt::print("{}\n", str);
}

export void app() {
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);
    auto shape = sf::CircleShape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}

/*
export int add_numbers(const int& a, const int& b) {
    return a + b;
}

export void print_number(const int& num) {
    fmt::print("Number is: {}\n", num);
}
*/
