# Flow Control

---

## Topics

- If statement
- Switch
- Ternary Operator
- `std::unreachable` (C++23)
- Loops:
    - `for()`
    - `while()`
    - `do{} while()`
- Comma Operator

---

- Flow control are tools that C++, or any programming language, provides to control the flow of your program
    - Through the execution pipeline
- Using the tools, we can decide the path an instruction takes
    - We will also see different facilities that C++ provides.
    - Like:
        - Switches
        - Ternary operators
        - etc.

---

## If Statements

Facility that will allow you to make decisions in your C++ program

Example:

```c++
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
```

- Based on the result of the code above
    - We can do decisions
- We can say:
    - If result is true:
        - We want to do this thing we have within the curly braces
        - Following the syntax:
            - `if( // Conditions ) { // Code to run if conditions met }`
            - Use logical operators for conditions
- We can also implicitly check our conditions
    - we can shorten our condition in the example above
    - Following the syntax:
        - `if (result) {}`
        - This is equivalent to writing out `if (result == true) {}`
- We can also check if the result is `false` rather than `true`
    - Using the following syntax:
        - `if (!result) {}`
        - which is equivalent to: `if (~(result == true)) {}`

We can also set up two branches.
If you say something is `true`, I will run a set of operations.
Otherwise, I am going to run a different set of operations.

Example:

```c++
    if (result == true)
    {
        fmt::println("{} is less than {}", number1, number2);
    }else
    {
        fmt::println("{} is NOT less than {}", number1, number2);
    }
```

- In the example above we combined our previous `if` statements
- If we know our second condition will be true given our first condition fails
    - We simply run the operations for the second condition without checking its condition

### Nested If Statements

We can also do nested `if` statements. Look at the following example:

```c++
  constexpr bool red{false};
  constexpr bool yellow{false};
  constexpr bool green{true};
  constexpr bool police_stop{true};
  
  // If green: go
  // If red, yellow: stop
  // if green and police_stop: stop
  
  ...

  fmt::println("Police Officer Stops (verbose)");
  
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
```

- The code block above showcases an example of a nested `if` statement.
    - But we should also not abuse this function.
    - Nesting large quantities of `if` statements is not good code practice.
        - In general, nesting 2 to 3 `if` statements is common.

Most often, we can shorten the use of nested `if` statements by checking the conditions together.
Meaning, if there already exist a relationship between two or more conditions they can be combined
Using logical operators.

Example below:

```c++
  fmt::println("Police Officer Stops (less verbose)");
  
  if (green && !police_stop)
  {
      fmt::println("Go!");
  } else
  {
      fmt::println("Stop!");
  }
```

### `If` with Initializer

We can initialize a variable within the `if()` parentheses of an `if` statement.

Example below:

```c++
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

```

- At this point we are also providing an initializer variable
- Variable is only accessible within the `if` statement scope
    - if we tried using the variable outside the `if` statement
        - An error would occur when building the program
        - Showcased below:

```c++
error: use of undeclared identifier 'speed'
   99 |         fmt::println("{}", speed);
      |                            ^~~~~
1 error generated.
```

### `else if` statements

While `else if` is not a distinct C++ keyword, it is a standard `else` clause
followed by the `if` statement.

It allows for testing a series of conditions sequentially.

Example:

```c++
  // Tools
  constexpr int pen{10};
  constexpr int marker{20};
  constexpr int eraser{30};
  constexpr int rectangle{45};
  constexpr int circle{15};
  constexpr int ellipse{7};
  
  constexpr int tool{eraser};
  
  if (tool == pens) {
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
```

### `if` statement's scope

We also want to revisit scopes with `if` statements
As previously stated, any variable declared within an `if` statement will
be temporary. Meaning, if one wanted to use said variable later on in
their program. An error would be thrown.

Now, let us focus on the internal scopes.

Looking at the example below:

```c++
#include <print>

int main(int argc, char **argv) {
    bool green {false};
    
    if (green) {
        int car_count{23};
        std::println("The color is green. {} Cars on the move!", car_count);
    } else {
        std::println("The color is not green. Y'all need to stop!");
    }
}
```

We note that we declared a variable within the if-block of the `if` statement.
Would we be able to utilize this variable within the else-block of the `if` statement?

