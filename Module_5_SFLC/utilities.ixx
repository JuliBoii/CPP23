module;

#include <array>
#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <format>
#include <fmt/format.h>
#include <print>

export module utilities;

export void output_and_input()
{
	// Data Output
	std::cout << "Hello Modern C++" << std::endl;
	std::cout << "How are you?\n";
	std::cout << "I am fine.\n\n";

	constexpr unsigned int age{24};
	std::cout << "Age: " << age << '\n';
	/*// std::cerr can be used to print errors
	std::cerr << "Error message: Something is wrong" << std::endl;
	// std::clog can be used to print log messages
	std::clog << "Log message: Something happened\n";*/

	// Data Input
	unsigned int age1{};
	std::string name{};
	std::cout << "What is your name and age?\n";
	std::cout << "Name: ";
	std::getline(std::cin, name);
	std::cout << "Age: ";
	std::cin >> age1;
	std::cout << "Hello " << name << "!\n"
	<< "So, you are " << age1 << " years old.\n\n";
}

export void output_formatting()
{
	// Output Formatting
	std::cout << "Unformatted Table" << std::endl;
	std::cout << "First Name" << " " << "Last Name" << " " << "Age" << std::endl;
	std::cout << "Daniel" << " " << "Gray" << " " << "25" << std::endl;
	std::cout << "Stanley" << " " << "Woods" << " " << "33" << std::endl;
	std::cout << "Jordan" << " " << "Parker" << " " << "45" << std::endl;
	std::cout << "Joe" << " " << "Ball" << " " << "21" << std::endl;
	std::cout << "Josh" << " " << "Carr" << " " << "25" << std::endl;
	std::cout << "Izaiah" << " " << "Robinson" << " " << "29" << std::endl;
	std::cout << std::endl;

	/*
	std::cout << "Formatted Table" << std::endl;
	std::cout << std::setw(10) << "First Name" << std::setw(10) << "Last Name" << std::setw(5) << "Age" << std::endl;
	std::cout << std::setw(10) << "Daniel" << std::setw(10) << "Gray" << std::setw(5) << "25" << std::endl;
	std::cout << std::setw(10) << "Stanley" << std::setw(10) << "Woods" << std::setw(5) << "33" << std::endl;
	std::cout << std::setw(10) << "Jordan" << std::setw(10) << "Parker" << std::setw(5) << "45" << std::endl;
	std::cout << std::setw(10) << "Joe" << std::setw(10) << "Ball" << std::setw(5) << "21" << std::endl;
	std::cout << std::setw(10) << "Josh" << std::setw(10) << "Carr" << std::setw(5) << "25" << std::endl;
	std::cout << std::setw(10) << "Izaiah" << std::setw(10) << "Robinson" << std::setw(5) << "29" << std::endl;
	*/
	std::cout << "Left-Aligned Formatted Table with Variables:" << std::endl;

	constexpr int column_width{20};
	std::cout << std::left;
	std::cout << std::setw(column_width) << "First Name" << std::setw(column_width) << "Last Name" << std::setw(column_width/2) << "Age" << std::endl;
	std::cout << std::setw(column_width) << "Daniel" << std::setw(column_width) << "Gray" << std::setw(column_width/2) << "25" << std::endl;
	std::cout << std::setw(column_width) << "Stanley" << std::setw(column_width) << "Woods" << std::setw(column_width/2) << "33" << std::endl;
	std::cout << std::setw(column_width) << "Jordan" << std::setw(column_width) << "Parker" << std::setw(column_width/2) << "45" << std::endl;
	std::cout << std::setw(column_width) << "Joe" << std::setw(column_width) << "Ball" << std::setw(column_width/2) << "21" << std::endl;
	std::cout << std::setw(column_width) << "Josh" << std::setw(column_width) << "Carr" << std::setw(column_width/2) << "27" << std::endl;
	std::cout << std::setw(column_width) << "Izaiah" << std::setw(column_width) << "Robinson" << std::setw(column_width/2) << "29" << std::endl;
	std::cout << std::endl;

	std::cout << "Right-Aligned Formatted Table with Variables:" << std::endl;
	std::cout << std::right;
	std::cout << std::setw(column_width) << "First Name" << std::setw(column_width) << "Last Name" << std::setw(column_width/2) << "Age" << std::endl;
	std::cout << std::setw(column_width) << "Daniel" << std::setw(column_width) << "Gray" << std::setw(column_width/2) << "25" << std::endl;
	std::cout << std::setw(column_width) << "Stanley" << std::setw(column_width) << "Woods" << std::setw(column_width/2) << "33" << std::endl;
	std::cout << std::setw(column_width) << "Jordan" << std::setw(column_width) << "Parker" << std::setw(column_width/2) << "45" << std::endl;
	std::cout << std::setw(column_width) << "Joe" << std::setw(column_width) << "Ball" << std::setw(column_width/2) << "21" << std::endl;
	std::cout << std::setw(column_width) << "Josh" << std::setw(column_width) << "Carr" << std::setw(column_width/2) << "27" << std::endl;
	std::cout << std::setw(column_width) << "Izaiah" << std::setw(column_width) << "Robinson" << std::setw(column_width/2) << "29" << std::endl;
	std::cout << std::endl;

	std::cout << "Negative Number Alignment Example:" << std::endl;
	std::cout << std::right;
	std::cout << std::setw(column_width/2) << -123.24 << std::endl;
	std::cout << std::internal;
	std::cout << std::setw(column_width/2) << -123.24 << std::endl;
	std::cout << std::endl;

	std::cout << "Table with fill characters:" << std::endl;
	std::cout << std::left;
	std::cout << std::setfill('*');

	std::cout << std::setw(column_width) << "First Name" << std::setw(column_width) << "Last Name" << std::setw(column_width/2) << "Age" << std::endl;
	std::cout << std::setw(column_width) << "Daniel" << std::setw(column_width) << "Gray" << std::setw(column_width/2) << "25" << std::endl;
	std::cout << std::setw(column_width) << "Stanley" << std::setw(column_width) << "Woods" << std::setw(column_width/2) << "33" << std::endl;
	std::cout << std::setw(column_width) << "Jordan" << std::setw(column_width) << "Parker" << std::setw(column_width/2) << "45" << std::endl;
	std::cout << std::setw(column_width) << "Joe" << std::setw(column_width) << "Ball" << std::setw(column_width/2) << "21" << std::endl;
	std::cout << std::setw(column_width) << "Josh" << std::setw(column_width) << "Carr" << std::setw(column_width/2) << "27" << std::endl;
	std::cout << std::setw(column_width) << "Izaiah" << std::setw(column_width) << "Robinson" << std::setw(column_width/2) << "29" << std::endl;
	std::cout << std::endl;

	// Bool Representation
	// boolalpha and noboolalpha: control bool output format
	// 1/0 or true/false
	bool condition{true};
	bool other_condition{false};

	std::cout << "Default Bool Output Format:" << std::endl;
	std::cout << "condition: " << condition << std::endl;
	std::cout << "other_condition: " << other_condition << std::endl;
	std::cout << std::endl;

	std::cout << std::boolalpha;
	std::cout << "boolalpha Output Format:" << std::endl;
	std::cout << "condition: " << condition << std::endl;
	std::cout << "other_condition: " << other_condition << std::endl;
	std::cout << std::endl;

	std::cout << std::noboolalpha;
	std::cout << "noboolalpha Output Format:" << std::endl;
	std::cout << "condition: " << condition << std::endl;
	std::cout << "other_condition: " << other_condition << std::endl;
	std::cout << std::endl;

	// Signed Number Representation
	// showpos and noshowpos: show or hide the + sign for positive numbers
	constexpr int pos_num{34};
	constexpr int neg_num{-34};

	std::cout << "Default Positive Number Output Format:" << std::endl;
	std::cout << "pos_num: " << pos_num << std::endl;
	std::cout << "neg_num: " << neg_num << std::endl;
	std::cout << std::endl;

	std::cout << "Show Positive Number Sign Format Output:" << std::endl;
	std::cout << std::showpos;
	std::cout << "pos_num: " << pos_num << std::endl;
	std::cout << "neg_num: " << neg_num << std::endl;
	std::cout << std::endl;

	std::cout << "Disable Show Positive Number Sign Format Output:" << std::endl;
	std::cout << std::noshowpos;
	std::cout << "pos_num: " << pos_num << std::endl;
	std::cout << "neg_num: " << neg_num << std::endl;
	std::cout << std::endl;

	// Uppercase
	constexpr int number{717171};
	std::cout << "Default Number Output Format:" << std::endl;
	std::cout << "number (decimal): " << std::dec << number << std::endl;
	std::cout << "number (hexadecimal): " << std::hex << number << std::endl;
	std::cout << "number (octal): " << std::oct << number << std::endl;
	std::cout << std::endl;

	std::cout << "Uppercase Number Output Format:" << std::endl;
	std::cout << std::uppercase;
	std::cout << "number (decimal): " << std::dec << number << std::endl;
	std::cout << "number (hexadecimal): " << std::hex << number << std::endl;
	std::cout << "number (octal): " << std::oct << number << std::endl;
	std::cout << std::endl;

	std::cout << "Disable Uppercase Number Output Format:" << std::endl;
	std::cout << std::nouppercase;
	std::cout << "number (decimal): " << std::dec << number << std::endl;
	std::cout << "number (hexadecimal): " << std::hex << number << std::endl;
	std::cout << "number (octal): " << std::oct << number << std::endl;
	std::cout << std::endl;

	// floating-point output
	std::cout << "Default floating-point Output Format:" << std::endl;
	constexpr double a{3.1415926535};
	constexpr double b{2006.0};
	constexpr double c{1.34e-10};

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << std::endl;

	std::cout << "Fixed Point Output Format:" << std::endl;
	std::cout << std::fixed;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << std::endl;

	std::cout << "Scientific Point Output Format:" << std::endl;
	std::cout << std::scientific;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << std::endl;

	std::cout << "Reset to Default Floating-Point Output Format:" << std::endl;
	std::cout << std::defaultfloat;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << std::endl;

	// Floating-point Precision
	constexpr double pie{3.1415926535897932384626433832795};

	std::cout << "Default Floating-Point Precision Output Format:" << std::endl;
	const auto default_precision{std::cout.precision()}; // Saves current precision size
	std::cout << "pi: " << pie << std::endl;
	std::cout << std::endl;

	std::cout << "Floating-Point (10) Precision Output Format:" << std::endl;
	std::cout << std::setprecision(10);
	std::cout << "pi: " << pie << std::endl;
	std::cout << std::endl;

	std::cout << "Floating-Point (20) Precision Output Format:" << std::endl;
	std::cout << std::setprecision(20);
	std::cout << "pi: " << pie << std::endl;
	std::cout << std::endl;

	std::cout << "Reset to Default Floating-Point Precision Output Format:" << std::endl;
	std::cout << std::setprecision(default_precision);
	std::cout << "pi: " << pie << std::endl;
	std::cout << std::endl;

	// Showing Point
	constexpr double d{34.1}, e{101.99}, f{12.0};
	constexpr int g{45};

	std::cout << "Show Point Format Output:" << std::endl;
	std::cout << std::showpoint;
	std::cout << "d: " << d << std::endl;
	std::cout << "e: " << e << std::endl;
	std::cout << "f: " << f << std::endl;
	std::cout << "g: " << g << std::endl;
	std::cout << std::endl;

	std::cout << std::noshowpoint;
	std::cout << "No Show Point Format Output:" << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "e: " << e << std::endl;
	std::cout << "f: " << f << std::endl;
	std::cout << "g: " << g << std::endl;
	std::cout << std::endl;
}

