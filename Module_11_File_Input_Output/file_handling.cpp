module;

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <fmt/format.h>
#include <filesystem>
#include <cstring>
#include <array>
#include <bit>

module file_handling;

auto ifstream_examples::character_by_character(const std::string &filename) -> void {
    std::ifstream input_file{filename, std::ios::in};

    if (!input_file.is_open()) {
        std::cerr << "Error! Could not open file for reading!\n";
        return;
    }

    char character{};

    while (input_file.get(character)) {
        if (std::isprint(static_cast<unsigned char>(character))) {
            fmt::print("{}", character);
        }
    }
    input_file.close();
}

auto ifstream_examples::word_by_word(const std::string &filename) -> void {
    std::ifstream input_file{filename, std::ios::in};

    if (!input_file.is_open()) {
        std::cerr << "Error! Could not open file for reading!\n";
        return;
    }

    std::string word{};

    while (input_file >> word) {
        fmt::println("{}", word);
    }
    input_file.close();
}

auto ifstream_examples::line_by_line(const std::string &filename) -> void {
    std::ifstream input_file{filename, std::ios::in};

    if (!input_file.is_open()) {
        std::cerr << "Error! Could not open file for reading!\n";
        return;
    }

    std::string line{};

    while (std::getline(input_file, line)) {
        fmt::print("{}\n", line);
    }
    input_file.close();
}

auto ofstream_example(const std::string &filename) -> void {
    std::ofstream output_file{filename, std::ios::out};

    if (!output_file.is_open()) {
        std::cerr << "Error! Could not open file for writing!\n";
        return;
    }

    // Text being written to file
    output_file << filename << "\n";
    output_file << "Hello! This is new text!\n";
    output_file << "Writing to a file in C++ is straightforward.\n";
    output_file << 3.14159 << '\n';
    output_file << 19 << '\n';

    // Writing Character-by-character
    output_file.put('A');
    output_file.put('B');
    output_file.put('C');
    output_file.put('\n');

    output_file.close();

    fmt::println("File written successfully!");
}

auto fstream_example(const std::string &filename) -> void {
    std::fstream file{filename, std::ios::in | std::ios::out};

    if (!file.is_open()) {
        std::cerr << "Error! Could not open file for reading!\n";
        return;
    }

    std::string line{};

    while (std::getline(file, line)) {
        fmt::print("{}\n", line);
    }

    fmt::println("File Read successfully!\n");

    file.clear();

    file.seekp(0, std::ios::end);
    file << "Appended after reading\n";

    file.flush();

    file.seekg(0, std::ios::beg);
    while (std::getline(file, line)) {
        fmt::print("{}\n", line);
    }

    file.close();
}

auto filesystem_examples::file_path_example() -> void {
    const std::filesystem::path execution_path = std::filesystem::current_path();
    std::filesystem::path project_path{};

    for (auto directory = execution_path.begin(); *directory != "cmake-build"; ++directory) {
        project_path /= *directory;
    }

    fmt::println("Path for Project Directory: {}\n", project_path.string());

    fmt::println("Appending file name to path, then checking to see if it exists:");

    // Both methods append to a path
    project_path.append("read_only_file.txt");
    // project_path /= "read_only_file.txt";

    if (!std::filesystem::exists(project_path)) {
        std::cerr << "Error! File not found!";
        return;
    }

    fmt::println("File Exists!: {}", project_path.string());
}

auto filesystem_examples::file_directory_example() -> void {
    namespace fs = std::filesystem;
    fs::path project_path = [] -> fs::path {
        fs::path execution_path{fs::current_path()};
        fs::path temp_path{};

        for (auto directory = execution_path.begin(); *directory != "cmake-build"; ++directory) {
            temp_path /= *directory;
        }
        return temp_path;
    }();

    fmt::println("Path for Project Directory: {}\n", project_path.string());

    project_path.append("read_only_file.txt");
    fmt::println("File name: {}", project_path.filename().string());
    fmt::println("Stem: {}", project_path.stem().string());
    fmt::println("Extension: {}\n", project_path.extension().string());
    fmt::println("Parent Path: {}\n", project_path.parent_path().string());
    fmt::println("Relative Path: {}\n", project_path.relative_path().string());
    fmt::println("Root Path: {}\n", project_path.root_path().string());
    fmt::println("Root Directory: {}\n", project_path.root_directory().string());

    fmt::println("Contents of Parent directory (Does not visit subdirectories)");
    for (const auto &entry: fs::directory_iterator(project_path.parent_path())) {
        fmt::println("{} {}", entry.is_directory() ? "[Dir]" : "[File]", entry.path().filename().string());
    }

    // Use recursive_directory_iterator to visit subdirectories (if any exist)
    /*for (const auto &entry: fs::recursive_directory_iterator(project_path.parent_path())) {
        fmt::println("{} {}", entry.is_directory() ? "[Dir]" : "[File]", entry.path().filename().string());
    }*/
}

