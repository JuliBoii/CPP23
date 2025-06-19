import utilities;
// One line comment

/*
 * This is a block comment that englobes
 * multiple
 * lines
 * of
 * text
 */

int main() {
    // This is going to print Number1, Number2, and Number3
    print_msg("Number1");
    print_msg("Number2");
    print_msg("Number3");
    print_number(5);

    int num1{5};
    int num2{6};
    int result = add_numbers(num1, num2);

    print_number(result);

    return 0;
}