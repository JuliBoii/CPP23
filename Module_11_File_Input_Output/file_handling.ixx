module;

#include <string>
#include <filesystem>

export module file_handling;

struct Player {
    int id;
    char name[40];
    double health;
};

namespace ifstream_examples {
    export auto character_by_character(const std::string &filename) -> void;

    export auto word_by_word(const std::string &filename) -> void;

    export auto line_by_line(const std::string &filename) -> void;
}

export auto ofstream_example(const std::string &filename) -> void;

export auto fstream_example(const std::string &filename) -> void;

namespace filesystem_examples {
    export auto file_path_example() -> void;

    export auto file_directory_example() -> void;

    export auto reading_files() -> void;
}

namespace fstream_binary_example {
    export auto write_file(const std::string &filename) -> void;

    export auto read_file(const std::string &filename) -> void;
}

namespace modern_cpp_binary_example {
    export auto get_path() -> std::filesystem::path;

    export auto write_file() -> void;

    export auto read_file() -> void;
}
