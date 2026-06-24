module;

export module utilities;

import character_handling;

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
