module;

# include <fmt/format.h>
# include <array>
# include <limits>
# include <cmath>
# include <string>
# include <vector>

export module utilities;

//	Part 1
export void number_systems()
{
	/*
	 * In this example we are list initializing four different variables
	 * that all store the same number 15, but are being stored
	 */
	int number1{15}; // Decimal
	int number2{017}; // Octal
	int number3{0x0F}; // Hexadecimal
	int number4{0b000001111}; // Binary

	fmt::print("number1: {}\n", number1);
	fmt::print("number2: {}\n", number2);
	fmt::print("number3: {}\n", number3);
	fmt::print("number4: {}\n\n", number4);
}

export void decimal_representation()
{
	// Single precision (float)
	float single_precision = 1.123456789123456789f;

	// Double precision (double)
	double double_precision = 1.123456789123456789;

	// Extended precision (long double)
	long double long_precision = 1.123456789123456789123456789l;

	// Print results with 30 decimal places for comparison
	fmt::print("single_precision: {:.30f}\n", single_precision);
	fmt::print("double_precision: {:.30f}\n", double_precision);
	fmt::print("long_precision: {:.30Lf}\n\n", long_precision);

	fmt::print("Size of float: {} bytes\n", sizeof(float));
	fmt::print("Size of double: {} bytes\n", sizeof(double));
	fmt::print("Size of long double: {} bytes\n\n", sizeof(long double));
}

export void print_type_ranges()
{
	fmt::println("Ranges for various data types:");
	// Ranges
	fmt::print("The range for short is from {} to {}\n",
	           std::numeric_limits<short>::min(),
	           std::numeric_limits<short>::max());

	fmt::print("The range for short int is from {} to {}\n",
	           std::numeric_limits<short int>::min(),
	           std::numeric_limits<short int>::max()
	);

	fmt::print("The range for unsigned short is from {} to {}\n",
	           std::numeric_limits<unsigned short>::min(),
	           std::numeric_limits<unsigned short>::max());

	fmt::print("The range for an unsigned short int is from {} to {}\n",
	           std::numeric_limits<unsigned short int>::min(),
	           std::numeric_limits<unsigned short int>::max()
	);

	fmt::print("\nThe range for int is from {} to {}\n",
	           std::numeric_limits<int>::min(),
	           std::numeric_limits<int>::max());

	fmt::print("The range for unsigned int is from {} to {}\n",
	           std::numeric_limits<unsigned int>::min(),
	           std::numeric_limits<unsigned int>::max());

	fmt::print("\nThe range for long is from {} to {}\n",
	           std::numeric_limits<long>::min(),
	           std::numeric_limits<long>::max());

	fmt::print("The range for long int is from {} to {}\n",
	           std::numeric_limits<long int>::min(),
	           std::numeric_limits<long int>::max()
	);

	fmt::print("The range for signed long int is from {} to {}\n",
	           std::numeric_limits<signed long int>::min(),
	           std::numeric_limits<signed long int>::max()
	);

	fmt::print("The range for unsigned long is from {} to {}\n",
	           std::numeric_limits<unsigned long>::min(),
	           std::numeric_limits<unsigned long>::max()
	);


	fmt::print("The range for unsigned long int is from {} to {}\n",
	           std::numeric_limits<unsigned long int>::min(),
	           std::numeric_limits<unsigned long int>::max()
	);

	fmt::print("The range for long long is from {} to {}\n",
	           std::numeric_limits<long long>::min(),
	           std::numeric_limits<long long>::max()
	);


	fmt::print("\nThe range for float is from {} to {}\n",
	           std::numeric_limits<float>::min(),
	           std::numeric_limits<float>::max());

	fmt::print("The range (with lowest) for float is from {} to {}\n",
	           std::numeric_limits<float>::lowest(),
	           std::numeric_limits<float>::max());

	fmt::print("The range (with lowest) for double is from {} to {}\n",
	           std::numeric_limits<double>::lowest(),
	           std::numeric_limits<double>::max());

	fmt::print("The range (with lowest) for long double is from {} to {}\n",
	           std::numeric_limits<long double>::lowest(),
	           std::numeric_limits<long double>::max());

	fmt::print("\nint is signed: {}\n", std::numeric_limits<int>::is_signed);

	fmt::print("int digits: {}\n\n", std::numeric_limits<int>::digits);
}

