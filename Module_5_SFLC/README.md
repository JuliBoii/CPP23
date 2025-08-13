# Streams, Formatting, Literals and Constants

---

- Topics
  - Input and Output Streams
  - Stream Formatting
  - The Format Library
	- Printing and Formatting facilities from C++23
	- How mainstream compilers support them
	- The `fmt` library to the rescue
  - Literals
  - Constants

---

## Input & Output Streams

Starting with the `iostream` library. Seeing how we can use it for input and output.

### Outputting

Below is a simple example:

```c++
#include <iostream>

int main() {
    std::cout << "Hello C++23\n";
    
    int age{24};
    std::cout << "Age: " << age << '\n';
    // std::cerr can be used to print errors
    std::cerr << "Error message: Something is wrong" << std::endl;
    // std::clog can be used to print log messages
    std::clog << "Log message: Something happened\n";
}
```

- The use of `std::cerr` and `std::clog` is for terminal applications/uses
  - The terminal may treat the respective commands differently
- We can end a line that is being printed by using two options
  - `std::endl`
  - `'\n'` or `"\n"`
	- We use single quotes when we know we only want to output the newline character
	  - After outputting some variable data
	- We use double quotes when we add the newline character
	  - When outputting a string
	  - Like the example above
- But the main difference between both methods is that `std::endl` flushes the buffer
  - when it is called
	- Meaning it clears anything in the buffer, which has not been printed
	- Yet, when doing so, we risk clearing data that we may or may not have needed
	- So, we use `'\n'` to start a newline, but not flush the buffer

### Inputting

```c++
#include <iostream>
#include <string>

int main() {
  std::cout << "What is your name and age?\n";
  std::string name{};
  std::getline(std::cin, name);
  constexpr unsigned int age{};
  std::cin >> age;
  std::cout << "Hello " << name << "!\n"
            << "You are " << age << " years old.\n";
}
```

- We can get input in two different manners
- The standard method is using `std::cin` to read data being inputted
  - This method does not work well with reading an entire string
- Thus, we use the second method to read an entire string
- We can use `std::getline()` to read an entire string and store said information into a string type variable
  - But this method requires the use of the `string` library
- The example above showcases this use case

## Stream Formatting

Output Formatting is the way to make our data more appealing.
For example, aligning data to the right or left.
The following, will allow us to set the visual width of we want the next thing we print, to take.
Once again, to use the output formatting commands, we need to add the required library.
So we include the `iomanip` library.

```c++
#include <iostream>
#include <iomanip>

int main() {
	std::cout << "Unformatted Table" << std::endl;
	std::cout << "Daniel" << " " << "Gray" << " " << "25" << std::endl;
	std::cout << "Stanley" << " " << "Woods" << " " << "33" << std::endl;
	std::cout << "Jordan" << " " << "Parker" << " " << "45" << std::endl;
	std::cout << "Joe" << " " << "Ball" << " " << "21" << std::endl;
	std::cout << "Josh" << " " << "Carr" << " " << "25" << std::endl;
	std::cout << "Izaiah" << " " << "Robinson" << " " << "29" << std::endl;
	std::cout << std::endl;

	std::cout << "Formatted Table" << std::endl;
	std::cout << std::setw(10) << "Daniel" << std::setw(10) << "Gray" << std::setw(5) << "25" << std::endl;
	std::cout << std::setw(10) << "Stanley" << std::setw(10) << "Woods" << std::setw(5) << "33" << std::endl;
	std::cout << std::setw(10) << "Jordan" << std::setw(10) << "Parker" << std::setw(5) << "45" << std::endl;
	std::cout << std::setw(10) << "Joe" << std::setw(10) << "Ball" << std::setw(5) << "21" << std::endl;
	std::cout << std::setw(10) << "Josh" << std::setw(10) << "Carr" << std::setw(5) << "25" << std::endl;
	std::cout << std::setw(10) << "Izaiah" << std::setw(10) << "Robinson" << std::setw(5) << "29" << std::endl;
	std::cout << std::endl;
}
```

### `std::setw()`

