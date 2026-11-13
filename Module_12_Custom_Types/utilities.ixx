module;

#include <fmt/format.h>
#include <memory>

export module utilities;

import custom_types;
import Boxes;

export auto public_access_example() -> void {
    custom_types_struct::Pixel p1{};
    custom_types_class::Pixel_P p2{};

    p1.m_color = 0xFFA01C00;
    p2.x_position = 41;
    p2.y_position = 3;
    p1.x_position = 784;

    fmt::println("Struct Pixel Color: {:#010x}", p1.m_color);
    fmt::println("Struct Pixel Position: ({}, {})\n", p1.x_position, p1.y_position);

    fmt::println("Class Pixel Color: {:#010x}", p2.m_color);
    fmt::println("Class Pixel Position: ({}, {})\n", p2.x_position, p2.y_position);
}

export auto private_access_example() -> void {
    [[maybe_unused]] custom_types_struct::Pixel_P p1{};
    [[maybe_unused]] custom_types_class::Pixel p2{};

    fmt::println("Cannot access p1 nor p2");
}

export auto setter_and_getters_example() -> void {
    custom_types_class::Pixel p;

    fmt::println("Pixel on the Stack:");
    fmt::println("Modifying Private Variables\n");
    p.set_color(0xff81ca00);
    p.set_x_position(412);
    p.set_y_position(500);

    // Stack
    fmt::println("Accessing Private Variables");
    fmt::println("Get Pixel Color: {:#010x}", p.get_color());
    fmt::println("Get Pixel Position: ({}, {})\n", p.get_x_position(), p.get_y_position());

    // Using Raw Pointers
    fmt::println("Pixel on the Heap:");
    const auto *p2 = new custom_types_class::Pixel(0xaa1c3f00, 300, 400);
    fmt::println("Get Pixel Color: {:#010x}", p2->get_color());
    fmt::println("Get Pixel Position: ({}, {})\n", p2->get_x_position(), p2->get_y_position());
    delete p2;

    // Using Unique Pointers
    const auto p3 = std::make_unique<custom_types_class::Pixel>(0x1c8a0000, 50, 480);
    fmt::println("Get Pixel Color: {:#010x}", p3->get_color());
    fmt::println("Get Pixel Position: ({}, {})\n", p3->get_x_position(), p3->get_y_position());
}

export auto fib = [](this auto self, int n) -> int {
    return n <= 1 ? n : self(n - 1) + self(n - 2);
};