//	Part 2
export void types_of_initializers()
{
	fmt::print("Braced Initialization Example:\n");
	int elephant_count; // Initialized to junk
	int lion_count{}; // Initialized to zero
	int dog_count{10}; // Initialized to 10
	int cat_count{15}; // Initialized to 15

	// Can use expression as initializer
	int domesticated_animals{dog_count + cat_count};

	// int new_number{doesnt_exist};
	// int narrowing_conversion{2.8};	// Error

	fmt::print("Elephant count: {}\n", elephant_count);
	fmt::print("Lion count: {}\n", lion_count);
	fmt::print("Dog count: {}\n", dog_count);
	fmt::print("Cat count: {}\n", cat_count);
	fmt::print("Domesticated animal count: {}\n\n", domesticated_animals);

	fmt::print("Functional Initialization Example:\n");

	// int test();	// Error
	int apple_count(5);
	int orange_count(10);
	int fruit_count(apple_count + orange_count);
	// int bad_initialization(doesnt_exist2 + doesnt_exist3);

	// Information lost.
	// Less safe than braced initialization
	int narrowing_conversion_functional(2.9);

	fmt::print("Apple count: {}\n", apple_count);
	fmt::print("Orange count: {}\n", orange_count);
	fmt::print("Fruit count: {}\n", fruit_count);
	// Will lose information
	fmt::print("Narrowing conversion (functional): {}\n\n", narrowing_conversion_functional);

	fmt::print("Assignment Initialization Example:\n");

	int bike_count = 2;
	int truck_count = 7;
	int vehicle_count = bike_count + truck_count;
	int narrowing_conversion_assignment = 2.8;

	fmt::print("Bike count: {}\n", bike_count);
	fmt::print("Truck count: {}\n", truck_count);
	fmt::print("Vehicle count: {}\n", vehicle_count);
	fmt::print("Narrowing conversion: {}\n", narrowing_conversion_assignment);

	// Check the size with sizeof()
	fmt::println("sizeof int: {}", sizeof(int));
	fmt::println("sizeof truck_count: {}\n", sizeof(truck_count));
}

export void integer_mods()
{
	fmt::print("Value Modifiers:\n");
	// Integer Modifiers
	signed int value1{10};
	signed int value2{-300};
	unsigned int value3{4294967290};

	fmt::print("value1: {}\nsizeof(value1): {}\n", value1, sizeof(value1));
	fmt::print("value2: {}\nsizeof(value2): {}\n", value2, sizeof(value2));
	fmt::print("value3: {}\nsizeof(value3): {}\n", value3, sizeof(value3));

	// unsigned int value4{-5};	// Compiler Error

	fmt::print("\nShort & Long variables:\n");

	short short_var{-32768}; // 2 Bytes
	short int short_int{455};
	signed short signed_short_var{-122};
	signed short int signed_short_int{-456};
	unsigned short int unsigned_short_int{456};

	fmt::print("short_var: {}\nsizeof(short_var): {}\n", short_var, sizeof(short_var));
	fmt::print("\nshort_int: {}\nsizeof(short_int): {}\n", short_int, sizeof(short_int));
	fmt::print("\nsigned_short_var: {}\nsizeof(signed_short_var): {}\n", signed_short_var, sizeof(signed_short_var));
	fmt::print("\nsigned_short_int: {}\nsizeof(signed_short_int): {}\n", signed_short_int, sizeof(signed_short_int));
	fmt::print("\nunsigned_short_int: {}\nsizeof(unsigned_short_int): {}\n", unsigned_short_int,
	           sizeof(unsigned_short_int));

	int int_var{55}; // 4 Bytes
	signed signed_var{4566};
	signed int signed_int{-21474836};
	unsigned int unsigned_int{42949672};

	fmt::print("\nint_var: {}\nsizeof(int_var): {}\n", int_var, sizeof(int_var));
	fmt::print("\nsigned_var: {}\nsizeof(signed_var): {}\n", signed_var, sizeof(signed_var));
	fmt::print("\nsigned_int: {}\nsizeof(signed_int): {}\n", signed_int, sizeof(signed_int));
	fmt::print("\nunsigned_int: {}\nsizeof(unsigned_int): {}\n", unsigned_int, sizeof(unsigned_int));

	long long_var{-922337}; // 4 or 8 Bytes
	long int long_int{9223};
	signed long signed_long_var{-9223372};
	signed long int signed_long_int{9223372};
	unsigned long int unsigned_long_int{1844674};

	fmt::print("\nlong_var: {}\nsizeof(long_var): {}\n", long_var, sizeof(long_var));
	fmt::print("\nlong_int: {}\nsizeof(long_int): {}\n", long_int, sizeof(long_int));
	fmt::print("\nsigned_long_var: {}\nsizeof(signed_long_var): {}\n", signed_long_var, sizeof(signed_long_var));
	fmt::print("\nsigned_long_int: {}\nsizeof(signed_long_int): {}\n", signed_long_int, sizeof(signed_long_int));
	fmt::print("\nunsigned_long_int: {}\nsizeof(unsigned_long_int): {}\n", unsigned_long_int,
	           sizeof(unsigned_long_int));

	long long long_long{92233720365477}; // 8 Bytes
	long long int long_long_int{922337236854};
	signed long long signed_long_long_var{-92233736854775};
	signed long long int signed_long_long_int{-922337205807};
	unsigned long long int unsigned_long_long_var{184467440770955};

	fmt::print("\nlong_long: {}\nsizeof(long_long): {}\n", long_long, sizeof(long_long));
	fmt::print("\nlong_long_int: {}\nsizeof(long_long_int): {}\n", long_long_int, sizeof(long_long_int));
	fmt::print("\nsigned_long_long_var: {}\nsizeof(signed_long_long_var): {}\n", signed_long_long_var,
	           sizeof(signed_long_long_var));
	fmt::print("\nsigned_long_long_int: {}\nsizeof(signed_long_long_int): {}\n", signed_long_long_int,
	           sizeof(signed_long_long_int));
	fmt::print("\nunsigned_long_long_var: {}\nsizeof(unsigned_long_long_var): {}\n", unsigned_long_long_var,
	           sizeof(unsigned_long_long_var));
}

