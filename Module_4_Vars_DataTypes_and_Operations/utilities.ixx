module;

# include <fmt/format.h>
# include <limits>

export module utilities;

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
		std::numeric_limits<unsigned long >::max()
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

export void types_of_initializers()
{
	fmt::print("Braced Initialization Example:\n");
	int elephant_count;	// Initialized to junk
	int lion_count{};	// Initialized to zero
	int dog_count{10};	// Initialized to 10
	int cat_count{15};	// Initialized to 15

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

	short short_var{-32768};	// 2 Bytes
	short int short_int{455};
	signed short signed_short_var{-122};
	signed short int signed_short_int{-456};
	unsigned short int unsigned_short_int{456};

	fmt::print("short_var: {}\nsizeof(short_var): {}\n", short_var, sizeof(short_var));
	fmt::print("\nshort_int: {}\nsizeof(short_int): {}\n", short_int, sizeof(short_int));
	fmt::print("\nsigned_short_var: {}\nsizeof(signed_short_var): {}\n", signed_short_var, sizeof(signed_short_var));
	fmt::print("\nsigned_short_int: {}\nsizeof(signed_short_int): {}\n", signed_short_int, sizeof(signed_short_int));
	fmt::print("\nunsigned_short_int: {}\nsizeof(unsigned_short_int): {}\n", unsigned_short_int, sizeof(unsigned_short_int));

	int int_var{55};			// 4 Bytes
	signed signed_var{4566};
	signed int signed_int{-21474836};
	unsigned int unsigned_int{42949672};

	fmt::print("\nint_var: {}\nsizeof(int_var): {}\n", int_var, sizeof(int_var));
	fmt::print("\nsigned_var: {}\nsizeof(signed_var): {}\n", signed_var, sizeof(signed_var));
	fmt::print("\nsigned_int: {}\nsizeof(signed_int): {}\n", signed_int, sizeof(signed_int));
	fmt::print("\nunsigned_int: {}\nsizeof(unsigned_int): {}\n", unsigned_int, sizeof(unsigned_int));

	long long_var{-922337};			// 4 or 8 Bytes
	long int long_int{9223};
	signed long signed_long_var{-9223372};
	signed long int signed_long_int{9223372};
	unsigned long int unsigned_long_int{1844674};

	fmt::print("\nlong_var: {}\nsizeof(long_var): {}\n", long_var, sizeof(long_var));
	fmt::print("\nlong_int: {}\nsizeof(long_int): {}\n", long_int, sizeof(long_int));
	fmt::print("\nsigned_long_var: {}\nsizeof(signed_long_var): {}\n", signed_long_var, sizeof(signed_long_var));
	fmt::print("\nsigned_long_int: {}\nsizeof(signed_long_int): {}\n", signed_long_int, sizeof(signed_long_int));
	fmt::print("\nunsigned_long_int: {}\nsizeof(unsigned_long_int): {}\n", unsigned_long_int, sizeof(unsigned_long_int));

	long long long_long{92233720365477};	// 8 Bytes
	long long int long_long_int{922337236854};
	signed long long signed_long_long_var{-92233736854775};
	signed long long int signed_long_long_int{-922337205807};
	unsigned long long int unsigned_long_long_var{184467440770955};

	fmt::print("\nlong_long: {}\nsizeof(long_long): {}\n", long_long, sizeof(long_long));
	fmt::print("\nlong_long_int: {}\nsizeof(long_long_int): {}\n", long_long_int, sizeof(long_long_int));
	fmt::print("\nsigned_long_long_var: {}\nsizeof(signed_long_long_var): {}\n", signed_long_long_var, sizeof(signed_long_long_var));
	fmt::print("\nsigned_long_long_int: {}\nsizeof(signed_long_long_int): {}\n", signed_long_long_int, sizeof(signed_long_long_int));
	fmt::print("\nunsigned_long_long_var: {}\nsizeof(unsigned_long_long_var): {}\n", unsigned_long_long_var, sizeof(unsigned_long_long_var));
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

	float number4 = 192400023.0f;	// Error: Narrowing Conversion

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
	double number2{};	// Init to 0
	double number3{};	// Init to 0

	// Infinity
	double result{number1 / number2};

	fmt::println("{} / {} yields {}", number1, number2, result);
	fmt::println("{} + {} yields {}", result, number1, result + number1);

	// NaN
	result = number2 / number3;

	fmt::println("{} / {} yields {}", number2, number3, result);
}