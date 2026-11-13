module;

#include <cstdint>
#include <fmt/format.h>

export module custom_types;

namespace custom_types_struct {
    export struct Pixel {
        std::uint32_t m_color{0xFF000000};
        unsigned int x_position{0};
        unsigned int y_position{0};
    };

    export struct Pixel_P {
    private:
        std::uint32_t m_color{0xFF000000};
        unsigned int x_position{0};
        unsigned int y_position{0};
    };
}

namespace custom_types_class {
    export class Pixel_P {
    public:
        std::uint32_t m_color{0xFF000000};
        unsigned int x_position{0};
        unsigned int y_position{0};
    };

    export class Pixel {
        std::uint32_t m_color{0xFF000000};
        unsigned int x_position{0};
        unsigned int y_position{0};

    public:
        // Default Constructor
        Pixel() = default;

        // Constructors
        Pixel(const std::uint32_t color, const unsigned int x, const unsigned int y) {
            m_color = color;
            x_position = x;
            y_position = y;
        }

        // Destructor
        ~Pixel() {
            fmt::println("~Pixel()\n");
        }

        // Setters
        auto set_color(const std::uint32_t &new_color) -> void {
            m_color = new_color;
        }

        auto set_x_position(const unsigned int &new_x_position) -> void {
            x_position = new_x_position;
        }

        auto set_y_position(const unsigned int &new_y_position) -> void {
            y_position = new_y_position;
        }

        // Getters
        [[nodiscard]] auto get_color() const -> std::uint32_t {
            return m_color;
        }

        [[nodiscard]] auto get_x_position() const -> unsigned int {
            return x_position;
        }

        [[nodiscard]] auto get_y_position() const -> unsigned int {
            return y_position;
        }
    };
}