export void floating_point_representation()
{
	fmt::print("Floating Point Representation:\n");
	float number1{1.12345678901234567890f};
	double number2{1.12345678901234567890};
	long double number3{1.12345678901234567890L};

	// Print out Sizes
	fmt::print("Size of float: {}\n", sizeof(float));
	fmt::print("Size of double: {}\n", sizeof(double));
	fmt::print("Size of long double: {}\n", sizeof(long double));

	// Precision
	fmt::print("number1: {}\n", number1);
	fmt::print("number2: {}\n", number2);
	fmt::print("number3: {}\n", number3);

	float number4 = 192400023.0f; // Error: Narrowing Conversion

	fmt::println("number4: {}", number4);

	// Scientific Notation
	double number5{192400023};
	double number6{1.92400023e8};
	double number7{1.924e8};
	double number8{0.00000000003498};
	double number9{3.498e-11};

	fmt::println("number5: {}", number5);
	fmt::println("number6: {}", number6);
	fmt::println("number7: {}", number7);
	fmt::println("number8: {}", number8);
	fmt::println("number9: {}\n", number9);
}

export void infinity_and_nan()
{
	fmt::println("Infinity & NaN:");
	// Infinity & NaN
	double number1{-5.6};
	double number2{}; // Init to 0
	double number3{}; // Init to 0

	// Infinity
	double result{number1 / number2};

	fmt::println("{} / {} yields {}", number1, number2, result);
	fmt::println("{} + {} yields {}", result, number1, result + number1);

	// NaN
	result = number2 / number3;

	fmt::println("{} / {} yields {}\n", number2, number3, result);
}

export void bool_type()
{
	bool red_light{true};
	bool green_light{false};

	if (red_light == true)
	{
		fmt::println("Stop!!!");
	}
	else
	{
		fmt::println("Go Through!");
	}

	// An implicit variation of the example above
	if (green_light)
	{
		fmt::println("Go on...");
	}
	else
	{
		fmt::println("NOT GREEN!!!");
	}

	// sizeof()
	fmt::println("Size of a Bool: {}", sizeof(bool));

	// Printing out a bool
	// 1 = true
	// 0 = false
	fmt::println("red_light: {}", red_light);
	fmt::println("green_light: {}\n", green_light);
}

export void char_type()
{
	char character1{'a'};
	char character2{'r'};
	char character3{'r'};
	char character4{'o'};
	char character5{'w'};

	fmt::println("{}", character1);
	fmt::println("{}", character2);
	fmt::println("{}", character3);
	fmt::println("{}", character4);
	fmt::println("{}", character5);

	char value = 65; // ASCII character code for 'A'
	fmt::println("value: {}", value); // 'A'
	fmt::println("value(int): {}\n", static_cast<int>(value));
}