auto filesystem_examples::reading_files() -> void {
    namespace fs = std::filesystem;
    fs::path project_path = [](fs::path &p_path) -> fs::path {
        fs::path execution_path{fs::current_path()};

        for (auto directory = execution_path.begin(); *directory != "cmake-build"; ++directory) {
            p_path /= *directory;
        }
        return p_path;
    }(project_path);

    fmt::println("Path for Project Directory: {}\n", project_path.string());
}

auto fstream_binary_example::write_file(const std::string &filename) -> void {
    Player mainPlayer{};
    mainPlayer.id = 23;
    std::strcpy(mainPlayer.name, "Main One");
    mainPlayer.health = 76.12;

    std::ofstream out_file{filename, std::ios::out | std::ios::binary};

    if (!out_file.is_open()) {
        std::cerr << "Error! File not found!\n";
        return;
    }

    out_file.write(reinterpret_cast<const char *>(&mainPlayer), sizeof(mainPlayer));
    out_file.close();

    fmt::println("Writing to file {}, Success!\n", filename);
}

auto fstream_binary_example::read_file(const std::string &filename) -> void {
    Player loadPlayer{};

    std::ifstream in_file{filename, std::ios::in | std::ios::binary};
    if (!in_file.is_open()) {
        std::cerr << "Error! File not found!\n";
        return;
    }

    in_file.read(reinterpret_cast<char *>(&loadPlayer), sizeof(loadPlayer));
    fmt::println("Reading from file {}", filename);
    fmt::println("Player ID: {}", loadPlayer.id);
    fmt::println("Player Name: {}", loadPlayer.name);
    fmt::println("Player Health: {}\n", loadPlayer.health);
}

auto modern_cpp_binary_example::get_path() -> std::filesystem::path {
    namespace fs = std::filesystem;
    fs::path filepath = [] -> fs::path {
        fs::path execution_path{fs::current_path()};
        fs::path temp_path{};

        for (auto directory = execution_path.begin(); *directory != "cmake-build"; ++directory) {
            temp_path /= *directory;
        }
        return temp_path;
    }();

    return filepath;
}

auto modern_cpp_binary_example::write_file() -> void {
    namespace fs = std::filesystem;
    fs::path file_path = get_path();
    file_path /= "player_data.bin";

    Player mainPlayer{14, "myName", 71.4123};

    std::ofstream out_file{file_path, std::ios::out | std::ios::binary};
    if (!out_file.is_open()) {
        throw std::runtime_error("Error! File not found: " + file_path.string());
    }

    auto bytes = std::bit_cast<std::array<char, sizeof(Player)> >(mainPlayer);

    out_file.write(bytes.data(), bytes.size());
    out_file.close();
}

auto modern_cpp_binary_example::read_file() -> void {
    namespace fs = std::filesystem;
    fs::path file_path = get_path();
    file_path /= "player_data.bin";

    std::ifstream in_file{file_path, std::ios::in | std::ios::binary};
    if (!in_file.is_open()) {
        throw std::runtime_error("Error! File not found: " + file_path.string());
    }

    std::array<char, sizeof(Player)> bytes{};
    in_file.read(bytes.data(), bytes.size());

    auto loadPlayer{std::bit_cast<Player>(bytes)};
    fmt::println("Reading from file {}", file_path.string());
    fmt::println("Player ID: {}", loadPlayer.id);
    fmt::println("Player Name: {}", loadPlayer.name);
    fmt::println("Player Health: {}\n", loadPlayer.health);
}