- When used, it sets the width parameter of the stream `out` or `in` to exactly `n`
- Some operations reset the width to zero
  - So `std::setw()` may need to be repeatedly called to set the width for multiple operations

The Unformatted Table will look like the following:

```text
Unformatted Table
First Name Last Name Age
Daniel Gray 25
Stanley Woods 33
Jordan Parker 45
Joe Ball 21
Josh Carr 25
Izaiah Robinson 29
```

With the formatted table looking like:

```text
Formatted Table
First Name Last Name  Age
    Daniel      Gray   25
   Stanley     Woods   33
    Jordan    Parker   45
       Joe      Ball   21
      Josh      Carr   25
    Izaiah  Robinson   29
```

We can also utilize variables to make universal changes,
without having to change each `std::setw()` instance manually.

```c++
std::cout << "Foramtted Table with Variables:" << std::endl;

int column_width{14};

std::cout << std::setw(column_width) << "First name" << std::setw(column_width) << "Last Name" << std::setw(column_width/2) << "Age" << std::endl;
std::cout << std::setw(column_width) << "Daniel" << std::setw(column_width) << "Gray" << std::setw(column_width/2) << "25" << std::endl;
std::cout << std::setw(column_width) << "Stanley" << std::setw(column_width) << "Woods" << std::setw(column_width/2) << "33" << std::endl;
std::cout << std::setw(column_width) << "Jordan" << std::setw(column_width) << "Parker" << std::setw(column_width/2) << "45" << std::endl;
std::cout << std::setw(column_width) << "Joe" << std::setw(column_width) << "Ball" << std::setw(column_width/2) << "21" << std::endl;
std::cout << std::setw(column_width) << "Josh" << std::setw(column_width) << "Carr" << std::setw(column_width/2) << "27" << std::endl;
std::cout << std::setw(column_width) << "Izaiah" << std::setw(column_width) << "Robinson" << std::setw(column_width/2) << "29" << std::endl;
```

### Output Alignment

We can also change the alignment, of the data.
The following commands modify the positioning of the fill characters in an output stream.

- Alignment can one of three options
  - `std::left`
  - `std::right`
	- `left` and `right` apply to any type being output
  - `std::internal`
	- `internal` applies to integer, floating-point, and monetary output
	- Most use this alignment to fix the negative sign from the number
- All the options have no effect on input
- The initial default for standard streams is equivalent to right

So it would look like the following:

```c++
std::cout << "Foramtted Table with Variables:" << std::endl;

int column_width{14};

std::cout << std::left;
std::cout << std::setw(column_width) << "First name" << std::setw(column_width) << "Last Name" << std::setw(column_width/2) << "Age" << std::endl;
std::cout << std::setw(column_width) << "Daniel" << std::setw(column_width) << "Gray" << std::setw(column_width/2) << "25" << std::endl;
std::cout << std::setw(column_width) << "Stanley" << std::setw(column_width) << "Woods" << std::setw(column_width/2) << "33" << std::endl;
std::cout << std::setw(column_width) << "Jordan" << std::setw(column_width) << "Parker" << std::setw(column_width/2) << "45" << std::endl;
std::cout << std::setw(column_width) << "Joe" << std::setw(column_width) << "Ball" << std::setw(column_width/2) << "21" << std::endl;
std::cout << std::setw(column_width) << "Josh" << std::setw(column_width) << "Carr" << std::setw(column_width/2) << "27" << std::endl;
std::cout << std::setw(column_width) << "Izaiah" << std::setw(column_width) << "Robinson" << std::setw(column_width/2) << "29" << std::endl;
```

We may not necessarily have to import the library where alignment is defined.
Since it is implicitly included through `iomanip`.
But to be on the safe side, you could include it by adding the header `ios`

### `std::setfill()`

- When used in an expression `out << setfill(c)`
  - it sets the fill character of the stream `out` to `c`
  - With `c` being a new value for the fill character

Applying this to our existing table code will look like the following:

```c++
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
```

Which will output the following:

```text
Table with fill characters:
First Name**********Last Name***********Age*******
Daniel**************Gray****************25********
Stanley*************Woods***************33********
Jordan**************Parker**************45********
Joe*****************Ball****************21********
Josh****************Carr****************27********
Izaiah**************Robinson************29********
```

### `std::boolalpha` & `std::noboolalpha`

- This enables the boolalpha flag in the stream
- Disables the boolalpha flag in the stream

`std::boolalpha` is an I/O manipulator, so it may be called with an expression such as `out << std::boolalpha` for any
out or with an expression such as `in >> std::boolalpha` for any in. Having the following output when used:

```text
Default Bool Output Format:
condition: 1
other_condition: 0

boolalpha Output Format:
condition: true
other_condition: false

noboolalpha Output Format:
condition: 1
other_condition: 0
```

### `std::showpos` & `std::noshowpos`

- Enables or disables the display of the plus sign `+` in non-negative integer output
- Has no effect on input
- `std::showpos` enables the showpos flag in the stream
- `std::noshowpos` disables the showpos flag in the stream

`std::showpos` is an I/O manipulator. Having the following output when used:

```text
Default Positive Number Output Format:
pos_num: 34
neg_num: -34

Show Positive Number Sign Format Output:
pos_num: +34
neg_num: -34

Disable Show Positive Number Sign Format Output:
pos_num: 34
neg_num: -34
```

### `std::uppercase` & `std::nouppercase`

Enables the use of uppercase characters in floating-point and hexadecimal integer output

- `std::uppercase` enables the uppercase flag in the stream
- `std::nouppercase` diables the uppercase flag in the stream

`std::uppercase` is an I/O manipulator. Having the following ouput:

```text
Default Number Output Format:
number (decimal): 717171
number (hexadecimal): af173
number (octal): 2570563

Uppercase Number Output Format:
uppercase number (decimal): 717171
uppercase number (hexadecimal): AF173
uppercase number (octal): 2570563
```

### `std::fixed`, `std::scientific`, & `std::defaultfloat`

Modifies the default formatting for floating-point output.

- `std::fixed` sets the floatfield of the stream to fixed
- `std::scientific` sets the floatfield of the stream to scientific
- `std::hexfloat` sets the floatfield of the stream to fixed and scientific simultaneously
  - Enabling hexadecimal floating-point formatting
  - Which is different from fixed and scientific
- `std::defaultfloat` sets the floatfield of the stream to zero
  - This enables the default floating-point formatting
  - Which is defferent from fixed and scientific

This is an I/O manipulator.
The following is the output, using `std::fixed`:

```text
Fixed Point Output Format:
a: 3.141593
b: 2006.000000
c: 0.000000
```

This is the output, using `std::scientific`:

```text
Scientific Point Output Format:
a: 3.141593e+00
b: 2.006000e+03
c: 1.340000e-10
```

We reset the formatting to default using `std::defaultfloat`, which gives us the following output:

```text
Reset to Default Floating-Point Output Format:
a: 3.14159
b: 2006
c: 1.34e-10
```

### `std::setprecision(n)`

When used in an expression `out << setprecision(n)` or `in >> setprecision(n)`, sets the precision parameter of the
stream `out`
or `in` to exactly `n`.

- With `n` being a new value for precision.
- _If we set the precision to be larger than the data type is capable of_
  - Junk data will fill in the remaining points

Example output below using the variable `double pi{3.1415926535897932384626433832795}`:

```text
Default Floating-Point Precision Output Format:
pi: 3.14159

Floating-Point (10) Precision Output Format:
pi: 3.141592654

Floating-Point (20) Precision Output Format:
pi: 3.141592653589793116
```

### `std::showpoint` & `std::noshowpoint`

Enables or disables the unconditional inclusion of the decimal point character in floating-point output.
Has no effect on input.

- `std::showpoint` enables the showpoint flag in the stream
- `std::noshowpoint` disables the showpoint flag in the stream

This is an I/O manipulator.

Example output below:

```text
Show Point Format Output:
d: 34.1000
e: 101.990
f: 12.0000
g: 55

No Show Point Format Output:
d: 34.1
e: 101.99
f: 12
g: 55
```