The answer is **no**. An error would be thrown.
Shown below:

```shell
/tmp/Module_6_Flow_Control/utilities.ixx:166:40: error: use of undeclared identifier 'car_count'
  166 |                 std::println("{} cars are stopped.", car_count);
      |                                                      ^~~~~~~~~
1 error generated.
```

Likewise, anything declared in the else-block will be constrained to the scope
of the else-block.

---

## Switch Statements

The `switch` statement is similar to the function of `else if`.
Having the format of:

```c++
switch( conditional )
{
    case //int value or int variable: 
    {
        // Operations
    } break;
    default:
    {
        // Operations
    } break;
}
```

- We pass our conditional in the parentheses of the `switch()` keyword
    - In the curly braces following the `switch()` statement
        - We enter the `case` options we want to check for
            - Where each case could have operations done or "fall down" to the operations of other `cases`
        - After each `case`'s operations, following the curly braces, we add a `break`
            - This ensures that we do not "fall down" to other `case` options and execute their operations, if any
    - At the end of all the `case` options, we add a `default` option
        - The `default` case handles situations we do not account for or simply want to ignore
- Similar to `if` statements, we can add an initializer within the `switch()` parentheses
    - Which also only exist within the `switch()` statements scope

---

## Short Circuit Evaluation

This is a phenomenon that happens when the compiler takes a shortcut and avoids
doing all the work.

**How does this happen?**

```c++
...

constexpr bool a{true}, b{true}, c{true}, d{false};

// AND: If one of the operands is false, the result is false
fmt::println("AND Short Circuit Example:");
constexpr bool result_and{a && b && c && d};
fmt::println("result (AND): {}", result_and);
fmt::println("");

...
```

- Suppose we have the logical expression for `result_and`
    - Acknowledging that an `AND` operator is going to be brought down by a single zero (`false`)
    - i.e., regardless of the numerous `true` statements
        - A single `false` leads to a `false` result
- This is what the compiler does
    - Sees only `AND` operators in the logical expression
    - Find the first zero (`false`)
    - Then decide that the result is going to be zero (`false`)
        - While also ignoring all other evaluations to achieve that result
- Thus, the name `short circuit evaluation`
    - Meaning it is simply a phrase that represents the compilers behavior
        - Ignoring to do all the unnecessary evaluations to achieve the same result

**This also happens with the `OR` operator.**

```c++
...

constexpr bool p{false}, q{false}, r{false}, m{true};

// OR: If one of the operands is true, the result is true
fmt::println("OR Short Circuit Example:");
constexpr bool result_or{a || b || c || d};
fmt::println("result (OR): {}", result_or);
fmt::println("");

...
```

So this has the same concept as the previous operator.

- Suppose we have the logical expression for `result_or`
    - regardless of the numerous `false` statements
        - A single `true` leads to a `true` result
- This is what the compiler does
    - Sees only `OR` operators in the logical expression
    - Find the first one (`true`)
    - Then decide that the result is going to be one (`true`)
        - While also ignoring all other evaluations to achieve that result

---

## Ternary Operator (Conditional Operator)

This is an operator you can use to simplify your code.

Look at the following example:

```c++
int max{};
constexpr int a{35}, b{120};

if (a > b)
{
    max = a;
} else
{
    max = b;
}
```

The previous `if` statement is a simple logical expression. Yet, it takes multiple
lines to write out, to verbose. Expression where two possible outcomes are possible, can be
written as such:

```c++
max = (a > b) ? a : b;
```

- It is a ternary operator because:
    - It has three operators
        1. The first is the greater than operator
        2. Followed by the question mark
        3. Having two things acting as the answer/result
            - if `a` is greater than `b`
                - We assign `a` to the `max` variable
            - Otherwise
                - We assign `b` to the `max` variable

---

## `std::unreachable` (C++23)

We will be discussing a facility that was introduced in C++23, `std::unreachable`.
This is just a suggestion or a helper line tha you will put in your code to
tell the compiler a part of your cod is going to be unreachable. So, the compiler
will do optimizations in turn.

- `std::unreachable()` is a function introduced as part of `<utility>`
    - Marks code paths that should never be reached
