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
        // Pixel(const std::uint32_t color, const unsigned int x, const unsigned int y) {
        //     m_color = color;
        //     x_position = x;
        //     y_position = y;
        // }

        // Constructor List Initialization
        Pixel(const std::uint32_t m_color, const unsigned int x_position,
              const unsigned int y_position) : m_color{m_color}, x_position{x_position}, y_position{y_position} {
            fmt::println("Pixel Created!");
        }

        // Copy Constructor
        Pixel(const Pixel &object) : m_color{object.m_color}, x_position{object.x_position},
                                     y_position{object.y_position} {
            fmt::println("Pixel Copied!");
        }

        // Destructor
        ~Pixel() {
            fmt::println("~Pixel()");
        }

        // Setters
        auto set_color(this Pixel &self, const std::uint32_t &m_color) -> void {
            self.m_color = m_color;
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

namespace delegation_class {
    export class Pixel {
        std::uint32_t m_color{0xFF000000};
        unsigned int x_position{0};
        unsigned int y_position{0};

    public:
        // Default Constructor
        Pixel() = default;

        // Constructor with color only, delegates to the three-argument constructor
        Pixel(const std::uint32_t m_color) : Pixel(m_color, 0, 0) {
            fmt::println("Color only constructor!");
        }

        // The constructor below is not valid, since delegating call must be the only item in the member initializer list
        /*
        Pixel(const std::uint32_t m_color) : Pixel(m_color, 0, 0), x_position{9} {
            fmt::println("Color only constructor!");
        }
        */

        // Constructor List Initialization
        // Will be doing the heavy lifting for other constructors
        Pixel(const std::uint32_t m_color, const unsigned int x_position,
              const unsigned int y_position) : m_color{m_color}, x_position{x_position}, y_position{y_position} {
            fmt::println("Three-argument Constructor!");
        }

        // Copy Constructor
        Pixel(const Pixel &object) : Pixel(object.m_color, object.x_position, object.y_position) {
            fmt::println("Copy Constructor");
        }

        // Destructor
        ~Pixel() {
            fmt::println("~Pixel()");
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

    export auto print_pixel(const Pixel &object) -> void {
        fmt::println("Pixel:");
        fmt::println("\tcolor = {:08X}", object.get_color());
        fmt::println("\tX Position: {}", object.get_x_position());
        fmt::println("\tY Position: {}\n", object.get_y_position());
    }
}

namespace explicit_constructor {
    export class Pixel {
        std::uint32_t m_color{0xFF000000};
        unsigned int x_position{0};
        unsigned int y_position{0};

    public:
        Pixel() = default;

        // Constructor with only one argument
        // explicit is used to prevent implicit conversions
        explicit Pixel(const std::uint32_t m_color) : Pixel(m_color, 0, 0) {
            fmt::println("Color only constructor!");
        }

        Pixel(const std::uint32_t m_color, const unsigned int x_position,
              const unsigned int y_position) : m_color{m_color}, x_position{x_position}, y_position{y_position} {
            fmt::println("Three-argument Constructor!");
        }

        Pixel(const Pixel &object) : Pixel(object.m_color, object.x_position, object.y_position) {
            fmt::println("Copy Constructor");
        }

        ~Pixel() {
            fmt::println("~Pixel()");
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

    export auto print_pixel(const Pixel &object) -> void {
        fmt::println("Pixel:");
        fmt::println("\tcolor = {:08X}", object.get_color());
        fmt::println("\tX Position: {}", object.get_x_position());
        fmt::println("\tY Position: {}\n", object.get_y_position());
    }
}