export void collection_of_chars()
{
	const std::vector<char> characters1{'a', 'r', 'r', 'o', 'w'};
	constexpr std::array<char, 5> characters2{'a', 'r', 'r', 'o', 'w'};

	fmt::print("Vector:\n");
	fmt::print("{}\n", characters1[0]);
	fmt::print("{}\n", characters1[1]);
	fmt::print("{}\n", characters1[2]);
	fmt::print("{}\n", characters1[3]);
	fmt::print("{}\n\n", characters1[4]);

	fmt::print("Array:\n");
	fmt::print("{}\n", characters2[0]);
	fmt::print("{}\n", characters2[1]);
	fmt::print("{}\n", characters2[2]);
	fmt::print("{}\n", characters2[3]);
	fmt::print("{}\n\n", characters2[4]);

	// Print all characters in one go: compiler error
	// fmt::print("{}", characters1);

	fmt::print("Printing string:\n");
	std::string message{"arrow"};
	fmt::print("{}\n", message);

	// Doing more stuff with std::string
	message = "Hello";
	message.append(" there!");
	fmt::print("{}\n\n", message);
}

export void auto_example()
{
	auto var1{12};
	auto var2{13.542};
	auto var3{14.0f};
	auto var4{15.0l};
	auto var5{'e'};

	// int modifier suffix
	auto var6{123u}; // unsigned
	auto var7{1243ul}; // unsigned long
	auto var8{1234ll}; // long long

	fmt::print("var1 occupies: {} bytes\n", sizeof(var1));
	fmt::print("var2 occupies: {} bytes\n", sizeof(var2));
	fmt::print("var3 occupies: {} bytes\n", sizeof(var3));
	fmt::print("var4 occupies: {} bytes\n", sizeof(var4));
	fmt::print("var5 occupies: {} bytes\n", sizeof(var5));
	fmt::print("var6 occupies: {} bytes\n", sizeof(var6));
	fmt::print("var7 occupies: {} bytes\n", sizeof(var7));
	fmt::print("var8 occupies: {} bytes\n", sizeof(var8));
}

//	Part 3
export void basic_ops()
{
	fmt::print("Basic Operations:\n");
	// Addition
	int num1{5};
	int num2{6};
	int num3{51};

	fmt::print("Addition Result: {}\n", num1 + num2);

	// Subtraction
	fmt::print("Subtraction Result: {}\n", num1 - num2);
	fmt::print("Subtraction Result: {}\n", num2 - num1);

	// Multiplication
	fmt::print("Multiplication Result: {}\n", num1 * num2);

	// Division
	fmt::print("Division Result: {}\n", num1 / num2);
	fmt::print("Division Result: {}\n", num2 / num1);

	// Modulus
	fmt::print("Modulo Result: {}\n", num1 % num2);
	fmt::print("Modulo Result: {}\n\n", num3 % num2);
}

export void precedence_and_associativity()
{
	fmt::print("Precedence and Associativity:\n");
	const int a{6};
	const int b{3};
	const int c{8};
	const int d{9};
	const int e{3};
	const int f{2};
	const int g{5};

	int result{a + b * c - d / e - f + g}; // 6 + 24 - 3 - 2 + 5
	fmt::print("Result is: {}\n", result);

	result = a / b * c + d - e + f; // 16 + 9 - 3 + 2
	fmt::print("Result is: {}\n", result);

	result = (a + b) * c - d / e - f + g; // 72 - 3 - 2 + 5
	fmt::print("Result is: {}\n\n", result);
}

export void prefix_postfix_increment_and_decrement_operators()
{
	fmt::print("Pre- and Postfix Incrementing/Decrementing Operations:\n");
	int value{5};
	int value2{10};
	int preNum{};
	int postNum{};

	fmt::print("Initial value: {}\n", value);

	// Increment by 1
	value++;
	fmt::print("Incremented value: {}\n", value);

	// Decrement by 1
	value--;
	fmt::print("Decremented value: {}\n\n", value);

	// A look at the difference between pre- & postfix
	fmt::print("Difference in pre- and post- incrementing/decrementing:\n");
	preNum = --value;
	postNum = value2--;

	// Printing value of preNum after pre-decrement
	fmt::print("Pre-decremented value: {}\n", preNum);
	fmt::print("Original value variable: {}\n\n", value);

	// Printing value of postNum after post-decrement
	fmt::print("Post-decremented value: {}\n", postNum);
	fmt::print("Original value2 variable: {}\n\n", value2);
}

