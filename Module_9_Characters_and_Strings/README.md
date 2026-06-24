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
`<cctype>`. 

> All functions from `<cctype>`, have undefined behavior if the argument provided is neither representable as
> `unsigned char` nor equal to `EOF`. To use the functions safely with plain `char`s (or `signed char`s), the argument should
> be converted to `unsigned char`.

Let us define some terms used here:

C Locale (POSIX locale): This is the default, bare-bones system locale in programming. A **_locale_** is an embodiment of a set of cultural
conventions, including information about the native character set, how dates are formatted, which symbol to use for currency, and so on.
Each set of related attributes is called a _**facet**_, which are grouped into categories. Can be used by programs to be more portable internationally.

### `std::isalnum()`

This facility is used to check if a character is alphanumeric. Look at the example below:

```c++
fmt::println("Example using std::isalnum:");
fmt::println("C is alphanumeric: {}", (std::isalnum('C') ? "True" : "False"));
fmt::println("^ is alphanumeric: {}", (std::isalnum('^') ? "True" : "False"));
fmt::println("7 is alphanumeric: {}\n", (std::isalnum('7') ? "True" : "False"));

fmt::println("Used in an if statement");
if (std::isalnum('['))
{
    fmt::println("Is alphanumeric\n");
} else
{
    fmt::println("Is not alphanumeric\n");
}
```

Output:

```terminaloutput
C is alphanumeric: True
^ is alphanumeric: False
7 is alphanumeric: True

Used in an if statement
Is not alphanumeric
```

`std::isalnum` returns Non-zero value if character is alphanumeric character, zero otherwise. That is why we use a ternary operator to
output a string of `"True"` or `"False"` to better understand the result.

`std::isalnum` checks if the given character is an alphanumeric character as classified by the current C locale. In the default locale, the
following characters are alphanumeric:

- digits 
  - `0123456789`
- uppercase letters
  - `ABCDEFGHIJKLMNOPQRSTUVWXYZ`
- lowercase letters
  - `abcdefghijklmnopqrstuvwxyz`

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

Output: 

```terminaloutput
C is alphabetic: True
^ is alphabetic: False
7 is alphabetic: False

Used in an if statement
Is alphabetic
```

`std::isalpha()` returns Non-zero value if the character is an alphabetic character, zero otherwise. That is why we use a ternary operator to 
output a string of `"True"` or `"False"` to better understand the result.

`std::isalpha()` checks if the given character is an alphabetic character as classified by the currently installed C locale.
In the default locale, the following characters are alphabetic:

- uppercase letters
  - `ABCDEFGHIJKLMNOPQRSTUVWXYZ`
- lowercase letters
  - `abcdefghijklmnopqrstuvwxyz`

### `std::isblank()`

### `std::isupper()` and `std::islower()`

### `std::isalnum()`