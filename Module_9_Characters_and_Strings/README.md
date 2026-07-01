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

<!--@formatter:off-->

<!-- TOC -->
* [Characters & Strings](#characters--strings)
  * [Handling Characters](#handling-characters)
    * [`std::isalnum()`](#stdisalnum)
    * [`std::isalpha()`](#stdisalpha)
    * [`std::isblank()`](#stdisblank)
    * [`std::isupper()` and `std::toupper()`](#stdisupper-and-stdtoupper)
    * [`std::islower()` and `std::tolower()`](#stdislower-and-stdtolower)
    * [`std::isdigit()` and `std::isxdigit()`](#stdisdigit-and-stdisxdigit)
    * [`std::isspace()`](#stdisspace)
    * [`std::ispunct()`](#stdispunct)
    * [`std::isprint()`](#stdisprint)
  * [Handling C-Strings](#handling-c-strings)
    * [String Manipulation](#string-manipulation)
      * [`std::strcpy` and `std::strncpy`](#stdstrcpy-and-stdstrncpy)
      * [`std::strcat` and `std::strncat`](#stdstrcat-and-stdstrncat)
    * [String Examination](#string-examination)
      * [`std::strlen()`](#stdstrlen)
      * [`std::strcmp()` and `std::strncmp()`](#stdstrcmp-and-stdstrncmp)
      * [`std::strchr()` and `std::strrchr()`](#stdstrchr-and-stdstrrchr)
  * [`std::string` Handling](#stdstring-handling)
    * [Declaration & Initialization](#declaration--initialization)
      * [Difference between Double Quotes and std::string literal](#difference-between-double-quotes-and-stdstring-literal)
    * [Concatenation](#concatenation)
      * [`append()`](#append)
      * [`operator+=`](#operator)
        * [Comparison of `operator+=` and `append()`](#comparison-of-operator-and-append)
      * [`push_back()`](#push_back)
      * [Concatenating integers & float values](#concatenating-integers--float-values)
    * [Memory & Capacity Management](#memory--capacity-management)
      * [Accessing `std::string` Size/Length](#accessing-stdstring-sizelength)
      * [Checking if `std::string` is empty](#checking-if-stdstring-is-empty)
      * [Checking Maximum Size of `std::string`](#checking-maximum-size-of-stdstring)
      * [`capacity()` and `reserve()` Member functions](#capacity-and-reserve-member-functions)
      * [`shrink_to_fit()` Member Function](#shrink_to_fit-member-function)
      * [`clear()` member function](#clear-member-function)
    * [Accessing Elements in A `std::string`](#accessing-elements-in-a-stdstring)
      * [Subscript Operator `[]`](#subscript-operator-)
      * [`at()` Member Function](#at-member-function)
      * [`front()` and `back()`](#front-and-back)
      * [Iterators & Range-based Loops](#iterators--range-based-loops)
      * [Direct Pointer Access](#direct-pointer-access)
      * [`insert()` Member Function](#insert-member-function)
    * [Modifying `std::string`](#modifying-stdstring)
      * [`erase()`](#erase)
<!-- TOC -->

<!--@formatter:on-->

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
which is manipulated through a pointer. All the facilities we will be using can be found in the `<cstring>` library.
Let's go!!

### String Manipulation

#### `std::strcpy` and `std::strncpy`

Both these facilities copies the character string to the character array. `std::strncpy` simply takes an additional
parameter for a character copy limit. Let us look at an example:

```c++
const char *cstring{"Is this valid?"};
char *dest1{new char[16]};
char *dest2{new char[16]};

fmt::println("Before std::strcpy():");
fmt::println("dest1: {}\n", dest1);

fmt::println("Copying...");
std::strcpy(dest1, cstring);
fmt::println("After std::strcpy():");
fmt::println("dest1: {}\n", dest1);

fmt::println("Before std::strncpy():");
fmt::println("dest2: {}\n", dest1);

fmt::println("Copying...");
std::strncpy(dest2, cstring, 14);
fmt::println("After std::strcpy():");
fmt::println("dest2: {}\n", dest2);
```

Output:

```terminaloutput
Before std::strcpy():
dest1: 

Copying...
After std::strcpy():
dest1: Is this valid?

Before std::strncpy():
dest2: Is this valid?

Copying...
After std::strcpy():
dest2: Is this valid?
```

`std::strcpy` copies a pointer to a null-terminated byte string to a character array whose first element is pointed to
by a pointer.

The facility will have undefined behavior if the character array is not large enough. It can also have undefined
behavior if the strings overlap.

For `std::strcpy()`, we did not include a third parameter when copying our c-string to the character array. Unlike our
example using `std::strcpy()`. The third parameter for `std::strncpy` deals with the maximum number of characters to
copy. For this example, we will refer to this parameter as `count`.

If `count` is reached before the entire string (`cstring`) was copied, the resulting character array (`dest1` & `dest2`)
is not null-terminated. If, after copying the string (`cstring`), `count` has not been reached, additional null
characters are written to the character array (`dest1` & `dest2`), until the total of `count` characters have been
written. If the strings overlap, the behavior is undefined.

#### `std::strcat` and `std::strncat`

These facilities append strings. Lets us look at an example:

```c++
char dest[15] = "Hello";
char dest2[15] = "My";
char src[15] = "World";

fmt::println("Before std::strcat():");
fmt::println("dest: {}\n", dest);

fmt::println("Concatenating...");
std::strcat(dest, src);
fmt::println("After std::strcat():");
fmt::println("dest: {}\n", dest);

fmt::println("Before std::strncat():");
fmt::println("dest2: {}\n", dest2);

fmt::println("Concatenating...");
std::strncat(dest2, src, 14);
fmt::println("After std::strcat():");
fmt::println("dest2: {}\n", dest2);
```

Output:

```terminaloutput
Before std::strcat():
dest: Hello

Concatenating...
After std::strcat():
dest: HelloWorld

Before std::strncat():
dest2: My

Concatenating...
After std::strcat():
dest2: MyWorld
```

`std::strcat()` appends a copy of the character string, pointed to by `src`, to the end of the character string, pointed
to by `dest`. With the beginning of `src` (`scr[0]`) replacing the null terminator (`\0`) at the end of `dest`.
Resulting in a null-terminated byte string.

This facility has undefined behavior if the destination byte string (return value) is not large enough or the contents
of both `src` and `dest` along with the null terminator. It also has undefined behavior if the strings overlap.

`std::strncat()` is similar to `std::strcat()`, except it takes a third parameter. This third parameter is the maximum
number of characters to copy. So, the destination byte string (return value) must have enough space for the contents of
both `dest2` and `src` along with the null terminator. With `src` being limited in length as specified by the third
parameter.

**_Note:_** Both `std::strcat()` and `std::strncat()` have to find the end of the destination byte-string every time
either is used. It is **inefficient** to concatenate many strings into one using either facility.

### String Examination

#### `std::strlen()`

Returns the length of the given byte-string. Meaning the number of characters in a character array up til reaching the
null terminator.

This facility has undefined behavior if there is no null terminator in the byte-string. Let us look at an example:

```c++
constexpr char message1[]{"The sk\0y is blue.\0"};
constexpr char *message2{"The sky is bl\0ue.\0"};

fmt::println("message1 : {}", message1);
fmt::println("message2 : {}", message2);

fmt::println("strlen(message1) : {}", std::strlen(message1));
fmt::println("strlen(message2) : {}", std::strlen(message2));
```

Output:

```terminaloutput
message1 : The sk
message2 : The sky is bl
strlen(message1) : 6
strlen(message2) : 13
```

This facility does behave differently compared to other facilities that return a size/length. For example, `sizeof()`
would not return the same value as `std::strlen()`. Appending the following to the code above:

```c++
...
fmt::println("sizeof(message1) : {}", sizeof(message1));
..
fmt::println("sizeof(message2) : {}", sizeof(message2));
...
```

Output:

```terminaloutput
message1 : The sk
message2 : The sky is bl
strlen(message1) : 6
sizeof(message1) : 19
strlen(message2) : 13
sizeof(message2) : 8
```

This result difference is due how each facility handles the null-terminator. `std::strlen()` returns the length/size
up-until reaching a null terminator. On the other hand, `sizeof()` is a compile-time operator that measures total
allocated memory. So, `sizeof()` is returning the total storage allocated for the byte-string. Thus, taking into account
the null-terminator.

#### `std::strcmp()` and `std::strncmp()`

These facilities compare two c-strings lexicographically. Let us look at an example:

```c++
const char *string_data1{"Banana"};
const char *string_data2{"Danana"};

char string_data3[]{"Banana"};
char string_data4[]{"Danana"};

fmt::println("Using std::strcmp()");
fmt::println("std::strcmp({}, {}) = {}", string_data1, string_data2, std::strcmp(string_data1, string_data2));
fmt::println("std::strcmp({}, {}) = {}\n", string_data3, string_data4, std::strcmp(string_data3, string_data4));

fmt::println("Using std::strncmp()");
fmt::println("std::strncmp({}, {}, 4) = {}", string_data1, string_data2,
             std::strncmp(string_data1, string_data2, 4));
fmt::println("std::strncmp({}, {}, 4) = {}\n", string_data3, string_data4,
             std::strncmp(string_data3, string_data4, 4));
```

Output:

```terminaloutput
Using std::strcmp()
std::strcmp(Banana, Danana) = -2
std::strcmp(Banana, Danana) = -2

Using std::strncmp()
std::strncmp(Banana, Danana, 4) = -2
std::strncmp(Banana, Danana, 4) = -2
```

`std::strcmp()` compares two null-terminated byte strings lexicographically. In the example above we test this using
two different cstring formats. We use a character pointer first followed by a test using a character array.

Facility returns an integer value. This integer value tells you 3 things:

- If negative (`-`)
    - The left hand side (`string_data1`) appears before the right hand side (`string_data2`) in lexicographical order
- If zero (`0`)
    - The left hand side (`string_data1`) and right hand side (`string_data2`) compare equal
- If positive (`+`)
    - The left hand side (`string_data1`) appears after the right hand side (`string_data2`) in lexicographical order

`std::strcmp()` has undefined behavior if the left hand side or right hand side are not pointers to null-terminated
byte-strings.

`std::strncmp()` takes a third parameter, which dictates the number of characters to compare. Referring to this size as
`count`. So, the facility will compare, at most, `count` characters of two null-terminated byte-strings. With the
comparison also being done lexicographically. Any character that follows the null-character are not compared.
This facility follows the same return behavior as `std::strcmp()`.

`std::strncmp()` has undefined behavior when either the left hand or right hand side go past the end of respective
array. Or either is a null pointer.

#### `std::strchr()` and `std::strrchr()`

`std::strchr()` finds the first occurrence of a specified `char`. While `std::strrchr()` finds the last occurrence of
the
specified `char`. Let us look at an example:

```c++
constexpr char string_data1[]{"Havana Banana in Transylvania next to Pennsylvania"};
const char *string_data2{"Havana Banana in Transylvania next to Pennsylvania"};
constexpr char target = 'i';

fmt::println("Using std::strchr()");
const char *result = string_data1;
result = std::strchr(string_data1, target);
if (result) {
    fmt::println("{}\n", result);
}

result = std::strchr(string_data2, target);
if (result) {
    fmt::println("{}\n", result);
}

fmt::println("Using std::strrchr()");
result = std::strrchr(string_data1, target);
if (result) {
    fmt::println("{}\n", result);
}

result = std::strrchr(string_data2, target);
if (result) {
    fmt::println("{}\n", result);
}
```

Output:

```terminaloutput
Using std::strchr()
in Transylvania next to Pennsylvania

in Transylvania next to Pennsylvania

Using std::strrchr()
ia

ia
```

`std::strchr()` finds the first occurrence of the character in the byte-string. In the example above we test this using
two different cstring formats. We use a character array first followed by a test using a character pointer. Adding in,
the null character (`\0`) is also included in the search. One can search for it by inputting the null character to the
facility.

`std::strchr()` returns a `char` pointer of the found character in the source cstring, or a null pointer if the
character is not found.

`std::strrchr()`, on the other hand, finds the last occurrence of the character in the byte-string. Likewise, the null
character can also be found.

`std::strncmp()` returns a `char` pointer of the found character in the source cstring, or a null pointer if the
character is not found.

There are more facilities available in the `<cstring>` library, but these are the ones we wanted to cover.

---

## `std::string` Handling

Despite learning about cstring, we need to remember that cstrings are not the current best practice for Modern C++. For
Modern C++, one needs to be utilizing `std::string`. This is a library built into C++ to make it easier to work with
string data. First let us learn how to declare and initialize a `std::string`.

### Declaration & Initialization

Just like other data types, there are various ways to initialize a `std::string` declaration. Let us look at an example:

```c++
std::string full_name;
std::string planet{"Earth. Where the sky is blue"};
std::string preferred_planet{planet};
std::string message{"Hello there", 5};
std::string weird_message(4, 'e');
std::string greeting{"Hello World"};
std::string saying_hello{greeting, 6, 5};
```

- The first line is just a declaration.
    - We are defining
        - The data type: `std::string`
        - Variable name: `full_name`
    - Not initializing the variable
        - Thus, holding garbage data
- The next line uses braced initialization for `planet`
    - In curly brackets
        - We initialize the data we want to store in our `std::string`
        - **Note:**
            - `""` (double quotes) in C++ is interpreted as a traditional c-string
            - of type `const char[]`
- `preferred_planet` is initialized by another `std::string`
    - Passing the `planet` variable in the braced initialization
    - Thus, using another existing variable (of the same type) to initialize
- `message` is initialized using a cstring, but only keeping a specified length
    - In this case
        - Passed the cstring: `"Hello there"`
        - Specify the length of characters in the given string we want to store: `5`
- `weird_message` is an example of initializing with repeating a `char`
    - We pass the size of the resulting string: `4`
    - Followed by the `char` to initialize the string with
- `greeting` is initialized with a c-string literal, as previously seen
- `say_hello` is initialized with a substring of another variable
    - We first pass a `std::string` variable
    - The starting position index: `6`
    - The length of resulting string: `5`

We can also reassign a `std::string` variable at runtime.

```c++
plantet = "Jupiter"s;
```

All together this results in the following output:

```terminaloutput
full_name: 
planet: Earth. Where the sky is blue
preferred planet: Earth. Where the sky is blue
message: Hello
weird_message: eeee
greeting: Hello World
saying_hello: World

planet: Jupiter is awesome!
```

#### Difference between Double Quotes and std::string literal

To continue from my previous note, there is a distinct difference from a simple double quotes ("") and a string literal.
As previously mentioned, double quotes is interpreted as a c-style string literal. So its type is `const char[]`. On the
other hand, a string literal in C++ is of type `std::string`. Which begs the question, how do I define a string literal.
We utilize the suffix `s` which is defined in the `<string>` library. This suffix was introduced in the C++14 standard,
so any compiler using older standards will not recognize the suffix. Example below:

```c++
#include <string>

using namespace std::literals::string_literals;

int main() {
    auto str = "This is a string literal"s;
    
    return 0;
}
```

We need to add `using namespace std::literals::string_literals;` in order to use the `s` suffix. But the reason we
metion this is to prepare us for the next section discussing concatenation. Let us move on.

### Concatenation

The need to discuss the difference between a c-style string and `std::string` literal was for the purpose of
concatenation, among other reasons. But, `std::string` literals have differing methods & operations compared to c-style.
And in the context of concatenation, c-style strings can concatenate automatically with adjacent string literals, but
`std::string` literals cannot concatenate automatically with unadorned string literals. Let us look at an example:

```c++
#include <string>

using namespace std::literals::string_literals;

int main() {
    //auto cstyle_string = "Hello" + "World";
    
    auto standard_string{"Hello" + "World"};
    auto standard_string = "Hello"s + " World";
    
    return 0;
}
```

If we attempt to run the example above, the compiler would throw an error. Like the one below:

```terminaloutput
/tmp/Module_9_Characters_and_Strings/standard_string_handling.ixx:36:38: error: invalid operands to binary expression ('const char[6]' and 'const char[6]')
   36 |         auto cstyle_string = "Hello" + "World";
      |                              ~~~~~~~ ^ ~~~~~~~
1 error generated.
```

This happens because double quotes ("") evaluate to a `const char[]`. Thus adding it directly to another `const char[]`
results in the error. Using the `s` prefix, avoids this by treating the first term as a true `std::string` object that
knows how to append standard characters. Obviously, if you are working with an actual `std::string` object, this problem
would not arise. Yet, it is still useful to mention in case such a situation should ever arise.

Now let us look at another examples of concatenation for `std::string`s:

```c++
std::string str_var_1{"Hello"};
std::string str_var_2{"World"};
fmt::println("str_var_1: {}", str_var_1);
fmt::println("str_var_2: {}", str_var_2);
fmt::println("result: {}", str_var_1 + str_var_2);
fmt::println("result (With temp string added): {}", str_var_1 + " my " + str_var_2);
```

Outputs:

```terminaloutput
str_var_1: Hello
str_var_2: World
result: HelloWorld
result (With temp string added): Hello my World
```

This method of concatenation utilizes two `std::string` variables to make a single string. They could also be combined
with string literals (whether c-style or `std::string`). This leads us to the feature available for `std::string`
string literals. The `append()` function/method.

#### `append()`

First we need to understand this fact, `std::string` is a compound type. Meaning it is constructed from fundamental,
built-in types rather than being a primitive data type itself. Specifically, `std::string` is a high-level abstraction (
`class` template) build around an array of `char` elements. It manages its own memory dynamically, handles resizing
automatically, and provides a rich set of member functions for string manipulation.

Leading us to the topic of this subsection: `append()`. This member function adds characters to the end of an existing
`std::string`. Modifying the string in place and increasing the length. Let us look at the various methods of inputting
to the member function:

```c++
#include <string>
#include <fmt/format.h>

int main() {
    // 1. Append another std::string
    std::string str {"Hello"};
    str.append(" World");
    fmt::println("{}\n", str);
    
    // 2. Append a specific number of characters
    str = "Hey";
    str.append(3, '!');
    fmt::println("{}", str);
    
    // 3. Append a substring
    str = "is my name.";
    std::string name{"Angel "};
    name.append(str, 0, 11);
    fmt::println("{}", name);
    
    // 4. Append a C-style string up to a certain length
    str = "Los Angeles ";
    str.append("California", 2);
    fmt::println("{}", str);
    
    // 5. Append using iterators (A range of characters)
    str = "Letters: ";
    std::string letters{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    str.append(letters.begin(), letters.begin() + 5); // +5 is the length from beginning
    fmt::println("{}", str);
    
    return 0;
}
```

Output:

```terminaloutput
Hello World
Hey!!!
Angel is my name.
Los Angeles Ca
Letters: ABCDE


```

There are even more methods to concatenate a `std::string`, so let us look at the next method.

#### `operator+=`

This operator (`+=`) also performs concatenation in-place, appending the right hand side operand directly to the end of
the left hand side `std::string` object. So, unlike the `+` operator, `+=` does not create a completely new string
object. It directly modifies the existing string's memory to accommodate the new characters. Let us look at an example:

```c++
#include <string>
#include <fmt/format.h>

using namespace::std::literals::string_literals;

int main() {
    // Adding another string
    std::string str{"Hello"};
    str += " World!"s;
    fmt::println("{}", str);
    
    // C-style string literals
    str = "C++";
    str += "Programming";
    fmt::println("{}", str);
    
    // A single char
    str = "Dog";
    str += 's';
    fmt::println("{}\n", str);
    
    return 0;
}
```

Output:

```terminaloutput
Hello World!
C++Programming
Dogs

```

Why would we use this operator?

- Performance:
    - Because this method of concatenation modifies the string in-place
        - Rather than allocating memory for and constructing a brand-new string
    - It is fast and uses little memory
- Convenience:
    - Offers clean, readable syntax for building up larger strings from smaller components (over sequential lines)

##### Comparison of `operator+=` and `append()`

While both member functions do the exact same job: append data to the end of an existing string in-place without
creating a temporary copy. They differ in syntax and flexibility.

With the key differences being:

- Overload options (Topic will be covered more in-depth in later Modules)
    - The operator `+=` only accepts a single argument
    - `append()` offers multiple overloads
        - Allowing for options as mentioned in the `append()` subsection
- Chaining:
    - `append()` returns a reference to the modified string (`*this`)
        - Allowing for chaining multiple append operations in a single line

> While `str += "text";` is cleaner for simple additions, the `append()` function is much more powerful.

Let us focus on one last concatenation method.

#### `push_back()`

This member function also concatenates to a `std::string`. However, it appends a single character to the very end of an
existing string. It increases the total length of the string by exactly one. Let us look at an example:

```c++
#include <string>
#include <fmt/format.h>

int main() {
    std::string message {"Hello"};
    
    // Append a single character
    message.push_back('!');
    fmt::println("{}", message);
    
    return 0;
}
```

Outputs:

```terminaloutput
Hello!
```

Again, this member function only appends a **_single_** `char`. One cannot pass a string literal or a string object into
the `push_back()` method. For such situations, `operator+=` or `append()` are recommended. Here are some other details
about the member function:

- Time Complexity
    - It operates in amortized constant time `O(1)`
    - Most of the time, drops the character into already allocated memory
        - Will have to reallocate when capacity limit is reached
- Memory Allocation:
    - If `std::string`s current `size()` is equal to its `capacity()`
        - Calling `push_back()` will reallocate memory behind the scenes
        - As a result, existing iterators/pointers/references will be invalidated
- Exceptions:
    - If calling `push_back()` causes the string to reach its maximum limit (`max_size()`)
        - It throws a `std::length_error` exception
        - Offering a strong exception guarantee

#### Concatenating integers & float values

A quick coverage on converting `int` and `float` values into string literals. That way they can be concatenated to a
`std::string`. To do this we utilize the member function `std::to_string()`. Let us look at an example:

```c++
#include <string>
#include <fmt/format.h>

int main() {
    std::string message {"How many apples do I have? Let me check: "};
    int apples{41};
    float apple_price{1.99f};
    
    // Append a single character
    message.append(std::to_string(apples));
    message.append("\nI can sell them for ");
    message.append(std::to_string(apple_price));
    fmt::println("{}", message);
    
    return 0;
}
```

Output:

```terminaloutput
How many apples do I have? Let me check: 41
I can sell them for 1.990000
```

### Memory & Capacity Management

We will be looking at member functions that deal with memory and capacity of a `std::string`.

#### Accessing `std::string` Size/Length

We access the size or length of a `std::string`, we utilize respective member functions. We have access to
`size()` and `length()` member functions. Both are completely interchangeable aliasas and execute in `O(1)` constant
time. Example below:

```c++
#include <string>
#include <fmt/format.h>

int main() {
    std::string message{"What is the size/length of this string"};
    fmt::println("message.size(): ", message.size());
    fmt::println("message.length(): ", message.length());
    
    return 0;
}
```

Output:

```terminaloutput
message.size(): 38
message.length(): 38
```

Something to keep in mind:

- Byte Count:
    - These member functions return the length in terms of bytes(characters)
    - For standard strings, equates to number of characters
    - For Encoded Text (ex.UTF-8), does not reflect "visual" character count
- No Null Terminator:
    - The returned size/length excludes the implicit null terminator (`\0`)
- Return Type:
    - Both member functions return a type of `std::string::size_type`
    - Which is equivalent to an `unsigned int`

#### Checking if `std::string` is empty

`empty()` is a member function that checks if the string contains any characters. Returns `true` if the string length is
`0`, `fasle` otherwise. This member function is faster and more readable than writing a size check, such as:
`if (str.size() == 0)`. Function has a time complexity of `O(1)` constant time. Example below:

```c++
#include <string>
#include <fmt/format.h>

int main() {
    std::string message{"What is the size/length of this string"};
    std::string message1;
    std::string message2{};

    fmt::println("message.empty(): {}", message.empty());
    fmt::println("message1.emtpy(): {}", message1.empty());
    fmt::println("message2.empty(): {}\n", message2.empty());
    return 0;
}
```

Output:

```terminaloutput
message.empty(): false
message1.emtpy(): true
message2.empty(): true
```

#### Checking Maximum Size of `std::string`

`max_size()` is a member function that return the theoretical maximum number of characters a `std::string` can hold.
Gives the absolute ceiling limit dictated by system architecture or library implementation. Which is useful to check if
a massive input file or data stream will exceed the system's string limit. Prior to attempting to store it. This member
function also has a time complexity of `O(1)` constant time. Example below:

```c++
#include <string>
#include <fmt/format.h>

int main() {
    std::string message{};

    fmt::println("message.mex_size(): {}", message.max_size());
    return 0;
}
```

Output:

```terminaloutput
message.mex_size(): 9223372036854775806
```

#### `capacity()` and `reserve()` Member functions

`capacity()` is a member function that returns the size of the allocated storage space currently allocated for the
`std::string`. Meaning, it measures how many characters the string can hold without needing to reallocate for more
memory. The difference between `capacity()` and other functions, such as `size()` and `length()`, is that `capacity()`
is almost always equal to or greater than the current string size/length.

This member function has a time complexity of `O(1)` constant time.

On the other hand, `reserve()` is a member function that requests that the string capacity be expanded to at least `n`
characters. We pass `n` in such manner: `reserve(n)`. This informs the system of planned growth so it can allocate a
large block of memory upfront. Preventing multiple expensive reallocations when building a large string, character by
character.

This function has a time complexity of `O(1)` constant time, if the requested size is smaller than the
current capacity. Otherwise, the time complexity is `O(n)` if a reallocation triggers. Due to the need to make a copy of
the existing string to the new allocated memory location. Example below:

```c++
#include <string>
#include <fmt/format.h>

int main() {
    std::string message{};

    fmt::println("message.capacity(): {}", message.capacity());
    fmt::println("message.size(): {}\n", message.size());
    
    fmt::println("Reserving space for 100 characters");
    message.reserve(100);
    fmt::println("message.capacity(): {}", message.capacity());
    return 0;
}
```

Output:

```terminaloutput
message.capacity(): 15
message.size(): 0

message.capacity(): 100
```

#### `shrink_to_fit()` Member Function

`shrink_to_fit()` is a member function that is sort of the opposite of `reserve()`. This facility request that the
`std::string`s capacity be reduced to match its current size. In situations where you delete characters from a string,
C++ leaves the allocated memory as is. Which does save time from having to reallocate later when inputting more data.

`shrink_to_fit()` tells the system to stop holding onto the extra memory. This facility does not affect the actual text
inside the string. Let us look at an example:

```c++
#include <string>
#include <fmt/format.h>

int main() {
    std::string message{};

    fmt::println("Reserving space for 100 characters");
    message.reserve(100);
    fmt::println("message.capacity(): {}", message.capacity());
    fmt::println("message.size(): {}\n", message.size());
    
    fmt::println("Reducing the capacity of message");
    message.shrink_to_fit();
    fmt::println("message.capacity(): {}", message.capacity());
    fmt::println("message.size(): {}\n", message.size());
    
    return 0;
}
```

Output:

```terminaloutput
Reserving space for 100 characters
message.capacity(): 100
message.size(): 0

Reducing the capacity of message
message.capacity(): 15
message.size(): 0
```

We need to keep some information in mind, while using `shrink_to_fit()`:

- Non-binding Request:
    - C++ standards treat this function as a _request_
    - Thus, the compiler/library can **choose** to ignore the request
        - If matching the exact `size` is inefficient for the operating system
- Performance Cost
    - To shrink a strings capacity, the system usually allocates a brand-new and smaller memory slot.
    - Then copies over, if existing, the string
        - This facility should thus not be used in performance-critical loops
- Use case:
    - This facility should be used when we have a string that **briefly** grew massive
    - But now needs to be reduced to a smaller, more permanent size

#### `clear()` member function

The `clear()` member function wipes out the contents of a string. In the context of memory and capacity it has the
following behavior:

- For `size()` and `length()`
    - It resets `size()` and `length()` instantly to `0`
- For `capacity()`
    - It leaves `capacity()` completely unchanged

It does this because C++ assumes a cleared string will still be utilized later on in the program. Thus, keeping the
allocated capacity prevents the system from having to reallocate memory again. Example below:

```c++
#include <string>
#include <fmt/format.h>

int main() {
    std::string message{"What is the size/length of this string"};
    fmt::println("message: {}", message);
    fmt::println("message.capacity(): {}", message.capacity());
    fmt::println("message.size(): {}", message.size());
    fmt::println("message.length(): {}\n", message.length());
    
    fmt::println("Calling clear() on message");
    message.clear();
    fmt::println("message: {}", message);
    fmt::println("message.capacity(): {}", message.capacity());
    fmt::println("message.size(): {}", message.size());
    fmt::println("message.length(): {}\n", message.length());
    
    return 0;
}
```

Output:

```terminaloutput
message: What is the size/length of this string
message.capacity(): 38
message.size(): 38
message.length(): 38

Calling clear() on message
message: 
message.capacity(): 38
message.size(): 0
message.length(): 0
```

Let us move on to accessing elements in a string.

### Accessing Elements in A `std::string`

Let us now look at how to access elements in a `std::string`. There are four main ways to access elements.
We won't go too deep about their benefits or verbose details, but some of the methods have been discussed previously
when covering `std::array`, `std::vector` and raw arrays.

#### Subscript Operator `[]`

The most common method is the subscript operator `[]`. Which we saw when discussing containers and arrays. This is the
array-style indexing. While it is fast, it does not provide bounds checking. Plus, passing an index that is invalid
results in undefined behavior.

```c++
std::string message{"Can I Access This Character."};
fmt::println("{}", message);

const char element{message[4]};
message[4] = 'e';

fmt::println("message[4] previously was: {}", element);
fmt::println("message[4] is now: {}", message[4]);
fmt::println("{}\n", message);
```

Output:

```terminaloutput
Can I Access This Character.
message[4] previously was: I
message[4] is now: e
Can e Access This Character.
```

#### `at()` Member Function

This methods behavior is similar to the subscript operator, but has bounds-checking. Thus, if passed an invalid index,
the member function throws an `std::out_of_range` exception. Making it safer, but slightly slower.

```c++
std::string message{"Can I Access This Character."};
fmt::println("{}", message);

const char element1{message.at(4)};
message.at(4) = 'e';

fmt::println("message.at(4) previously was: {}", element1);
fmt::println("message.at(4) is now: {}", message.at(4));
fmt::println("{}\n", message);

fmt::println("Bound Checking with at()");
try {
    const char out_of_bound{message.at(89)};
} catch (const std::out_of_range &e) {
    std::cerr << "Out of bound!" << std::endl;
}
```

Output:

```terminaloutput
Can I Access This Character.
message.at(4) previously was: I
message.at(4) is now: e
Can e Access This Character.

Bound Checking with at()
Out of bound!
```

#### `front()` and `back()`

These member functions provide clean access to the boundaries of the sequence. Using these functions on an empty string
results in undefined behavior.

`front()`: Access the very first character. Equivalent to `message[0]`.

`back()`: Access the last character. Equivalent to `message[message.size() - 1]`.

Example below:

```c++
#include <string>
#include <fmt/format.h>

int main() {
    std::string message{"Can I Access This Character"};
    fmt::println("{}", message);
    fmt::println("First character of message: {}", message.front());
    fmt::println("Last character of message: {}", message.back());
    
    return 0;
}
```

Output:

```terminaloutput
message: Can I Access This Character
First character of message: C
Last character of message: r

```

#### Iterators & Range-based Loops

To process or traverse elements in a string sequentially, we can use iterators or a ranged-based loop. For iterators:

- `begin()` and `end()` Provide read/write access
- `cbegin()` and `cend()` Provide read-only (`const`) access

Example below:

```c++
#include <string>
#include <cctype>
#include <fmt/format.h>

int main() {
    std::string message{"HEY! THIS IS A STRING."};
    fmt::println("{}", message);

    for (auto &element: message) {
        if (std::tolower(element))
            element = std::tolower(element);
    }

    for (const auto &element: message) {
        fmt::print("{}", element);
    }
    fmt::print("\n\n");
    
    message = "HEY! THIS IS A STRING.";
    fmt::println("{}", message);

    for (auto it = message.begin(); it != message.end(); ++it) {
        if (std::tolower(*it))
            *it = std::tolower(*it);
    }

    for (auto it = message.begin(); it != message.end(); ++it) {
        fmt::print("{}", *it);
    }
    fmt::print("\n");
    
    return 0;
}
```

Output:

```terminaloutput
HEY! THIS IS A STRING.
hey! this is a string.

HEY! THIS IS A STRING.
hey! this is a string.
```

#### Direct Pointer Access

If we need compatibility with legacy C-style API's. We can get a direct pointer to the underlying contiguous charcater
array using the memeber function: `data()` or `c_str()`. Since the C++11 standard,

- `data()` returns a valid, null-terminating string pointer (`char*` or `const char*`)
- `c_str()` returns a read-only, null-terminating C-string array pointer (`const char*`)

Example below:

```c++
#include <string>
#include <fmt/format.h>

int main() {
    std::string message {"Hello Man!"};
    const char* c_ptr = message.c_str();
    char* raw_ptr = message.data();
    
    return 0;
}
```

#### `insert()` Member Function

This function can technically be categorized as adding content to a string. But, I wanted to put it in this section,
since the `insert()` is like a more useful version of `push_back()`. Since, it can insert characters or substrings at a
specific index/iterator positon. Rather than adding one character to the end. This function has various parameter
templates so let us look at an example showcasing them:

```c++
#include <string>
#include <fmt/format.h>

int main() {
    std::string str{"tard"};
    fmt::println("Before insert():");
    fmt::println("{}\n", str);
    
    // Insert a single character
    fmt::println("After insert() single character:");
    str.insert(0, "S"); // Using index
    fmt::println("{}", str);
    
    str.insert(str.begin(), 'C'); // Using Iterator
    fmt::println("{}", str);
    
    str.insert(str.begin() + 1, ' '); // Using Iterator
    fmt::println("{}\n", str);
    
    // Insert a single character multiple times
    fmt::println("After insert() repeating character:");
    str.insert(1, 2, '+'); // index 1, repeat 2 times
    fmt::println("{}\n", str);
    
    // Insert a string
    fmt::println("After insert() a string:");
    str.insert(6, "and"s);
    fmt::println("{}\n", str);
    
    // Insert a range from another string
    fmt::println("After insert() substring from a given string:");
    std::string substr{" is the latest standard pushed by the CPP Committee."s};
    str.insert(12, substr, 0, 23);
    fmt::println("{}\n", str);
    
    // Insert an iterator range
    std::string substr2{"26"s};
    fmt::println("After insert() iterator range:");
    str.insert(str.begin() + 3, substr2.begin(), substr2.end());
    fmt::println("{}", str);
}
```

Outputs:

```terminaloutput
Before insert():
tard

After insert() single character:
Stard
CStard
C Stard

After insert() repeating character:
C++ Stard

After insert() a string:
C++ Standard

After insert() substring from a given string:
C++ Standard is the latest standard

After insert() iterator range:
C++26 Standard is the latest standard
```

Let us move on to methods of modifying a string.

### Modifying `std::string`

Considering the previous sections, we have technically already learned how to modify a `std::string`, using several
built-in methods. Which can be classified as adding and altering the size of the string. Now, let us look at how we can
remove or replace elements of a string.

We already saw the member function `clear()`, so let us look at other memeber functions that remove content of a string.

#### `erase()`

This member function removes a specific number of characters starting at an index, or removes elements via an iterator.

---