export void format_library_test()
{
	auto value = fmt::format("Hello, {}!", "World");
	std::cout << value << '\n';
	const std::array<std::string, 6> first_name{"Daniel", "Stanley", "Jordan", "Joe", "Josh", "Izaiah"};
	const std::array<std::string, 6> last_name{"Gray", "Woods", "Parker", "Ball", "Carr", "Robinson"};
	constexpr std::array<unsigned int, 6> age{25u, 33u, 45u, 21u, 27u, 29u};

	fmt::print("Hello, {}!\n", "World");
	fmt::print("Hello, {}!", "World\n");
	fmt::println("Unformatted Table:");
	for (int i = 0; i < 6; i++)
	{
		if (i == 0)
			fmt::println("{} {} {}", "First Name", "Last Name", "Age");
		fmt::println("{} {} {}", first_name[i], last_name[i], age[i]);
	}
	fmt::println("-------\n");

	fmt::println("Formatted Table:");
	for (int i = 0; i < 6; i++)
	{
		if (i == 0)
			fmt::println("{:<10} {:<10} {:<5}", "First Name", "Last Name", "Age");
		fmt::println("{:<10} {:<10} {:<5}", first_name[i], last_name[i], age[i]);
	}
	fmt::println("-------\n");


	// Dynamic Widths
	constexpr int col_width{25};

	fmt::println("Formatted Left-Justified Table with Dynamic Widths:");
	for (int i = 0; i < 6; i++)
	{
		if (i == 0)
			fmt::println("{:<{}} {:<{}} {:<{}}", "First Name", col_width, "Last Name", col_width, "Age", col_width/2);
		fmt::println("{:<{}} {:<{}} {:<{}}", first_name[i], col_width, last_name[i], col_width, age[i], col_width/2);
	}
	fmt::println("-------\n");

	fmt::println("Formatted Right-Justified Table with Dynamic Widths:");
	for (int i = 0; i < 6; i++)
	{
		if (i == 0)
			fmt::println("{:>{}} {:>{}} {:>{}}", "First Name", col_width, "Last Name", col_width, "Age", col_width/2);
		fmt::println("{:>{}} {:>{}} {:>{}}", first_name[i], col_width, last_name[i], col_width, age[i], col_width/2);
	}
	fmt::println("-------\n");

	fmt::println("Formatted Internal-Justified Table with Dynamic Widths:");
	for (int i = 0; i < 6; i++)
	{
		if (i == 0)
			fmt::println("{:^{}} {:^{}} {:^{}}", "First Name", col_width, "Last Name", col_width, "Age", col_width/2);
		fmt::println("{:^{}} {:^{}} {:^{}}", first_name[i], col_width, last_name[i], col_width, age[i], col_width/2);
	}
	fmt::println("-------\n");

	fmt::println("Differences with Justification and Numbers:");
	fmt::println("{:<10}", -12.31);
	fmt::println("{:^10}", -12.31);
	fmt::println("{:>10}", -12.31);
	fmt::println("-------\n");

	fmt::println("Table with Fill Characters:");
	for (int i = 0; i < 6; i++)
	{
		if (i == 0)
			fmt::println("{:*<{}} {:*<{}} {:*<{}}", "First Name", col_width, "Last Name", col_width, "Age", col_width/2);
		fmt::println("{:*<{}} {:*<{}} {:*<{}}", first_name[i], col_width, last_name[i], col_width, age[i], col_width/2);
	}
	fmt::println("-------\n");

	fmt::println("Boolean Data with FMT:");
	constexpr bool first{true};
	constexpr bool last{false};

	fmt::println("True Condition Default: {}", first);
	fmt::println("False Condition Default: {}", last);

	// Workaround for Bool Printing -ref: https://github.com/fmtlib/fmt/issues/170
	fmt::println("True Condition Workaround: {:<d}", first);
	fmt::println("False Condition Workaround: {:<d}", last);
	fmt::println("-------\n");

	// Show sign for positive numbers
	fmt::println("Show or Hide the + sign for Positive Numbers:");
	constexpr int positive_num{34}, negative_num{-23};

	fmt::println("Positive Number: {}", positive_num);
	fmt::println("Negative Number: {}", negative_num);

	fmt::println("Positive Number: {:+}", positive_num);
	fmt::println("Negative Number: {:-}", negative_num);
	fmt::println("-------\n");

	// Controlling the Number System for Integers
	// Along with Case Sizing
	fmt::println("Uppercase and Nouppercase Examples:");
	constexpr int case_number{717171};
	fmt::println("case_number Default (No Upper Case):");
	fmt::println("case_number (decimal): {}", case_number);
	fmt::println("case_number (hexadecimal): {:x}", case_number);
	fmt::println("case_number (octal): {:o}", case_number);
	fmt::println("case_number (Binary): {:b}\n", case_number);

	fmt::println("case_number (Uppercase):");
	fmt::println("case_number (Hex): {:X}\n", case_number);

	// For integers, the "#" toggles the alternative format flag
	// This shows the base prefix like '0b' and '0x'
	fmt::println("case_number (Showbase):");
	fmt::println("case_number (Hex): {:#X}", case_number);
	fmt::println("case_number (Octal): {:#o}", case_number);
	fmt::println("case_number (Binary): {:#b}", case_number);
	fmt::println("-------\n");

	// Fixed and Scientific: for floating-point values
	// Control the precision
	constexpr double long_double{3.1415926535897932384626433832795};
	constexpr double stand_double{2006.2};
	constexpr double sci_double{1.34e-10};

	fmt::println("Double values (Default)");
	fmt::println("pi: {}", long_double);
	fmt::println("double: {}", stand_double);
	fmt::println("scientific double: {}\n", sci_double);

	fmt::println("Double Values (Precision: 6)");
	fmt::println("pi: {:.6}", long_double);
	fmt::println("double: {:.6}", stand_double);
	fmt::println("scientific double: {:.6}\n", sci_double);

	fmt::println("Double Values (Precision: 10)");
	fmt::println("pi: {:.10}", long_double);
	fmt::println("double: {:.10}", stand_double);
	fmt::println("scientific double: {:.10}\n", sci_double);

	fmt::println("Double Values (Fixed: 6)");
	fmt::println("pi: {:.6f}", long_double);
	fmt::println("double: {:.6f}", stand_double);
	fmt::println("scientific double: {:.6f}\n", sci_double);

	fmt::println("Double Values (Fixed: 10)");
	fmt::println("pi: {:.10f}", long_double);
	fmt::println("double: {:.10f}", stand_double);
	fmt::println("scientific double: {:.10f}\n", sci_double);

	fmt::println("Double Values (Scientific: 6)");
	fmt::println("pi: {:.6e}", long_double);
	fmt::println("double: {:.6e}", stand_double);
	fmt::println("scientific double: {:.6e}\n", sci_double);

	fmt::println("Double Values (Scientific: 10)");
	fmt::println("pi: {:.10e}", long_double);
	fmt::println("double: {:.10e}", stand_double);
	fmt::println("scientific double: {:.10e}", sci_double);
	fmt::println("-------\n");

	fmt::println("Argument Indexes:");
	fmt::println("It is {:.2f} degrees outside and it is {}", 34.5, "sunny");
	fmt::println("It is {1} degrees outside and it is {0:.2f}", 34.5, "sunny");
	fmt::println("-------\n");
}

