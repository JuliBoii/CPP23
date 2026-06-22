# Characters & Strings

In this module, we will explore strings and characters in C++. Unknown author of quote states: "String handling and
manipulation is one of the classic problems in Computer Science".

String manipulation can be a little complicated, but if understood properly many problems would become solvable in
Computer Science, not just C++. Since this knowledge propagates to other programming languages. So, once learned
one can use the knowledge for the rest of their life.

We will start with handling characters. Move on to handling C-strings. Which are arrays in memory that are managed by a
pointer. Then handling `std::string`s. Afterward, we look at the escape sequence and raw string literals. With the last
major topic covering the handling of `std::string_views`. A more recent addition. Let us learn!

---

<!-- TOC -->

* [Characters & Strings](#characters--strings)
    * [Handling Characters](#handling-characters)
        * [`std::isalnum()`](#stdisalnum)
        * [`std::isalpha()`](#stdisalpha)
        * [`std::isblank()`](#stdisblank)
        * [`std::isupper()` and `std::islower()`](#stdisupper-and-stdislower)
        * [`std::isalnum()`](#stdisalnum-1)

<!-- TOC -->

---

## Handling Characters

For this section we will be using a new built-in library for C++. Which provides facilities to use. The library is:
`<cctype>`

### `std::isalpha()`

This facility is used to check if a character is alphabetic. Look at the example below:

```c++
        fmt::println("C is alphabetic: {}", (std::isalpha('C') ? "True" : "False"));
        fmt::println("^ is alphabetic: {}", (std::isalpha('^') ? "True" : "False"));
        fmt::println("7 is alphabetic: {}\n", (std::isalpha('7') ? "True" : "False"));

        fmt::println("Used in an if statement");
        if (std::isalpha('a')) {
            fmt::println("Is alphabetic\n");
        } else {
            fmt::println("Is not alphabetic\n");
        }
```

### `std::isalnum()`

### `std::isblank()`

### `std::isupper()` and `std::islower()`

### `std::isalnum()`