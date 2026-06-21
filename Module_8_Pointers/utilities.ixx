module;

export module utilities;

import pointer1;
import pointer2;
import pointer3;
import pointer4;
import dynamic_memory_allocation;
import smart_ptrs;

export void pointers_example() {
    /*pointer1::declaration_and_initialization();
    pointer1::assignment_and_access();
    pointer1::char_pointers();*/

    /*
    pointer2::modifiable_raw_data();
    pointer2::modifiable_data_and_modifiable_pointer();
    // pointer2::modifiable_pointer_to_const_data();
    pointer2::semi_const_pointer_to_modifiable_data();
    pointer2::const_pointer_to_const_data();
    pointer2::const_pointer_to_modifiable_data();
    */

    /*pointer3::pointer_and_array_relationship();
    pointer3::swapping_addresses_example();*/

    /*pointer4::pointer_arithmetic_navigation();
    pointer4::pointer_arithmetic_distance();
    pointer4::pointer_arithmetic_comparisons();*/

    /*dynamic_memory_allocation::pointers_gone_bad();
    dynamic_memory_allocation::dynamic_heap_memory();
    dynamic_memory_allocation::dynamic_memory_dangling_pointers();
    // dynamic_memory_allocation::new_fail_examples();
    dynamic_memory_allocation::using_delete_on_nullptr();
    // dynamic_memory_allocation::memory_leaks_examples();
    dynamic_memory_allocation::dynamic_arrays_examples();
    dynamic_memory_allocation::dynamic_vs_static_arrays();*/

    /*smart_ptrs::unique_ptr_example();
    smart_ptrs::unique_ptr_as_parameter_or_return_value();
    smart_ptrs::unique_ptrs_and_arrays();
    smart_ptrs::shared_ptr_example();
    smart_ptrs::shared_ptr_from_unique_ptr();
    smart_ptrs::shared_ptr_arrays();*/
    smart_ptrs::shared_pointer_as_parameter_and_return_type();
}