---

## Format Library

Comparison of `<format>` and `<iostream>`

| Feature                    | `<format>` C++20               | `<iostream>`                              |
|----------------------------|--------------------------------|-------------------------------------------|
| Syntax Simplicity          | Clean `'{}'` placeholders      | Verbose; needs manipulators like `setw()` |
| Type Safety                | Compile-time `type` checks     | Errors occur at runtime                   |
| Performance                | Faster; Compile-time optimized | Slower; Runtime overhead                  |
| Formatting Options         | Rich, Compact syntax           | Verbose; multiple calls/manipulators      |
| Customizability            | Easy via `std::formatter`      | Requires `operator<<` overloads.          |
| Localization               | Supported when needed          | Default, but needs customization          |
| Error-Prone Constructors   | Eliminates format string issue | Safer than `printf`, but lacks checks     |
| Readability                | Compact and expressive         | Verbose for complex formatting            |
| Strings                    | Produces strings directly      | Needs `std::ostringstream`                |
| Extensibility              | Flexible for custom types      | Limited; needs overloads/manipulators     |
| Cross-Platform Consistency | Uniform across platforms       | Relies on `std::locale`                   |

C++23 adds `std::print` and `std::println`, but moving forward in the course we will be working with `fmt`.
Below is an example of the `<print>` library.

**_Reminder that some compilers do support this library, but not all IDE's (ex. CLion) will support the latest compiler or build system_**

Formatting Library

- Text formatting library offers a safe and extensible alternative to the `printf` family of functions
- It is intended to complement the existing C++ I/O streams library
- **_Again, this libraries main function is to format data not print_**
- Starting from C++23 the standard library introduces convenient functions like `std::print` and `std::println` for formatted output
- These functions simplify output by allowing easy formatting directly to standard streams
  - Without the verbosity of `std::cout` or `printf`
- Not all compilers fully support C++23 features
  - Including `std::print` and `std::println`
- If your compiler supports these functions, use them
  - As they align with modern C++ practices
- We will be using the `fmt` library, which provides similar functionality
  - With `fmt::print` and `fmt::println`, ensuring portability and consistency
- Using fmt, we can take advantage of modern formatting capabilities today
  - Even on compilers that do not yet fully support C++23

```c++
	auto value = std::format("Hello, {}!", "World");
	std::cout << value << '\n';
	const std::array<std::string, 6> first_name{"Daniel", "Stanley", "Jordan", "Joe", "Josh", "Izaiah"};
	const std::array<std::string, 6> last_name{"Gray", "Woods", "Parker", "Ball", "Carr", "Robinson"};
	constexpr std::array<unsigned int, 6> age{25u, 33u, 45u, 21u, 27u, 29u};

	std::print("Hello, {}!\n", "World");
	std::print("Hello, {}!", "World\n");
	std::println("Unformatted Table:");
	for (int i = 0; i < 6; i++)
	{
		std::println("{} {} {}", first_name[i], last_name[i], age[i]);
	}
```

- Each line of code prints a formatted string containing:
  - A person's first name, last name, age
- The `{}` symbols in the string are placeholders
  - Which will be replaced with the corresponding values
    - ex. "Daniel", "Gray", "25"
- The `std::println` function from the `<print>` library
  - Ensures the formatted string is printed to the console
  - Followed by a newline
- The same format `("{} {} {}")` is reused for each line
  - Simplifying the process of printing consistent output
- The output will appear neatly as one line per person with their name and age

As shown below:

```text
Unformatted Table:
First Name Last Name Age
Daniel Gray 25
Stanley Woods 33
Jordan Parker 45
Joe Ball 21
Josh Carr 27
Izaiah Robinson 29

```

We can also add formatting to the lines being printed, as shown below:

```c++
	std::println("Formatted Table:");
	for (int i = 0; i < 6; i++)
	{
		std::println("{:<10} {:<10} {:<5}", first_name[i], last_name[i], age[i]);
	}
```

- The first line creates a header formatted (First Name, Last Name, Age)
  - With consistent column widths for readability
