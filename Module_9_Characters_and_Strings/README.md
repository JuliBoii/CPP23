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

