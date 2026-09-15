module;

#include <fmt/format.h>
#include <vector>

export module references;

void print_value(const int &value) {
    // value = 421;
    fmt::println("Inside print_value:");
    fmt::println("data: {}\n", value);
}


namespace references {
    export void declaration_example() {
        double original_data{12.12};
        double &reference_original{original_data};

        fmt::println("double data:{:.>15}", original_data);
        fmt::println("reference data:{:.>12}", reference_original);
        fmt::println("double data address (&original_data):{:.>26}", fmt::ptr(&original_data));
        fmt::println("reference data address (&reference_original):{:.>18}\n", fmt::ptr(&reference_original));

        original_data = 13.411343;

        fmt::println("Modified data through (original_data) variable:");
        fmt::println("double data:{:.>15}", original_data);
        fmt::println("reference data:{:.>12}", reference_original);
        fmt::println("double data address (&original_data):{:.>26}", fmt::ptr(&original_data));
        fmt::println("reference data address (&reference_original):{:.>18}\n", fmt::ptr(&reference_original));

        reference_original = 14.31411;

        fmt::println("Modified data through (reference_original) variable:");
        fmt::println("double data:{:.>15}", original_data);
        fmt::println("reference data:{:.>12}", reference_original);
        fmt::println("double data address (&original_data):{:.>26}", fmt::ptr(&original_data));
        fmt::println("reference data address (&reference_original):{:.>18}\n", fmt::ptr(&reference_original));
    }

    export void comparison_with_pointers() {
        fmt::println("Comparison with pointers");
        fmt::println("Comapring the declaration & initializaiton:");

        fmt::println("Variable Declaration & Initialization:\ndouble double_value = 412.132\n");
        double double_value{412.132};

        fmt::println("Reference Declaration & Initialization:\ndouble &reference_double = double_value\n");
        double &reference_double{double_value};

        fmt::println("Pointer Declaration & Initialization:\ndouble *pointer_double = &double_value\n");
        double *pointer_double{&double_value};

        fmt::println("Accessing data:");
        fmt::println("double_value (value) = {}", double_value);
        fmt::println("reference_double (value) = {}", reference_double);
        fmt::println("*pointer_double (value) = {}\n", *pointer_double);

        fmt::println("Writing through various types:");

        fmt::println("Using original variable");
        fmt::println("double_value = 13.31\n");
        double_value = 13.31;
        fmt::println("double_value (value) = {}", double_value);
        fmt::println("reference_double (value) = {}", reference_double);
        fmt::println("*pointer_double (value) = {}\n", *pointer_double);

        fmt::println("Using reference variable");
        fmt::println("reference_double = 51.31\n");
        double_value = 51.31;
        fmt::println("double_value (value) = {}", double_value);
        fmt::println("reference_double (value) = {}", reference_double);
        fmt::println("*pointer_double (value) = {}\n", *pointer_double);

        fmt::println("Using pointer variable");
        fmt::println("*pointer_double = 62.31\n");
        double_value = 62.31;
        fmt::println("double_value (value) = {}", double_value);
        fmt::println("reference_double (value) = {}", reference_double);
        fmt::println("*pointer_double (value) = {}\n", *pointer_double);

        fmt::println("Memory address for each variable type:");
        fmt::println("&double_value (address): {:>20}", fmt::ptr(&double_value));
        fmt::println("&reference_double (address): {:>16}", fmt::ptr(&reference_double));
        fmt::println("&pointer_double (address): {:>18}\n", fmt::ptr(&pointer_double));

        fmt::println("Reassigning Pointer & Reference:");
        fmt::println("Able to reassign pointer with new address");
        fmt::println("pointer_double = &new_double_value\n");
        double new_double_value{42.3};
        pointer_double = &new_double_value;

        fmt::println("double_value (value) = {}", double_value);
        fmt::println("reference_double (value) = {}", reference_double);
        fmt::println("*pointer_double (value) = {}\n", *pointer_double);

        fmt::println("Unable to reassign reference variable\n");
        // reference_double = &new_double_value;
    }

    export void const_reference_example() {
        fmt::println("Using const With References:");
        int original_int{42};
        const int &reference_original_int{original_int};

        fmt::println("original_int (value) = {:>13}", original_int);
        fmt::println("reference_original_int (value) = {:>3}\n", reference_original_int);

        fmt::println("Modified original_int:");
        fmt::println("original_int = 24");
        original_int = 24;
        fmt::println("original_int (value) = {:>13}", original_int);
        fmt::println("reference_original_int (value) = {:>3}\n", reference_original_int);

        fmt::println("Cannot Modify reference_original_int:\n");
        // reference_original_int = 400;

        fmt::println("Preventing program from making a copy of original_int (Passing to function)");
        print_value(original_int);

        fmt::println("Example of Binding to a temporary rvalue:");
        const int &temporary_int{42};
        print_value(temporary_int);

        fmt::println("Not possible with a non-const reference variable\n");
        // int &temporary_int_1{41};
    }

    export void range_based_for_loop_example() {
        fmt::println("Using Range-based For Loop:");
        std::vector<int> scores{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        fmt::println("Printing vector, prior to modifying indices:");
        for (const auto &score: scores) {
            fmt::print("{:<4} ", score);
        }
        fmt::println("\n");

        fmt::println("Modifying data using range-based for loop");
        for (auto &score: scores) {
            score = score * 10;
        }

        fmt::println("Printing vector, after modifying indices");
        for (const auto &score: scores) {
            fmt::print("{:<4} ", score);
        }
        fmt::println("\n");
    }
}