- The `{:<10}, {:<5}` placeholders ensure lef-aligned text
  - With column widths of 10 and 5 respectively.
- The output appears as a table where data is organized into three neatly aligned columns
- 

Having the following output:

```text
First Name Last Name  Age  
Daniel     Gray       25   
Stanley    Woods      33   
Jordan     Parker     45   
Joe        Ball       21   
Josh       Carr       27   
Izaiah     Robinson   29 
```

## `<fmt>`

We can also use external formatting libraries, such as `<fmt>`. Which we have been using so far.
But using external libraries is not as easy to import as built-in libraries. That is why we are using
`vcpkg` to help import and manage our external libraries. Which we learned about previously. In this case,
we can simply change `std` to `fmt` and import the `fmt/format` library.

```c++
#include <fmt/format.h>

int main() {
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

	fmt::println("Formatted Table:");
	for (int i = 0; i < 6; i++)
	{
		if (i == 0)
			fmt::println("{:<10} {:<10} {:<5}", "First Name", "Last Name", "Age");
		fmt::println("{:<10} {:<10} {:<5}", first_name[i], last_name[i], age[i]);
	}

}
```

### Dynamic Tables with Formatting

Another example is:

```c++
	// Dynamic Widths
	constexpr int col_width{10};

	fmt::println("Formatted table with Dynamic Widths:");
	for (int i = 0; i < 6; i++)
	{
		if (i == 0)
			fmt::println("{:<{}} {:<{}} {:<{}}", "First Name", col_width, "Last Name", col_width, "Age", col_width/2);
		fmt::println("{:<{}} {:<{}} {:<{}}", first_name[i], col_width, last_name[i], col_width, age[i], col_width/2);
	}
```

- Placeholders with Widths:
  - The `{:<{}}` placeholders use:
    - Left-aligned formatting `(:<)`
    - Column widths determined by `col_width` 
      - Or `col_width/2` for the "Age" column

### Bool Values with Formatting

- By default, `fmt::println` formats Bool Values as `true` or `false`
  - When using `{}` placeholders
- The `{:d}` placeholder is a workaround to format Bool Values as integers
  - `1` for True
  - `0` for False
  - As the library does not natively support formatting for Bools yet.

### Show Sign for Positive Numbers

- We can also format to show or hide the `+` sign for positive numbers
- To show the sign we add the following inside the `{}` placeholders
  - `:+` is added inside the placeholders

Example below:

```c++
	constexpr int positive_num{34}, negative_num{-23};

	fmt::println("Positive Number: {}", positive_num);
	fmt::println("Negative Number: {}", negative_num);

	fmt::println("Positive Number: {:+}", positive_num);
	fmt::println("Negative Number: {:-}", negative_num);
```

Giving the following output:

```text
Positive Number: 34
Negative Number: -23
Positive Number: +34
Negative Number: -23
```

### Changing Number Systems

We can also control the number system our integer data is represented as.

#### Decimal

```c++
#include <fmt/format.h>

int main() {
	constexpr int case_number{717171};
	fmt::println("case_number (decimal): {}", case_number);
}
```

Output:

```text
case_number (decimal): 717171
```

#### Hexadecimal (Upper and Noupper)

```c++
	...
	fmt::println("case_number (hexadecimal): {:x}", case_number);
	fmt::println("case_number (Hex): {:X}", case_number);
	...
```

Output:

```text
case_number (hexadecimal): af173
case_number (Hex): AF173
```

#### Octal

```c++
	...
	fmt::println("case_number (octal): {:o}", case_number);
	...
```

Output:

```text
case_number (octal): 2570563
```

#### Binary

```c++
	...
	fmt::println("case_number (Binary): {:b}\n", case_number);
	...
```

Output:

```text
case_number (Binary): 10101111000101110011
```

#### Showbase for Numbers

```c++
	fmt::println("case_number (Hex): {:#X}", case_number);
	fmt::println("case_number (Octal): {:#o}", case_number);
	fmt::println("case_number (Binary): {:#b}", case_number);
```

Output:

