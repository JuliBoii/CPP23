module;

#include <fmt/format.h>
#include <iostream>

export module utilities;

// Tools
constexpr int pen{10};
constexpr int marker{20};
constexpr int eraser{30};
constexpr int rectangle{45};
constexpr int circle{15};
constexpr int ellipse{7};

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

	fmt::println("");

	fmt::println("Nested If Statements:");

 	constexpr bool red{false};
 	constexpr bool yellow{false};
 	constexpr bool green{true};
 	constexpr bool police_stop{true};

 	// If green: go
    // If red, yellow: stop
    // if green and police_stop: stop

    if (red)
    {
        fmt::println("Stop");

    }
    if (yellow)
    {
        fmt::println("Slow Down!");
    }
    if (green)
    {
        fmt::println("GO");
    }

    fmt::println("Police Officer stops(verbose)");
    if (green)
    {
        if (police_stop)
        {
            fmt::println("Stop!");
        } else
        {
            fmt::println("GO!");
        }
    }

	fmt::println("Police Officer Stops (Less Verbose)");

	if (green && !police_stop) {
		fmt::println("Go!");
	} else {
		fmt::println("Stop!");
	}

	fmt::println("\nIf Statement with Initializer");

	constexpr bool go{true};

	if (int speed{10}; go)
	{
    	fmt::println("Speed: {}", speed);
    	if (speed > 5)
    	{
        	fmt::println("Slow down!");
    	} else
    	{
        	fmt::println("All good!");
    	}
	} else
	{
    	fmt::println("Speed: {}", speed);
    	fmt::println("Stop!");
	}

	//fmt::println("{}", speed);

	fmt::println("Else-If Statement");

	constexpr int tool{eraser};

	if (tool == pen) {
		fmt::println("Active tool is pen.");
	} else if (tool == marker) {
		fmt::println("Active tool is marker.");
	} else if (tool == eraser) {
		fmt::println("Active tool is eraser.");
	} else if (tool == rectangle) {
		fmt::println("Active tool is rectangle.");
	} else if (tool == circle) {
		fmt::println("Active tool is circle.");
	} else if (tool == ellipse) {
		fmt::println("Active tool is ellipse.");
	}
	fmt::println("");
}

export void switch_statements() {
	fmt::println("Switch statements Example:");
	constexpr int tool{circle};

	switch (double strength {3.50}; tool) {
		case pen: {
			fmt::println("Active too is Pen. Strength: {}", strength);
		} break;
		case marker: {
			fmt::println("Active too is Marker. Strength: {}", strength);
		} break;
		case eraser: {
			fmt::println("Active too is Eraser. Strength: {}", strength);
		} break;
		case rectangle:
		case circle:
		case ellipse: {
			fmt::println("Active tool is a Shape. Strength: {}", strength);
		} break;
		default: {
			fmt::println("No match Found!");
		} break;
	}
	fmt::println("");
}