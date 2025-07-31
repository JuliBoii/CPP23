module;

#include <iostream>
#include <iomanip>
#include <ios>
#include <string>

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