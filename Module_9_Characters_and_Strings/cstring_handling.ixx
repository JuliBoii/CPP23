module;

#include <cstring>
#include <fmt/format.h>

export module cstring_handling;

namespace cstring_handling {
    export void using_strcpy_and_strncpy() {
        fmt::println("Example using std::strcpy and std::strncpy");
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
    }

    export void using_strcat_and_strncat() {
        fmt::println("Example using std::strcat and std::strncat");
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
    }

    export void using_strlen() {
        fmt::println("Example using std::strlen");
        constexpr char message1[]{"The sk\0y is blue.\0"};

        //Array decays into pointer when we use const char*
        const char *message2{"The sky is bl\0ue.\0"};
        fmt::println("message1 : {}", message1);
        fmt::println("message2 : {}", message2);

        //strlen ignores null character
        fmt::println("strlen(message1) : {}", std::strlen(message1));

        // std::sizeof includes the null character
        fmt::println("sizeof(message1) : {}", sizeof(message1));

        //strlen still works with decayed arrays
        fmt::println("strlen(message2) : {}", std::strlen(message2));

        //std::sizeof prints size of pointer
        fmt::println("sizeof(message2) : {}\n", sizeof(message2));
    }

    export void using_strcmp_and_strncmp() {
        fmt::println("Example using std::strcmp and std::strncmp");

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
    }

    export void using_strchr_and_strrcmp() {
        fmt::println("Example using std::strchr and strrcmp");
        constexpr char string_data1[]{"Havana Banana in Transylvania next to Pennsylvania"};
        const char *string_data2{"Havana Banana in Transylvania next to Pennsylvania"};
        constexpr char target = 'i';

        fmt::println("Using std::strchr()");
        const char *result = string_data1;
        fmt::println("Source cstring is const char[]");
        result = std::strchr(string_data1, target);
        if (result) {
            fmt::println("{}\n", result);
        }

        /*while ((result = std::strchr(result, target)) != nullptr) {
            fmt::println("Found '{}', starting at: {}", target, result);
            result++;
        }*/

        fmt::println("Source cstring is const char *");
        result = std::strchr(string_data2, target);
        if (result) {
            fmt::println("{}\n", result);
        }

        /*while ((result = std::strchr(result, target)) != nullptr) {
            fmt::println("Found '{}', starting at: {}", target, result);
            result++;
        }*/

        fmt::println("Using std::strrchr()");
        fmt::println("Source cstring is const char[]");
        result = std::strrchr(string_data1, target);
        if (result) {
            fmt::println("{}\n", result);
        }

        fmt::println("Source cstring is const char *");
        result = std::strrchr(string_data2, target);
        if (result) {
            fmt::println("{}\n", result);
        }
    }
}
