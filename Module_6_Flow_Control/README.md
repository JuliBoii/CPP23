# Flow Control

---

## Topics

- If statement
- Switch
- Ternary Operator
- Loops:
  - `for()`
  - `while()`
  - `do{} while()`

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

---

## Switch Statements
