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
> `unsigned char` nor equal to `EOF`. To use the functions safely with plain `char`s (or `signed char`s), the argument
> should be converted to `unsigned char`.

Let us define some terms used here:

C Locale (POSIX locale): This is the default, bare-bones system locale in programming. A **_locale_** is an embodiment
of a set of cultural conventions, including information about the native character set, how dates are formatted, which
symbol to use for currency, and so on. Each set of related attributes is called a _**facet**_, which are grouped into
categories. Can be used by programs to be more portable internationally.

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

`std::isalnum` returns non-zero value if character is alphanumeric character, zero otherwise. That is why we use a
ternary operator to output a string of `"True"` or `"False"` to better understand the result.

`std::isalnum` checks if the given character is an alphanumeric character as classified by the current C locale. In the
default locale, the following characters are alphanumeric:

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

`std::isalpha()` returns non-zero value if the character is an alphabetic character, zero otherwise. That is why we use
a ternary operator to output a string of `"True"` or `"False"` to better understand the result.

`std::isalpha()` checks if the given character is an alphabetic character as classified by the currently installed C
locale. In the default locale, the following characters are alphabetic:

- uppercase letters
    - `ABCDEFGHIJKLMNOPQRSTUVWXYZ`
- lowercase letters
    - `abcdefghijklmnopqrstuvwxyz`

### `std::isblank()`

This facility is used to check if a character is a blank character. Look at the example below:

```c++
char message[]{"This is a string of characters.\nHow is your day?\n"};
fmt::println("{}", message);

size_t blank_count{0};

for (size_t index{0}; index < std::size(message); ++index) {
    if (std::isblank(message[index])) {
        fmt::println("Blank character at index: {}", index);
        blank_count++;
    }
}
fmt::println("\nTotal number of blank characters: {}\n", blank_count);
```

Outputs:

```terminaloutput
This is a string of characters.
How is your day?

Blank character at index: 4
Blank character at index: 7
Blank character at index: 9
Blank character at index: 16
Blank character at index: 19
Blank character at index: 35
Blank character at index: 38
Blank character at index: 43

Total number of blank characters: 8
```

`std::isblank()` returns a non-zero value if the character is a blank character, zero otherwise.

`std::isblank()` checks if the given character is a blank character as classified by the currently installed C locale.
Blank characters are whitespace characters used to separate words within a sentence. In the default C locale,
only space (`0x20`) and horizontal tab (`0x09`) are classified as blank characters.

### `std::isupper()` and `std::toupper()`

These facilities are used to check if a character is uppercase and to convert a character to uppercase. Looking at
implementation in `character_handling.ixx` function `check_uppercase()`. We get the following output:

```terminaloutput
Original message:
This is a string of characters.
How is your day?

Uppercase character at index: 0
Uppercase character at index: 32

Total number of upper case characters: 2

Modified message (using std::toupper):
THIS IS A STRING OF CHARACTERS.
HOW IS YOUR DAY?
```

`std::isupper()` checks if the given character is an uppercase character as classified by the currently installed C
locale. In the default C locale, `std::isupper()` returns a non-zero value only for the following uppercase letters:
`ABCDEFGHIJKLMNOPQRSTUVWXYZ`. Something to note: If `std::isupper()` returns a non-zero value, it is guaranteed that the
following facilities will return zero for the same character in the same C locale:

- `std::iscntrl()`
- `std::isdigit()`
- `std::ispunct()`
- `std::isspace()`

`std::toupper()` converts the given character to uppercase according to the character conversion rules defined by the
currently installed C locale. In the default C locale, the following lowercase letters are replaced with respective
uppercase letters:

- `abcdefghijklmnopqrstuvwxyz ` $\rightarrow$ `ABCDEFGHIJKLMNOPQRSTUVWXYZ`

Thus, this facility returns a converted character. If the character does not have a defined uppercase version in the
locale, the behavior is undefined.

### `std::islower()` and `std::tolower()`

These facilities are used to check if a character is lowercase and to convert a character to lowercase. Looking at
implementation in `character_handling.ixx` function `check_lowercase()` for code. We get the following output:

```terminaloutput
Original message:
This MESSAGE is nOT fully LowERCASE.
THus, WE Must Fix IT!

Lower case character at index: 1
Lower case character at index: 2
Lower case character at index: 3
Lower case character at index: 13
Lower case character at index: 14
Lower case character at index: 16
Lower case character at index: 20
Lower case character at index: 21
Lower case character at index: 22
Lower case character at index: 23
Lower case character at index: 24
Lower case character at index: 27
Lower case character at index: 28
Lower case character at index: 39
Lower case character at index: 40
Lower case character at index: 47
Lower case character at index: 48
Lower case character at index: 49
Lower case character at index: 52
Lower case character at index: 53

Total number of lowercase characters: 20

Modified message (using std::tolower):
this message is not fully lowercase.
thus, we must fix it!
```

`std::islower()` checks if the given character is a lowercase character as classified by the currently installed C
locale. In the default C locale, `std::islower()` returns a non-zero value only for the following lowercase letters:
`abcdefghijklmnopqrstuvwxyz`. Something to note: If `std::islower()` returns a non-zero value, it is guaranteed that the
following facilities will return zero for the same character in the same C locale:

- `std::iscntrl()`
- `std::isdigit()`
- `std::ispunct()`
- `std::isspace()`

`std::tolower()` converts the given character to lowercase according to the character conversion rules defined by the
currently installed C locale. In the default C locale, the following uppercase letters are replaced with respective
lowercase letters:

- `ABCDEFGHIJKLMNOPQRSTUVWXYZ` $\rightarrow$ `abcdefghijklmnopqrstuvwxyz`

Thus, this facility returns a converted character.

### `std::isdigit()` and `std::isxdigit()`

These facilities check if a given character are decimal or hexadecimal digits, respectively. Looking at the
implementation in file `character_handling.ixx` function `check_if_decimal_and_hexadecimal()` for code. Which outputs:

```terminaloutput
Original message:
abcdefghijklmnopqrstuvwxyz0123456789

Decimal character at index: 26
Decimal character at index: 27
Decimal character at index: 28
Decimal character at index: 29
Decimal character at index: 30
Decimal character at index: 31
Decimal character at index: 32
Decimal character at index: 33
Decimal character at index: 34
Decimal character at index: 35

Total number of decimal characters: 10

Hexadecimal character at index: 0
Hexadecimal character at index: 1
Hexadecimal character at index: 2
Hexadecimal character at index: 3
Hexadecimal character at index: 4
Hexadecimal character at index: 5
Hexadecimal character at index: 26
Hexadecimal character at index: 27
Hexadecimal character at index: 28
Hexadecimal character at index: 29
Hexadecimal character at index: 30
Hexadecimal character at index: 31
Hexadecimal character at index: 32
Hexadecimal character at index: 33
Hexadecimal character at index: 34
Hexadecimal character at index: 35

Total hexadecimal characters: 16
```

`std::isdigit()` checks if the given character is a decimal numeric character: `0123456789`. Returns a non-zero value if
the character is a decimal numeric character, zero otherwise.

While `std::isxdigit()` checks if the given character is a hexadecimal numeric character: `0123456789ABCDEFabcdef`.
Returns a non-zero value if the character is a hexadecimal numeric character, zero otherwise.

**_Note:_** Both `std::isdigit()` and `std::isxdigit()` are the only standard narrow character classification functions
that are **not** affected by the currently installed C locale. Although, some implementations may classify additional
single-byte characters as digits.

### `std::isspace()`

Checks if the given character is a whitespace character. Let us look at the example below:

```c++
char message[]{"Are any of these characters a whitespace \fcharacter\t.\n\v\r"};
fmt::println("Original message: \n{}", message);

size_t whitespace_count{0};
for (size_t index{0}; index < std::size(message); ++index) {
    if (std::isspace(message[index])) {
        fmt::println("Whitespace character at index: {}", index);
        whitespace_count++;
    }
}
fmt::println("\nTotal whitespace characters: {}\n", whitespace_count);
```

Outputs:

```terminaloutput
Original message:
Are any of these characters a whitespace ♀character     .
♂
Whitespace character at index: 3
Whitespace character at index: 7
Whitespace character at index: 10
Whitespace character at index: 16
Whitespace character at index: 27
Whitespace character at index: 29
Whitespace character at index: 40
Whitespace character at index: 41
Whitespace character at index: 51
Whitespace character at index: 53
Whitespace character at index: 54
Whitespace character at index: 55

Total whitespace characters: 12
```

`std::isspace()` checks if the given character is a whitespace character as classified by the currently installed C
locale. In the default locale, the whitespace characters are the following:

- line feed (`0x0a` or `\n`)
- vertical tab (`0x0b` or `\v`)
- form feed (`0x0c` or `\f`)
- carriage return (`0x0d` or `\r`)
- horizontal tab (`0x09` or `\t`)
- space (`0x20` or ` `)

The facility returns a non-zero value if the character is a whitespace character, zero otherwise.

### `std::ispunct()`

Checks if the given character is a punctuation character. Let us look at the example below:

```c++
char message[]{
    "Hey,\nHow have you been? Are you still in California?"
    "\nI always loved going to Yosemite with you on the weekends."
    "\nLet's go again, if you are still there.\nHope to hear from you!\n"
};
fmt::println("Original message: \n{}", message);

size_t punctuation_count{0};

for (size_t index{0}; index < std::size(message); ++index) {
    if (std::ispunct(message[index])) {
        fmt::println("Punctuation character at index: {}", index);
        punctuation_count++;
    }
}
fmt::println("\nTotal punctuation characters: {}\n", punctuation_count);
```

Output:

```terminaloutput
Original message:
Hey,
How have you been? Are you still in California?
I always loved going to Yosemite with you on the weekends.
Let's go again, if you are still there.
Hope to hear from you!

Punctuation character at index: 3
Punctuation character at index: 22
Punctuation character at index: 51
Punctuation character at index: 110
Punctuation character at index: 115
Punctuation character at index: 126
Punctuation character at index: 150
Punctuation character at index: 173

Total punctuation characters: 8
```

`std::ispunct()` checks if the given character is a punctuation character as classified by the current C locale.
The default C locale classifies the following characters as punctuations: ``!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~``.
Returns a non-zero value if the character is a punctuation character, zero otherwise.

### `std::isprint()`

Checks if the given character is a printable character. Let us look at the example below:

```c++
bool my_isprint(char c) {
    return std::isprint(static_cast<unsigned char>(c));
}

int main() {
    char message[]{
        "!\"§ $%& /() =?* \'<> #|; ²³~ @`´ ©«» ¤¼× /() =?*<> #|; ²³~"
    };
    fmt::println("Total size of message: {}", std::size(message));

    size_t printable_character_count{0};
    for (size_t index{0}; index < std::size(message); ++index) {
        if (my_isprint(message[index])) {
            printable_character_count++;
        }
    }
    fmt::println("Total printable characters: {}\n", printable_character_count);
```

Output:

```terminaloutput
Total size of message: 70
Total printable characters: 45
```

For this example, we added character that would not be printable. But, as with all other facilities mentioned, if
the `char` is not representable as `unsigned char` nor equal to `EOF`. `std::isprint()` would have undefined behavior.
To use this facility safely, we convert the `char` to `unsigned char`. Thus, preventing the program from crashing.
This is done in our defined function `my_isprint()`.

So, `std::isprint()` checks if a character is a printable character as classified by the currently installed C locale.
In the default C locale, the following characters are printable:

- Digits (`0123456789`)
- Uppercase letters (`ABCDEFGHIJKLMNOPQRSTUVWXYZ`)
- Lowercase letters (`abcdefghijklmnopqrstuvwxyz`)
- Punctuation characters (``!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~``)
- Space (` `)

Returns a non-zero value if character can be printed, zero otherwise. Again, if the value passed to `std::isprint()`
cannot be represented as `unsigned char` or is not equal to `EOF`, it will have undefined behavior.

That is all for this subsection. But there are a few more facilities that were not discussed.

---

## Handling C-Strings

Now we will focus on facilities for handling/manipulating c-strings. As previously stated in an old module, a c-string
is a collection of characters in memory with the requirement that it must end with a null character (`\0`). It must
also be managed through a pointer. Essentially, it is a static array living in memory, ending with a null character,
which is manipulated through a pointer.

