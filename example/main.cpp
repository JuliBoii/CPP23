#include "utilities.h"
#include <fmt/format.h>
// Uncomment the line below if using C++20 Modules
//import utilities;

int main(){
    int value1 {10};
    int value2 {20};

    fmt::print("The values are {} and {}\n", value1, value2);
    return 0;
}