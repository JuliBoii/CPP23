module;

#include <fmt/format.h>
#include <iostream>

export module utilities;

//	Part 1
export void if_statements_example()
{
    // If Statement
    fmt::println("Example of If Statements:\n");

    constexpr int number1{75};
    constexpr int number2{60};

    constexpr bool result{number1 < number2}; // Expression yeilding the condition

    // Free standing if statement
    fmt::println("Free standing if Statement");

    // if (result) {}
    if (result == true)
    {
        fmt::println("{} is less than {}", number1, number2);
    }

	// if(!result) {}
	if (!(result == true)) {
		fmt::println("{} is NOT less than {}", number1, number2);
	}
}