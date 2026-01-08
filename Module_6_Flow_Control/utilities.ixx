module;

#include <fmt/format.h>
#include <iostream>
#include <utility>
#include <vector>

export module utilities;

// Tools
bool house() {
	fmt::println("house() is running");
	return false;
}

bool spouse() {
	fmt::println("spouse() is running");
	return true;
}

bool car() {
	fmt::println("car() is running");
	return true;
}

bool tv() {
	fmt::println("tv() is running");
	return true;
}

constexpr int pen{10};
constexpr int marker{20};
constexpr int eraser{30};
constexpr int rectangle{45};
constexpr int circle{15};
constexpr int ellipse{7};

constexpr int Red{70};
constexpr int Green{150};
constexpr int Blue{200};

void handle_color(int color) {
	switch (color) {
		case Red:
			fmt::println("Handling Red.");
			break;
		case Green:
			fmt::println("Handling Green.");
			break;
		case Blue:
			fmt::println("Handling Blue.");
			break;
		default:
			// We expect that all cases are covered
			// So reaching here sould never happen
			std::unreachable();
	}
}

//	Part 1
export void if_statements_example() {
	// If Statement
	fmt::println("Example of If Statements:\n");

	constexpr int number1{75};
	constexpr int number2{60};

	constexpr bool result{number1 < number2}; // Expression yeilding the condition

	// Free standing if statement
	fmt::println("Free standing if Statement");

	// if (result) {}
	if (result == true) {
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

	if (red) {
		fmt::println("Stop");
	}
	if (yellow) {
		fmt::println("Slow Down!");
	}
	if (green) {
		fmt::println("GO");
	}

	fmt::println("Police Officer Stops (Verbose)");
	if (green) {
		if (police_stop) {
			fmt::println("Stop!");
		} else {
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

	if (int speed{10}; go) {
		fmt::println("Speed: {}", speed);
		if (speed > 5) {
			fmt::println("Slow down!");
		} else {
			fmt::println("All good!");
		}
	} else {
		fmt::println("Speed: {}", speed);
		fmt::println("Stop!");
	}

	//fmt::println("{}", speed);
	fmt::println("");
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

	switch (double strength{3.50}; tool) {
		case pen: {
			fmt::println("Active too is Pen. Strength: {}", strength);
		}
		break;
		case marker: {
			fmt::println("Active too is Marker. Strength: {}", strength);
		}
		break;
		case eraser: {
			fmt::println("Active too is Eraser. Strength: {}", strength);
		}
		break;
		case rectangle:
		case circle:
		case ellipse: {
			fmt::println("Active tool is a Shape. Strength: {}", strength);
		}
		break;
		default: {
			fmt::println("No match Found!");
		}
		break;
	}
	fmt::println("");
}

export void short_circuit_evaluations() {
	fmt::println("Short Circuit Evaluations:\n");

	constexpr bool a{true}, b{true}, c{true}, d{false};
	constexpr bool p{false}, q{false}, r{false}, m{true};

	// AND: If one of the operands is false, the result is false
	fmt::println("AND Short Circuit Example:");
	constexpr bool result_and{a && b && c && d};
	fmt::println("result (AND): {}", result_and);
	fmt::println("");

	// OR: If one of the operands is true, the result is true
	fmt::println("OR Short Circuit Example:");
	constexpr bool result_or{a || b || c || d};
	fmt::println("result (OR): {}", result_or);
	fmt::println("");

	// Example using functions
	fmt::println("Short Circuit Example using Functions:");
	if (car() && house() && tv() && spouse()) {
		fmt::println("AND - I am happy");
	} else {
		fmt::println("AND - I am not happy!");
	}

	if (car() || tv() || spouse() || house()) {
		fmt::println("OR - I am happy");
	} else {
		fmt::println("OR - I am not happy!");
	}
	fmt::println("");
}

export void ternary_operator_example() {
	fmt::println("Ternary Operator Example:");

	int max{};
	constexpr int a{35}, b{120};

	//if (a > b)
	//{
	//	max = a;
	//} else
	//{
	//	max = b;
	//}

	max = (a > b) ? a : b;

	fmt::println("max: {}", max);
	fmt::println("");
}

export void unreachable_example() {
	fmt::println("Unreachable Example:");
	fmt::println("");

	handle_color(Red);
	handle_color(Green);
	handle_color(Blue);
	//handle_color(55);
}

export void loops_example() {
	fmt::println("Loops Example:");
	fmt::println("");

	// For Loops Examples
	fmt::println("For loops:");
	constexpr size_t COUNT{10};

	for (size_t i{0}; i < COUNT; ++i) {
		// Whatever we want the loop to run
		fmt::println("{} : I love C++", i);
	}

	fmt::println("");

	fmt::println("Ranged Based For Loop Example");

	for (const std::vector<int> values{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; int value: values) {
		// Value holds a copy of the current iteration in the whole collection
		fmt::println("value: {}", value);
	}
	fmt::println("");

	fmt::println("Using Auto Type Deduction");
	for (auto value: {1, 2, 3, 4, 5, 6, 7, 8}) {
		fmt::println("value: {}", value);
	}
	fmt::println("");

	// While Loops Example
	fmt::println("While Loop Examples:");

	size_t i{0};

	while (i < COUNT) {
		fmt::println("{} : I love C++", i);
		++i;
	}
	fmt::println("");

	i = 0;
	// Do-While Loops
	fmt::println("Do-While Loop Example:");
	do {
		fmt::println("{} : I love C++", i);
		++i;
	} while (i < COUNT);
}