export void literals_examples() {
	// 2 Bytes
	short short_var{-32768};	// No special literal type for short
	short int short_int{455};	// No special literal type for short
	signed short signed_short_var{-32768};	// No special literal type for short
	signed int signed_short_int{-455};	// No special literal type for short
	unsigned short int unsigned_short_var{65535U};

	// 4 Bytes
	const int int_var{32767};
	signed signed_var{-32768};
	signed int signed_int_var{-455};
	unsigned int unsigned_var{65535U};

	// 4 Or 8 Bytes
	long long_var{-9223372036854775807L}; // 4 or 8 bytes
	long int long_int_var{-9223372036854775807L};
	signed long signed_long_var{-9223372036854775807L};
	signed long int signed_long_int_var{-9223372036854775807L};
	unsigned long int unsigned_long_var{4294967295UL};

	long long long_long_var{-9223372036854775807LL}; // 8 Bytes
	long long int long_long_int_var{-9223372036854775807LL};
	signed long long signed_long_long_var{-9223372036854775807LL};
	signed long long int signed_long_long_int_var{-9223372036854775807LL};

	// Grouping Numbers: C++14 and Onwards
	unsigned int prize{1'500'00'0U};
	fmt::println("The prize is: {}", prize);
	fmt::println("signed_long_long_int: {}\n", signed_long_long_int_var);

	// With number systems: Hex (prefixed with 0x)
	unsigned int hex_number_1 {0x22BU};	// Decimal: 555
	int hex_number_2{0x400};	// Decimal: 1024
	fmt::println("The hex number is: {:x}", hex_number_1);
	fmt::println("The hex number is: {:x}\n", hex_number_2);

	// Representing colors with hex
	int black_color_hex{0xffffff};
	fmt::println("Black color is: {:X}\n", black_color_hex);

	// Octal literals: Prefix with 0
	int octal_number{0777u};	// Decimal: 511
	fmt::println("The octal number is: {:o}", octal_number);
	// BE CAREFUL NOT TO PREFIX YOUR INTEGERS WITH 0 IF YOU MEAN DECIMAL
	int error_octal_number{055};	// This is not 55 in memory, it is 45 in Decimal
	fmt::println("The erroneous octal number is: {}\n", error_octal_number);

	// Binary Literals
	unsigned int binary_literal{0b11111111u};
	fmt::println("The binary literal is: {:b}\n", binary_literal);

	// Literals Examples
	char char_var{'a'};
	int number_literal{15};
	float fractional_literal{1.5101f};
	std::string string_literal{"This is a string literal"};

	// Print the literals with fmt
	fmt::println("The char literal is: {}", char_var);
	fmt::println("The number literal is: {}", number_literal);
	fmt::println("The fractional literal is: {}", fractional_literal);
	fmt::println("The string literal is: {}\n", string_literal);
}