- Used to inform the compiler
    - Certain parts of code are logically unreachable
    - Which can lead to optimization opportunities

Example below:

```c++
void handleColor(const int& color)
{
    switch (color)
    {
        case Red:
            fmt::println("Handling Red");
            break;
        case Green:
            fmt::println("Handling Green");
            break;
        case Blue:
            fmt::println("Handling Blue");
            break;
        default:
            // We expect that all cases are covered
            // So reaching here should never happen.
            std::unreachable();
    }
}

int main()
{   
    handleColor(Red);
    handleColor(Green);
    handleColor(Blue);
}
```

- In the case above
    - We have a `switch` statement
        - Testing for certain cases
    - If we receive a case that does not exist
        - Then we do not expect to run the `default`
        - Thus mark it as **_unreachable_**
            - Helping the compiler out in processing it
            - Saving on that compilation
- _**We would mainly use `std::unreachable` in the optimization phase**_
    - e.i., using the `default`, for example, is not helping
    - Then we would add the `std::unreachable()`

---

## Loops

We will start learning about loops.

_Side Note:_ I may just not add many notes to this section other than
showing an example or minor information that may be helpful.

- Loop components
    - Initializer
    - End Condition
    - Incrementation
    - Body

### `for` loops

Example:

```c++
// for loop: the good way
for (unsigned int i{0}; i < 100; ++i)
{
    // Whatever we want the loop to run
    fmt::println("{} : I love C++", i);
}

// "i" is only available within the scope of the for loop
//fmt::println("{}", i);
```

- Breakdown:
    - Initializer
        - `unsigned int i{0}`
    - End Condition
        - `i < 100`
    - Incrementation
        - `++i`
    - Body
        - `fmt::println("{} : I love C++", i);`

When using a positive integer to count things, in C++, it is
best to do such process with `size_t` variables.
Which is just another name for `unsigned integer`, but that is
just a surface level explanation.

```c++
// Previous code with size_t
for (size_t i{0}; i < 100; ++i)
{
    // Whatever we want the loop to run
    fmt::println("{} : I love C++", i);
}
```

**We also want to remember to never hard code our count size.**
Instead, we should get comfortable using counter variables.
As shown below:

```c++
constexpr size_t COUNT{100};

for (size_t i{0}; i < COUNT; ++i)
{
    // Whatever we want the loop to run
    fmt::println("{} : I love C++", i);
}
```

We can also use range-based `for` loops in C++.
Showcased below:

```c++
// Ranged based for loop
std::vector<int> values {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

for (int value : values) {
    // Value holds a copy of the current iteration in the whole collection
    fmt::println("value: {}", value);
}
```

- Work best with collections/containers

We can also use the `auto` type deduction to make our
code more workable.

```c++
for (auto value : {1, 2, 3, 4, 5, 6, 7}) {
    fmt::println("value : {}", value);
}
```

We can also do multiple declarations within the `for` loop.

Example below:

```c++
#include <iostream>

int main(int argc, int** argv) {
    for (size_t i{0}, x{5}, y{22}; y > 15; ++i, x+=5, y-=1) {
        std::cout << "i: " << i << "\nx: " << x << "\ny: " << y << "\n\n";
    }
}
```

To accomplish this, we simply add commas after each variable declaration.
When utilizing this feature, one has to be comfortable reading the verbose
loop. Knowing where each section of the `for` loop is starting and ending.

Looking at the three parts

1. Initialized Variables
    - We have three variables
        - `i`
        - `x`
        - `y`
2. Conditional
    - We have one conditional check for `y`
    - We can use any of the declare variables
        - But we have to ensure the incrementation is working
        - i.e., Make sure the loop ends properly and does our desired task
3. Incrementation
    - We are incrementing all three variables at **different incrementation**
    - Each time we:
        - Add one to `i`
        - Add 5 to `x`
        - Subtract 1 from `y`

---

### `while` Loops

Syntax:

```c++
size_t i{0};

while (i < COUNT) // Test Condition
{
    fmt::println("{} : I love C++", i);
    ++i; // Incrementation
}
```

- `COUNT` is being utilized from previous `for` loop examples
- `size_t i` iterates through the `while` loop
    - We do not make it `const`
        - Since we will be incrementing the value
    - We also make sure to declare and init prior to use
    - `++i` is incrementing the value
