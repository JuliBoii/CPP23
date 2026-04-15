module;

#include <fmt/format.h>

export module pointer2;

export void modifiable_raw_pointers()
{
    fmt::println("Case: Raw Variable that can be modified");

    int number{5}; // Not const

    fmt::println("Number: {}", number);
    fmt::println("Number Address: {}", static_cast<void*>(&number));
    fmt::println("");

    fmt::println("Modifying 'number':");
    number = 12;
    number += 13;

    fmt::println("New Number: {}", number);
    fmt::println("Number Address: {}", static_cast<void*>(&number));
}