export void compound_assignment_operators()
{
	fmt::print("Compound Assignment Operators:\n");

	int value{5};
	fmt::print("Initial Value: {}\n", value);

	value += 5;
	fmt::print("Add 5 to Value: {}\n", value);

	value -= 5;
	fmt::print("Subtract 5 to Value: {}\n", value);

	value *= 5;
	fmt::print("Multiply Value by 5: {}\n", value);

	value /= 5;
	fmt::print("Divide Value by 5: {}\n", value);

	value %= 3;
	fmt::print("Mod 3, Value: {}\n\n", value);
}

export void relational_operators()
{
	fmt::print("Relational Operators:\n");

	int num1{20};
	int num2{10};

	fmt::print("num1: {}\n", num1);
	fmt::print("num2: {}\n\n", num2);

	fmt::print("Comparing Numbers:\n");

	fmt::print("num1 < num2: {}\n", num1 < num2);
	fmt::print("num1 <= num2: {}\n", num1 <= num2);
	fmt::print("num1 > num2: {}\n", num1 > num2);
	fmt::print("num1 >= num2: {}\n", num1 >= num2);
	fmt::print("num1 == num2: {}\n", num1 == num2);
	fmt::print("num1 != num2: {}\n\n", num1 != num2);

	fmt::print("Store comparison results and use it later\n");
	bool result{num1 == num2};
	fmt::print("{} == {}: {}\n\n", num1, num2, result);
}

export void logical_operators()
{
	fmt::print("Logical Operators:\n");

	bool a{true}, b{false}, c{true};
	fmt::print("a: {}\n", a);
	fmt::print("b: {}\n", b);
	fmt::print("c: {}\n\n", c);

	fmt::println("Basic AND Operations:");
	fmt::println("a && b: {}", a && b);
	fmt::println("a && c: {}", a && c);
	fmt::println("a && b && c: {}\n", a && b && c);

	fmt::println("Basic OR Operations:");
	fmt::println("a || b: {}", a || b);
	fmt::println("a || c: {}", a || c);
	fmt::println("a || b || c: {}\n", a || b || c);

	fmt::println("Basic OR Operations:");
	fmt::println("a || b: {}", a || b);
	fmt::println("a || c: {}", a || c);
	fmt::println("a || b || c: {}\n", a || b || c);

	fmt::println("Basic NOT Operations:");
	fmt::println("!a: {}", !a);
	fmt::println("!b: {}", !b);
	fmt::println("!c: {}\n", !c);

	// Combination of all these operators
	fmt::println("Combining logical operators\n");
	fmt::println("(a && b) || !c: {}", (a && b) || !c);
	fmt::println("!(a && b) || c: {}\n", !(a && b) || c);
}

export void relational_and_logical_operators()
{
	fmt::print("Relational and Logical Operations Examples:\n");

	int a{45};
	int b{-13};
	int c{98};
	bool d{true};

	fmt::println("a: {}", a);
	fmt::println("b: {}", b);
	fmt::println("c: {}", c);
	fmt::println("d: {}\n", d);

	fmt::println("(a > b) && (a > c): {}", (a > b) && (a > c));
	fmt::println("(a == b) || (b <= c): {}", (a == b) || (b <= c));
	fmt::println("(a < b) || (a > c): {}", (a < b) || (a > c));
	fmt::println("(c > b) || (a < c): {}", (c > b) || (a < c));
	fmt::println("(a > c) && (c <= a): {}", (a > c) && (c <= a));
	fmt::println("(a > b) && (a <= c): {}", (a > b) && (a <= c));
	fmt::println("(!d) && (a == b): {}", (!d) && (a == b));
	fmt::println("(!d) || (a == b): {}\n", (!d) || (a == b));
}

