# Streams, Formatting, Literals and Constants

---

- Topics
  - Input and Output Streams
  - Stream Formatting
  - The Format Library
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

When used in an expression `out << setprecision(n)` or `in >> setprecision(n)`, sets the precision parameter of the stream `out`
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

