# Custom Types

Custom types are a mechanism that allows one to build a C++ type (built from fundamental C++ data types). The core
concept will be the `class` keyword, which we use to set up these custom data types.

<!--@formatter:off-->
<!-- TOC -->
* [Custom Types](#custom-types)
  * [Creating a `class`](#creating-a-class)
    * [Member Functions to access `private` variables](#member-functions-to-access-private-variables)
    * [Constructors](#constructors)
    * [Destructors](#destructors)
  * [Explicit Object Parameters (C++23)](#explicit-object-parameters-c23)
    * [Recursive Lambda's](#recursive-lambdas)
    * [Rules and Restrictions](#rules-and-restrictions)
<!-- TOC -->
<!--@formatter:on-->

## Creating a `class`

For this example, we will be making a pixel type. The type is called `Pixel`.

```c++
namespace custom_type_struct {
    struct Pixel {
        // A struct defaults to public members
        uint32_t m_color{0xFF000000};
        unsigned int pos_x{0};
        unsigned int pos_y{0};
    };
}
```

> Note: We use `struct` rather than the `class` keyword here.
> A `struct` and `class` are functionally identical, but differ in how their default access specifiers and default
> inheritance behaviors. Additionally, `struct`'s cannot be used as type parameter keywords for templates—A topic
> soon to be covered—, while `class` can.

In the `Pixel` body, we specify what is making up the pixel data type. In this case, a `Pixel` is defined by three
pieces of information:

- The Color of the pixel
  - A 32-bit integer
  - A hex value containing:
    - The red value
    - The green value
    - The blue value
    - Transparency/Alpha value
- The Position of the `Pixel`
  - Both being `unsigned int`
    - An x-axis position (increasing from left to right)
    - A y-axis position (increasing from top to bottom)
    - We will not support negative value positions, in this example

As we stated in our note, a `struct` defaults has a different, default, access specifier to a `class`. A `struct`
defaults to having a `public` access specifier. This `public` keyword controls the visibility and accessibility of
class members—variables and functions.

This keyword, along with `private`, form the backbone of encapsulation by separating an object's interface from its
internal implementation.

So, a `public` access specifier allows access from anywhere in the program where the object is visible. While a
`private` access specifier allows accessibility **only** within the class itself. Thus, a `class` will default to a
`private` access specifier. This does not mean we cannot change the respective behaviors, we just have to use the
respective keyword in the body of the `struct`/`class`. Thus, changing the accessibility behavior of anything
following the declaration of the keyword.

For example, the same `Pixel` type can be made using `class` but we need to use the `public` keyword, in order to
achieve the same behavior as the `struct` example.

```c++
namespace custom_type_class {
    class Pixel {
        public:
            uint32_t m_color{0xFF000000};
            unsigned int pos_x{0};
            unsigned int pos_y{0};
    };
}
```

Any variable/member function declared prior to the `public` keyword, would have a `private` accessibility behavior.

This results in the ability to do the following:

```c++
#include <fmt/format.h>

auto main() -> int {
    custom_types_struct::Pixel p1{};
    custom_types_class::Pixel p2{};

    fmt::println("Struct Pixel Color: {:#010x}", p1.m_color);
    fmt::println("Struct Pixel Position: ({}, {})\n", p1.x_position, p1.y_position);

    fmt::println("Class Pixel Color: {:#010x}", p2.m_color);
    fmt::println("Class Pixel Position: ({}, {})", p2.x_position, p2.y_position);
    return 0;
}
```

In both cases we are able to access the data variables that make up the `Pixel` object. The `public` allows one to
access variables/functions within the object without any abstraction. Meaning, we are able to directly access the
varaibles/functions.

Otherwise, especially with default `class`, the accessibility of variables/functions would not straight forward.
Thus, with `private` variables/functions we need setters/getters to access the members. That is if we even want such
variables/functions to be accessed. Which coincides with the topics of Abstraction and Encapsulation.

But an example will be showcased below:

```c++
namespace custom_type_struct {
    ...
    struct Pixel_P {
        private:
          uint32_t m_color{0xFF000000};
          unsigned int pos_x{0};
          unsigned int pos_y{0};
    };
}

namespace custom_type_class {
    ...
    class Pixel_P {
        uint32_t m_color{0xFF000000};
        unsigned int pos_x{0};
        unsigned int pos_y{0};
    };
}
```

Using the same example, replacing `Pixel` with `Pixel_P`:

```c++
auto main() -> int {
    custom_types_struct::Pixel_P p1{};
    custom_types_class::Pixel_P p2{};

    fmt::println("Struct Pixel Color: {:#010x}", p1.m_color);
    fmt::println("Struct Pixel Position: ({}, {})\n", p1.x_position, p1.y_position);

    fmt::println("Class Pixel Color: {:#010x}", p2.m_color);
    fmt::println("Class Pixel Position: ({}, {})", p2.x_position, p2.y_position);
    return 0;
}
```

We get the following output when trying to compile the program:

```terminaloutput
/tmp/Module_12_Custom_Types/utilities.ixx:24:53: error: 'm_color' is a private member of 'custom_types_struct::Pixel_P'
   24 |     fmt::println("Struct Pixel Color: {:#010x}", p1.m_color);
      |                                                     ^
/tmp/Module_12_Custom_Types/custom_types.ixx:16:23: note: declared private here
   16 |         std::uint32_t m_color{0xFF000000};
      |                       ^
/tmp/Module_12_Custom_Types/utilities.ixx:25:58: error: 'x_position' is a private member of 'custom_types_struct::Pixel_P'
   25 |     fmt::println("Struct Pixel Position: ({}, {})\n", p1.x_position, p1.y_position);
      |                                                          ^
/tmp/Module_12_Custom_Types/custom_types.ixx:17:22: note: declared private here
   17 |         unsigned int x_position{0};
      |                      ^
/tmp/Module_12_Custom_Types/utilities.ixx:25:73: error: 'y_position' is a private member of 'custom_types_struct::Pixel_P'
   25 |     fmt::println("Struct Pixel Position: ({}, {})\n", p1.x_position, p1.y_position);
      |                                                                         ^
/tmp/Module_12_Custom_Types/custom_types.ixx:18:22: note: declared private here
   18 |         unsigned int y_position{0};
      |                      ^
/tmp/Module_12_Custom_Types/utilities.ixx:27:52: error: 'm_color' is a private member of 'custom_types_class::Pixel_P'
   27 |     fmt::println("Class Pixel Color: {:#010x}", p2.m_color);
      |                                                    ^
/tmp/Module_12_Custom_Types/custom_types.ixx:31:23: note: implicitly declared private here
   31 |         std::uint32_t m_color{0xFF000000};
      |                       ^
/tmp/Module_12_Custom_Types/utilities.ixx:28:55: error: 'x_position' is a private member of 'custom_types_class::Pixel_P'
   28 |     fmt::println("Class Pixel Position: ({}, {})", p2.x_position, p2.y_position);
      |                                                       ^
/tmp/Module_12_Custom_Types/custom_types.ixx:32:22: note: implicitly declared private here
   32 |         unsigned int x_position{0};
      |                      ^
/tmp/Module_12_Custom_Types/utilities.ixx:28:70: error: 'y_position' is a private member of 'custom_types_class::Pixel_P'
   28 |     fmt::println("Class Pixel Position: ({}, {})", p2.x_position, p2.y_position);
      |                                                                      ^
/tmp/Module_12_Custom_Types/custom_types.ixx:33:22: note: implicitly declared private here
   33 |         unsigned int y_position{0};
      |                      ^
6 errors generated.
```

Showcasing the difference in accessibility between the two keywords. Thus, the variables are not accessible, unless
we go through member functions designated to access them. But, even those member functions have to be something the
developer intends to allow. Otherwise, there would be no way of access.

Overall, both `struct` and `class` can be used to create custom types. However, there default behavior gives some
insight to how they are used.

In general, `struct`'s are mainly used for Plain Old Data (POD) or Passive Data. Which is a simple bundle of related
variables that can vary independently without breaking complex rules. While `class`'s are mainly used for Active
Objects & Encapsulation. So, types that manage internal logic, maintain strict data invariants, hide implementation
details from the outside world, or leverages object-oriented design patterns.

> Additionally, C++ does not differentiate how memory is allocated for a `struct` or `class`. Both can either live
> in the stack or the heap, depending on how they are initiated.

Now, let us delve more into Encapsulation using our `Pixel` class.

### Member Functions to access `private` variables

In our following example we will be adding setters and getters to our `Pixel` class to be able to modify and access
data that is `private`. However, it should be noted that one should not always add setters and getters for every
data member. There should be a level of abstraction, that allows a user to modify the data without knowing what the
actual structure of the object is.

For this example though we will be adding them for all our `private` variables.

```c++
...
    class Pixel {
        uint32_t m_color{0xFF000000};
        unsigned int pos_x{0};
        unsigned int pos_y{0};
    
    public:
        // Setters
        auto set_color(const std::uint32_t &new_color) -> void {
            m_color = new_color;
        }

        auto set_x_position(const unsigned int &new_x_position) -> void {
            x_position = new_x_position;
        }

        auto set_y_position(const unsigned int &new_y_position) -> void {
            y_position = new_y_position;
        }

        // Getters
        [[nodiscard]] auto get_color() const -> std::uint32_t {
            return m_color;
        }

        [[nodiscard]] auto get_x_position() const -> unsigned int {
            return x_position;
        }

        [[nodiscard]] auto get_y_position() const -> unsigned int {
            return y_position;
        }
    };
...
```

It should be noted that for our setters, we are passing the values by reference. While for our getters, we are
making the functions themselves `const`. The main purpose due to the nature of a getter function. A getter function
is not meant to modify data, simply return the desired information. Thus, adding the `const` keyword to the end of the
function declaration ensures the compiler to flag any code within the function's definition that modifies the data
members. Protecting the programmer from an inadvertent mistake.

### Constructors

Now let us look at methods to initialize data variables when we declare a new object. To do this, we use
constructors. Which are special member functions that are automatically called when an object of a class is created.
The primary purpose is to initialize the object's data members and allocate resources, ensuring the object starts
its life in a valid state.

> Constructors need to be `public` if one wants them to create objects.

The constructor will have the same name as the `class`.

```c++
...
    class Pixel {
        ...
    
    public:
        Pixel(const std::uint32_t color, const unsigned int x, const unsigned int y) {
            m_color = color;
            x_position = x;
            y_position = y;
        }
        ...
    };
...
```

By setting up a constructor, we lose the ability to simply declare a new object without using the proper initialization.
Therefore, `custom_type_class::Pixel p;` would result in a compiler error. Since there exists a proper way to initialize
a new object of type `Pixel`. To be able to use the previous syntax to declare and "initialize" a new object, we need to
define a `default` constructor. To do so we add the following:

```c++
...
    class Pixel {
        ...
    
    public:
        Pixel() = default;
    
        Pixel(const std::uint32_t color, const unsigned int x, const unsigned int y) {
            m_color = color;
            x_position = x;
            y_position = y;
        }
        ...
    };
...
```

In general, it is best practice to initialize the data members in the `class`. Since, the compiler may, in some
cases, call the default initializer. But if the data members are not initialized, junk data would be stored and
could result in undefined behavior if used unintentionally.

### Destructors

A destructor is also a special function in C++ `class`. It is automatically executed when an object goes out of
scope or is explicitly deleted. While a constructor initializes an object when it is created, a destructor handles
the cleanup, acting as the "opposite" of a constructor to release resources like dynamic memory, file pointers, or
network connections.

Destructors also have a specific syntax when being declared.

```c++
...
    class Pixel {
        ...
    
    public:
        ...
        // Destructor
        ~Pixel();
        ...
    };
...
```

- Like a constructor, a destructor shares the exact same name as the `class` but is prefixed with a tilde `~`
- Has no arguments or return type
- Is automatically invoked
  - Very rarely called manually
  - Compiler tends to call it automatically when a stack object leaves its scope
    - Or when `delete` is called on a heap pointer
- Objects are destroyed in the exact reverse order of their construction (Last-in, First-out)

The compiler tends to make a default constructor, even if we do not define one. Which is more than enough, especially
if we are only working with basic variables (`int`, `float`, etc.) or standard containers (`std::string`, `std::vector`,
etc.). Since the compiler cleans up stack-allocated variables automatically.

However, if we are working with raw pointers, open system files, or work with multithreading. It is essential for a
custom destructor, since we need to manually deallocate the memory. In order to prevent memory leaks.

## Explicit Object Parameters (C++23)

Explicit object parameters, also known as "deducing `this`" is a C++23 feature that allows one to explicitly declare
the object parameter (the `this` pointer) as the first parameter of a non-static member function.

Instead of relying on an implicit, hidden `this` pointer, one prefixes the first parameter with the `this` keyword.
Most would label the keyword with the name `self`. **If added to a member function, this declaration has to be the first
parameter in the list, if any.**

In previous C++ standards, member functions (functions with-in a `class`) would have a hidden `this` parameter. Now,
it is being made explicit, if one desires. So, it would look like the following:

```c++
class Pixel {
    void increment_x_position() {
        this->x_position++; // Tradtional C++ style
    }
    
    // Modern C++23 style
    void increment_y_position(this Pixel& self) {
        self.y_positon++;
    }
};
```

> It should be noted that a member function that uses an explicit object parameter, cannot use the `this` keyword as
> a pointer. One must interact directly with the parameter named, in the example above it would be through `self`.

### Recursive Lambda's

This also works for making lambda's recursive. Since lambdas are translated into anonymous classes with an implicit
`operator()`, they previously (to C++23) could not call themselves. With explicit object parameters, a lambda is
allowed to capture itself as a parameter, making recursion straightforward.

```c++
#include <print>

auto main() -> int {
    auto fib = [](this auto self, int n) -> int {
        return n <= 1 ? n : self (n - 1) + self (n - 2);
    };
    
    std::println("fib(10) = {}", fib(10));
    
    return 0;
}
```

### Rules and Restrictions

- Syntax Position:
  - The `this` keyword is only valid on the very first parameter of a non-static member function
- No Specifier on the Right:
  - Cannot combine explicit object parameters with traditional trailing cv-qualifiers or ref-qualifiers
    - Example: `void foo(this X self) const;`
      - Results in a compiling error
- Static or Virtual:
  - Functions utilizing an explicit object parameter **cannot** be marked `static` or `virtual`