export void math_functions()
{
	double weight{7.7};
	double num1{14.143315};

	// floor
	fmt::println("Flooring:");
	fmt::println("num1 is floored to: {}", std::floor(num1));
	fmt::println("Weight rounded to floor is: {}\n", std::floor(weight));

	// ceil
	fmt::println("Ceiling:");
	fmt::println("num1 is ceiled to: {}", std::ceil(num1));
	fmt::println("Weight rounded to ceiling: {}\n", std::ceil(weight));

	// absolute value
	double num{-148.145};
	double savings{-4241.73};
	fmt::println("Absoulte Value:");
	fmt::println("ABS of num is: {}", std::abs(num));
	fmt::println("ABS of weight is: {}", std::abs(weight));
	fmt::println("ABS of savings is: {}\n", std::abs(savings));

	// Rounding
	fmt::println("Rounding:");
	// Half-way points are rounded up
	fmt::println("3.654 rounded to: {}", std::round(3.654));
	fmt::println("2.5 rounded to: {}", std::round(2.5));
	fmt::println("2.4 rounded to: {}", std::round(2.4));
	fmt::println("-2.4 rounded to: {}\n", std::round(-2.4));

	// Exponential
	fmt::println("Exponential:");
	double result{std::exp(10)};
	fmt::println("The exponential of 10 is: {}\n", result);

	// Power
	fmt::println("Power:");
	fmt::println("3^4 is: {}", std::pow(3, 4));
	fmt::println("9^3 is: {}", std::pow(9, 3));
	fmt::println("5^7 is: {}\n", std::pow(5, 7));

	// Log (base e (Euler's Number))
	fmt::println("Logs:");
	fmt::println("Base-e log of 1: {}", std::log(1));
	fmt::println("Base-e log of 22026.465794806718: {}", std::log(22026.465794806718));
	fmt::println("Base-e log of 54.59: {}\n", std::log(54.59));

	// Log (base 10)
	fmt::println("Base-10 log of 1000: {}", std::log10(1000));
	fmt::println("Base-10 log of 0.001: {}\n", std::log10(0.001));

	// Log (base 2)
	fmt::println("Base-2 log of 65536: {}", std::log2(65536));
	fmt::println("Base-2 log of 0.125: {}\n", std::log2(0.125));

	// Square Root
	fmt::println("Square Root:");
	fmt::println("sqrt(2): {}", std::sqrt(2));
	fmt::println("sqrt(100): {}", std::sqrt(100));
	fmt::println("sqrt(81): {}\n", std::sqrt(81));
}

export void weird_integral_types()
{
	fmt::println("Weird integral Types:");

	short int var1{10}; // 2 Bytes
	short int var2{20};
	char var3{40}; // 1 Byte
	char var4{50};

	fmt::println("Size of var1: {}", sizeof(var1));
	fmt::println("Size of var2: {}", sizeof(var2));
	fmt::println("Size of var3: {}", sizeof(var3));
	fmt::println("Size of var4: {}\n", sizeof(var4));

	auto result1{var1 + var2};
	auto result2{var3 + var4};

	fmt::println("Size of resul1t: {}", sizeof(result1)); // 4
	fmt::println("Size of result2: {}\n", sizeof(result2)); // 4
}

export void implicit_conversion()
{
	fmt::println("Implicit Conversion in Expression:");
	double price{41.15};
	int units{10};

	auto total_price{price * units};

	fmt::println("Total price: {}", total_price);
	fmt::println("sizeof(total_price): {}\n", sizeof(total_price));

	fmt::println("Implicit Conversion in Assignment:");
	int x{};
	double y{148.13};

	x = y; // double to int

	fmt::println("The value of y is: {}", y);
	fmt::println("The value of x is: {}\n", x);

	fmt::println("sizeof(y): {}", sizeof(y));
	fmt::println("sizeof(x): {}\n", sizeof(x));
}

export void explicit_conversion()
{
	fmt::println("Explicit Conversion in Expression:");
	double x{12.5}, y{34.6};


	fmt::println("Converting data first, then sum:");
	int sum1 = static_cast<int>(x) + static_cast<int>(y);
	fmt::println("The sum1 is: {}\n", sum1);

	fmt::println("Sum then converting data:");
	int sum2 = static_cast<int>(x + y);
	fmt::println("The sum2 is: {}\n", sum2);
}

export void overflow_and_underflow()
{
	fmt::println("Overflow Example:");
	unsigned char data{250};

	fmt::println("unsigned char: \nmin: {} \nmax: {}\n",
		std::numeric_limits<unsigned char>::min(),
		std::numeric_limits<unsigned char>::max()
		);

	++data;
	fmt::println("Data: {}", static_cast<int>(data));
	++data;
	fmt::println("Data: {}", static_cast<int>(data));
	++data;
	fmt::println("Data: {}", static_cast<int>(data));
	++data;
	fmt::println("Data: {}", static_cast<int>(data));
	++data;
	fmt::println("Data: {}", static_cast<int>(data));

	++data;
	fmt::println("Data Overflow: {}\n", static_cast<int>(data)); // 256 -> 0

	fmt::println("Underflow Example:");

	data = 1;;
	fmt::println("Data: {}", static_cast<int>(data));

	--data;
	fmt::println("Data: {}", static_cast<int>(data)); // 0
	--data;
	fmt::println("Data Underflow: {}\n", static_cast<int>(data)); // 255
}