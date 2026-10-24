#include <string>
#include <array>
#include <iostream>
#include <fmt/format.h>

import file_handling;

auto main() -> int {
    // For Docker Build
    std::array<std::string, 4> docker_file_paths{
        R"(/tmp/Module_11_File_Input_Output/read_only_file.txt)",
        R"(/tmp/Module_11_File_Input_Output/write_only_file.txt)",
        R"(/tmp/Module_11_File_Input_Output/fstream_file.txt)",
        R"(/tmp/Module_11_File_Input_Output/player.bin)",
    };

    // For Windows
    std::array<std::string, 4> windows_file_paths{
        R"(G:\Juli\Documents\CLionProjects\CPP23\Module_11_File_Input_Output\read_only_file.txt)",
        R"(G:\Juli\Documents\CLionProjects\CPP23\Module_11_File_Input_Output\write_only_file.txt)",
        R"(G:\Juli\Documents\CLionProjects\CPP23\Module_11_File_Input_Output\fstream_file.txt)",
        R"(G:\Juli\Documents\CLionProjects\CPP23\Module_11_File_Input_Output\player.bin)",
    };

    /*fmt::println("Character by Character");
    ifstream_examples::character_by_character(windows_file_paths.at(0));

    fmt::println("\n\nWord by Word");
    ifstream_examples::word_by_word(windows_file_paths.at(0));

    fmt::println("\nLine by line");
    ifstream_examples::line_by_line(windows_file_paths.at(0));*/

    /*fmt::println("Writing to a file (Exclusively)");
    ofstream_example(windows_file_paths.at(1));*/

    /*fmt::println("Reading and Writing");
    fstream_example(windows_file_paths.at(2));*/

    // filesystem_examples::file_path_example();

    // filesystem_examples::file_directory_example();

    // fstream_binary_example::write_file(docker_file_paths.at(3));
    // fstream_binary_example::read_file(docker_file_paths.at(3));
    // fstream_binary_example::write_file(windows_file_paths.at(3));
    // fstream_binary_example::read_file(windows_file_paths.at(3));

    try {
        modern_cpp_binary_example::write_file();
        modern_cpp_binary_example::read_file();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
