module;

#include <fmt/format.h>
#include <array>
#include <vector>
#include <algorithm>
#include <string>

export module utilities;

export void std_array_example() {
    fmt::println("Example of std::array:");

    // Declaration and init
    std::array<int, 5> arr{1, 2, 3, 4, 5};

    fmt::println("Using Square Brackets [] With std::array:");
    // Accessing elements using []
    for (size_t i = 0; i < arr.size(); ++i) {
        fmt::println("arr[{}] = {}", i, arr[i]);
    }
    fmt::println("");

    fmt::println("Using Range-based for Loops With std::array:");
    // Use range based for loop
    for (const auto &element: arr) {
        fmt::println("{}", element);
    }
    fmt::println("");

    fmt::println("Using .at() With std::array:");
    // Accessing elements using at()
    for (size_t i = 0; i < arr.size(); ++i) {
        fmt::println("arr.at({}) = {}", i, arr.at(i));
    }
    fmt::println("");

    fmt::println("Modifying Elements In Our Array:");
    //Modifying elements in the array
    arr[0] = 10;
    arr.at(1) = 20;
    fmt::println("arr[0] = 10");
    fmt::println("arr.at(1) = 20");
    fmt::println("");

    fmt::println("Printing Modified Array:");
    // Printing modified array
    for (const auto &element: arr) {
        fmt::println("{}", element);
    }
    fmt::println("");

    fmt::println("Filling An Array With A Value:");
    fmt::println("Declare an empty array (arr2)");
    std::array<int, 5> arr2{};
    fmt::println("Filling An Array With a Single Value (7):");
    // Filling array with a single value
    arr2.fill(7);
    fmt::println("");

    fmt::println("Printing Filled Array:");
    // Printing filled array
    for (const auto &element: arr2) {
        fmt::println("{}", element);
    }
    fmt::println("");

    fmt::println("Printing the First Element in An Array");
    fmt::println("arr.front() = {}", arr.front());
    fmt::println("arr2.front() = {}", arr2.front());
    fmt::println("");

    fmt::println("Printing the Last Element in An Array");
    fmt::println("arr.back() = {}", arr.back());
    fmt::println("arr2.back() = {}", arr2.back());
    fmt::println("");

    fmt::println("Making 2D Arrays:");
    constexpr std::array<std::array<int, 2>, 3> arr3{{ {1, 2}, {3, 4}, {5,6} }};

    fmt::println("Printing 2D Array:");
    for (const auto& row : arr3) {
        for (const auto& col : row) {
            fmt::print("{} ", col);
        }
        fmt::println("");
    }

    fmt::println("Comparing Arrays:");
    std::array<int, 3> arr4{1, 2, 3};
    std::array<int, 3> arr5{1, 2, 3};
    std::array<int, 3> arr6{1, 2, 4};

    // Comparing for equality
    fmt::println("Comparing for equality:");
    if (arr4 == arr5)
    {
        fmt::println("arr4 is equal to arr5");
    } else
    {
        fmt::println("arr4 is not equal to arr5");
    }
    fmt::println("");

    // Comparing for inequality
    fmt::println("Comparing for inequality:");
    if (arr4 != arr6)
    {
        fmt::println("arr4 is not equal to arr6");
    } else
    {
        fmt::println("arr4 is equal to arr6");
    }
    fmt::println("");

    //Lexicographical comparison
    fmt::println("Lexicographical array comparison:");
    if (arr4 < arr6)
    {
        fmt::println("arr4 is less than arr6");
    } else
    {
        fmt::println("arr4 is not less than arr6");
    }
    fmt::println("");
}

export void vector_example()
{
    fmt::println("Vectors Example:");
    std::vector<int> vec{1, 2, 3, 4, 5};

    // Accessing Elements using []
    fmt::println("Accessing Elements Using []:");
    for (size_t i = 0; i < vec.size(); ++i)
    {
        fmt::println("vec[{}] = {}", i, vec[i]);
    }
    fmt::println("");

    // Accessing elements using .at()
    fmt::println("Accessing Elements using .at():");
    for (size_t i = 0; i < vec.size(); ++i)
    {
        fmt::println("vec.at({}) = {}", i, vec.at(i));
    }
    fmt::println("");

    // Modifying elements in the vector
    fmt::println("Modifying Elements in the Vector:");
    fmt::println("Modifying Element 0.");
    vec[0] = 10;
    fmt::println("Modifying Element 3.");
    vec[3] = 34;
    fmt::println("");

    fmt::println("Printing Modified Vector:");
    for (size_t i = 0; i < vec.size(); ++i)
    {
        fmt::println("vec[{}] = {}", i, vec[i]);
    }
    fmt::println("");

    // Using range-based for loops
    fmt::println("Using Range-based For Loops:");
    for (const auto& element : vec)
    {
        fmt::println("{}", element);
    }
    fmt::println("");


    fmt::println("Filling A Vector With A Value:");
    fmt::println("Declaring An Empty Vector");
    // Declaring a vector with initial length 5
    std::vector<int> vec2(5);

    fmt::println("Filling Vector with a Single Value (7):");
    // Filling vector with a single value
    std::fill(vec2.begin(), vec2.end(), 7);
    fmt::println("");

    fmt::println("Printing filled Vector:");
    for (const auto& element : vec2)
    {
        fmt::println("{}", element);
    }
    fmt::println("");

    fmt::println("Accessing First & Last Elements:");
    fmt::println("First element: {}", vec.front());
    fmt::println("Last element: {}", vec.back());
    fmt::println("");


    fmt::println("Multi-Dimensional Vector:");
    std::vector<std::vector<int>> multi {{1, 2}, {3, 4}, {5, 6}};

    for (const auto& row : multi)
    {
        for (const auto& col : row)
        {
            fmt::print("{} ", col);
        }
        fmt::println("");
    }
    fmt::println("");
}

