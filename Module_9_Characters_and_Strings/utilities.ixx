module;

export module utilities;

import character_handling;
import cstring_handling;
import string_handling;

export void handle_char_demo() {
    character_handling::check_if_alphanumeric();
    character_handling::check_if_alphabetic();
    character_handling::check_if_blank();
    character_handling::check_uppercase();
    character_handling::check_lowercase();
    character_handling::check_if_decimal_and_hexadecimal();
    character_handling::check_if_whitespace_character();
    character_handling::check_if_punctuation();
    character_handling::check_if_printable_character();
}

export void handle_cstring_demo() {
    cstring_handling::using_strcpy_and_strncpy();
    cstring_handling::using_strcat_and_strncat();
    cstring_handling::using_strlen();
    cstring_handling::using_strcmp_and_strncmp();
    cstring_handling::using_strchr_and_strrcmp();
}

export void handle_standard_string_demo() {
    string_handling::standard_string_declaration_and_initialization();
    string_handling::standard_string_concatenation();
    string_handling::standard_string_memory_and_capacity();
    string_handling::standard_string_accessing_elements();
}
