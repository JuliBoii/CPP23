module;

export module utilities;

import pointer1;
import pointer2;

export void pointers_example() {
    pointer1::declaration_and_initialization();
    pointer1::assignment_and_access();
    pointer1::char_pointers();

    pointer2::modifiable_raw_data();
    pointer2::modifiable_data_and_modifiable_pointer();
}
