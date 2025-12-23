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
