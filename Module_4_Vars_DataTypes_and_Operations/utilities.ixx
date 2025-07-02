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

	int int_var{55};			// 4 Bytes
	signed signed_var{4566};
	signed int signed_int{-21474836};
	unsigned int unsigned_int{42949672};

	long long_var{88};			// 4 or 8 Bytes
	long int long_int{33};
	signed long signed_long_var{44};
	signed long int signed_long_int{44};
	unsigned long int unsigned_long_int{44};

	long long long_long{888};	// 8 Bytes
	long long int long_long_int{999};
	signed long long signed_long_long_var{999};
	signed long long int signed_long_long_int{1234};
	unsigned long long int unsigned_long_long_var{1234};
}