export void string_example()
{
    // Declaring a std::string and initializing it
    // with a literal
    fmt::println("Strings Example:");
    // std::string str1 = "Hello World!";
    std::string str1{"Hello World!"};
    fmt::println("str1: {}", str1);
    fmt::println("");

    // Using Constructors
    // Creating a std::string using various constructors
    fmt::println("Using String Constructor:");
    std::string str2(str1);             // Copy constructor
    std::string str3(str1, 7, 5);   // Substring constructor: start at index 7, length 5
    std::string str4(10, 'A');        // Fill constructor: 10 characters of 'A'
    fmt::println("str2: {}", str2);
    fmt::println("str3: {}", str3);
    fmt::println("str4: {}", str4);
    fmt::println("");

    // Accessing Characters
    // Accessing individual characters using the [] operator and at() method
    fmt::println("Accessing Elements in a string:");
    fmt::println("First character of str1 using []: {}", str1[0]);
    fmt::println("Second character of str1 using at(): {}", str1.at(1));
    fmt::println("");

    // Modifying Strings
    // Modifying characters in the string
    fmt::println("Modifying Elements in a string:");
    str1[0] = 't';
    fmt::println("Modified str1 using []: {}", str1);
    str1.at(7) = 'w';
    fmt::println("Modified str1 using at(): {}", str1);
    fmt::println("");

    // Appending
    // Appending to a string using operator+= and append()
    fmt::println("Appending strings (Using operator+ & append()):");
    str1 += " How are you?";
    str2.append(" Goodbye!");
    fmt::println("Appended str1: {}", str1);
    fmt::println("Appended str2: {}", str2);
    fmt::println("");

    // Concatenation
    // Concatenating strings using operator+
    fmt::println("Concatenation for strings using operator+:");
    str3 = "How are you.";
    std::string str5 = str3 + " Everyone!";
    fmt::println("Concatenated str5: {}", str5);

    // Substrings
    // Extracting a substring using substr()
    fmt::println("Extracting a substring:");
    std::string subStr = str1.substr(7, 5); // Start at index 7, length 5
    fmt::println("Substring of str1: {}", subStr);
    fmt::println("");

    //Finding Substrings
    // Finding a substring within a string using find()
    fmt::println("Finding a Substring:");
    size_t pos = str2.find("World");
    if (pos != std::string::npos) {
        fmt::println("'World' found at position: {}", pos);
    } else {
        fmt::println("'World' not found");
    }
    fmt::println("");

    // Comparisons
    // Comparing strings using compare()
    fmt::println("Comparing strings:");
    std::string str6 {"Hello"};
    std::string str7 {"World"};

    /*if (str6.compare(str7) == 0) {
        fmt::println("str6 is equal to str7");
    } else {
        fmt::println("str6 is not equal to str7");
    }*/


    /*if(str6.compare(str7) > 0){
        fmt::println("str6 is greater");
    }else{
        fmt::println("str7 is greater");
    }*/

    // Comparing strings using logical operators
    if (str6 == str7) {
        fmt::println("str6 is equal to str7");
    } else {
        fmt::println("str6 is not equal to str7");
    }

    if(str6 > str7){
        fmt::println("str6 is greater");
    }else{
        fmt::println("str7 is greater");
    }
    fmt::println("");

    // Inserting & Erasing
    // Inserting a substring into a string
    fmt::println("Inserting a substring into a string:");
    fmt::println("Before insertion: {}", str6);
    str6.insert(5, ", Beautiful");
    fmt::println("After insertion: {}", str6);
    fmt::println("");

    // Erasing a part of the string
    fmt::println("Erasing a section of a string");
    fmt::println("Before erasing: {}", str6);
    str6.erase(5, 11); // Erase 11 characters starting from index 5
    fmt::println("After erasing: {}", str6);
    fmt::println("");

    // Obtaining the length & capacity of a string
    fmt::println("Obtaining length of a string:");
    str6 = "Hello World";
    fmt::println("Length of str6: {}", str6.length());
    fmt::println("Size of str6: {}", str6.size());
    fmt::println("");

    fmt::println("Obtaining the capacity of a string:");
    fmt::println("Capacity of str6: {}", str6.capacity());
    fmt::println("");

    // Iterating over a string
    // Using range-based for loop
    fmt::println("Iterating over a string:");
    fmt::println("Characters in str6: ");
    for (const auto& ch : str6) {
        fmt::print("{} ", ch);
    }
    fmt::println("\n");

    // Clearing a string
    fmt::println("Clearing a string:");
    str6.clear();
    fmt::println("Cleared str6, new length: {}", str6.length());
    fmt::println("{}", str6.empty() ? "empty" : "not empty");
    fmt::println("Capacity of str6 after clearing: {}", str6.capacity());
    fmt::println("");
}


export void built_in_arrays()
{

}