- The component are the same as a `for` loop
    - Just placed at other locations

---

### `do-while` Loops

While not as heavily utilized by many, could be useful
to someone, depending on the use-case.
Example below:

```c++
size_t i {0};

do {
    fmt::println("{} : I love C++", i);
    ++i;
} while (i < COUNT);
```

- `COUNT` is being utilized from `for` loop examples
- `size_t i` iterates through the `do-while` loop
    - We also make sure to declare and init prior to use
    - `++i` is incrementing the value
- The component are the same as a `while` loop
    - End condition is placed at the end
- Main difference is:
    - The body will run prior to testing the conditional

---

### Infinity Loops

If we are not careful, we can set up a loop which is never going
to stop. It will continuously run, trying to do things and exhausting the
resources of the program.

We will get an infinite loop if:

- Our end condition is set up to never stop

Example Infinite `for` below:

```c++
for (size_t i{}; true; ++i)
{
    fmt::println("{}: I love C++", i);
}
```

Example Infinite `while` below:

```c++
size_t i{};

while (true)
{
    fmt::println("{}: I love C++", i);
    ++i;
}
```

Example Inifinite `do-while` below:

```c++
size_t i{};

do
{
    fmt::println("{}: I love C++", i);
    ++i;
} while (true);
```

- In all the examples above
    - The loop condition is set to `true`
    - Thus, regardless of our operations, nothing will change a hard-coded `true`
    - Resulting in an infinite loop
- That is why we need something to help prevent such behavior

---

### Decrementing Loops

Similar to a regular loop, it just counts down rather than up.

```c++
constexpr size_t COUNT{100};
for (size_t i{COUNT}; i > 0; --i)
{
    fmt::println("{}: I love C++", i);
}
```

---

## `break` & `continue`

These are keywords that are utilized to alter or modify the way loops behave.

We utilize `continue` to make the loop ignore the current iteration.

- We skip any instruction that would normally occur in previous iterations
- This does not stop the loop

Example below:

```c++
constexpr size_t COUNT{20};

for (size_t i{0}; i < COUNT; ++i)
{
    if (i == 5) continue;
    fmt::println("i: {}", i);
}
```

When run, the program produces the following output:

```shell
i: 0
i: 1
i: 2
i: 3
i: 4
i: 6
i: 7
i: 8
i: 9
i: 10
i: 11
i: 12
i: 13
i: 14
i: 15
i: 16
i: 17
i: 18
i: 19
```

- We can note that `i: 5` is missing
- That is due to the conditional `i == 5`
    - Where we `continue`
    - So we skip the print statement

Now, `break` behaves differently. Rather than skipping the iteration,
`break` stops looping thereafter being run. In other words, when the
program encounters the `break` keyword in a loop, it will stop looping.
So, the remaining iterations will not be reached.

Modifying the example above, we get:

```c++
constexpr size_t COUNT{20};

for (size_t i{0}; i < COUNT; ++i)
{
    if (i == 5) continue;
    if (i == 11) break;
    fmt::println("i: {}", i);
}
```

- The new line adds:
    - The conditional check for `i` being equal to `11`
        - If the condition is met:
            - We stop the looping process

So the new output is:

```shell
Continue & Break Example:
i: 0
i: 1
i: 2
i: 3
i: 4
i: 6
i: 7
i: 8
i: 9
i: 10
```

---

## Comma Operator

We will be talking about the comma operator. This operator allows us
to group multiple expressions and treat them as if they were one expression.

Example below:

```c++
#include <print>

int main(int argc, int** argv) {
    int increment{5}, number1{10}, number2{20}, number3{25};
    int result = (number1 *= ++increment, number2 - (++increment), number3 += ++increment);
    std::println("number1: {}\nnumber2: {}\nnumber3: {}", number1, number2, number3);
    std::println("result: {}", result);
}
```

This is why we are able to declare multiple variables with one data type
declaration. Looking at the line for `int result`:

- We are
    - Compound multiplying `number1` with `increment`
        - Then incrementing `increment`
    - Subtracting `number2` with `increment`
        - Then incrementing `increment`
    - Compound Adding `number3` with `increment`
        - Then incrementing `increment`