```text
case_number (Hex): 0XAF173
case_number (Octal): 02570563
case_number (Binary): 0b10101111000101110011
```

### Floating-Point Formatting

#### Controlling Precision

```c++
#include <fmt/format.h>

int main() {
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
}
```

Output:

```text
Double values (Default)
pi: 3.141592653589793
double: 2006.2
scientific double: 1.34e-10

Double Values (Precision: 6)
pi: 3.14159
double: 2006.2
scientific double: 1.34e-10
```

#### Fixed Precision

```c++
	...
	fmt::println("Double Values (Fixed: 6)");
	fmt::println("pi: {:.6f}", long_double);
	fmt::println("double: {:.6f}", stand_double);
	fmt::println("scientific double: {:.6f}\n", sci_double);

	fmt::println("Double Values (Fixed: 10)");
	fmt::println("pi: {:.10f}", long_double);
	fmt::println("double: {:.10f}", stand_double);
	fmt::println("scientific double: {:.10f}\n", sci_double);
	...
```

Output:

```text
Double Values (Fixed: 6)
pi: 3.141593
double: 2006.200000
scientific double: 0.000000

Double Values (Fixed: 10)
pi: 3.1415926536
double: 2006.2000000000
scientific double: 0.0000000001
```

#### Scientific Precision

```c++
	...
	fmt::println("Double Values (Scientific: 6)");
	fmt::println("pi: {:.6e}", long_double);
	fmt::println("double: {:.6e}", stand_double);
	fmt::println("scientific double: {:.6e}\n", sci_double);

	fmt::println("Double Values (Scientific: 10)");
	fmt::println("pi: {:.10e}", long_double);
	fmt::println("double: {:.10e}", stand_double);
	fmt::println("scientific double: {:.10e}\n", sci_double);
	...
```

Output:

```text
Double Values (Scientific: 6)
pi: 3.141593e+00
double: 2.006200e+03
scientific double: 1.340000e-10

Double Values (Scientific: 10)
pi: 3.1415926536e+00
double: 2.0062000000e+03
scientific double: 1.3400000000e-10
```

### Specify Argument Indexes

We can specify the order things will print out by specifying the argument index.

```c++
	...
	fmt::println("Argument Indexes:");
	fmt::println("It is {:.2f} degrees outside and it is {}", 34.5, "sunny");
	fmt::println("It is {1} degrees outside and it is {0:.2f}", 34.5, "sunny");
	...
```

- In the first `println()` we do not specify the order of the argument indexes
  - Thus, the print order is done by FIFO
- The second `println()` does specify the order with the added indexes `{1}` and `{0:`
  - Thus, the order is specified in how we want things printed.

Having the following output:

```text
Argument Indexes:
It is 34.50 degrees outside and it is sunny
It is sunny degrees outside and it is 34.50
```


### General Form for Format Specifiers

The next thing we want to check out is how to specify argument indexes.
Which is something available in the `format` library.
With the format structure being:

```text
[[fill]align][sign][#][0][width][.precision][type]
```

- `[fill]`
  - Specifies the character used to fill any unused space 
    - when the value does not fully occupy the specified width
  - Default is space, but you can choose other characters (e.g. 0 for padding zeros)
  - Example:
    - `0` fills space with zeros (e.g., `0` in `{:0>10}`)
- `[align]`
  - Specifies the alignment of the value within its field
  - Options:
    - `<`: Left-align the value
    - `>`: Right-align the value (default)
    - `^`: Centers the value
  -Example:
    - `{:>10}` aligns the value to the right
- `[sign]`
  - Specifies whether to show a sign for numbers
  - Options
    - `+`: Forces a sign to appear for both positive and negative numbers (e.g., `+5`, `-5`)
    - `-`: Only negative numbers have a sign (default for numeric types).
  - Example:
    - `{:5}` will output positive and negative numbers with a sign if specified

```c++
	...
	fmt::println("Argument Indexes:");
	fmt::println("It is {:.2f} degrees outside and it is {}", 34.5, "sunny");
	fmt::println("It is {1} degrees outside and it is {0:.2f}", 34.5, "sunny");
	...
```

---
