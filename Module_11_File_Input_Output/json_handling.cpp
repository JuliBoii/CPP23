module;

#include <filesystem>
#include <fstream>
#include <fmt/format.h>
#include <stdexcept>
#include <string>

module json_handling;

auto json_handling::writing_json_file(const std::filesystem::path &file_path) -> void {
    std::ofstream json_file(file_path, std::ios::out);

    if (!json_file.is_open()) {
        throw std::runtime_error("JSON file " + file_path.string() + " cannot be opened.");
    }

    // Do not actually do the following
    // It is better to use dedicated libraries for handling JSON
    // This is merely a basic example
    json_file << "[\n";

    json_file << "  {\n";
    json_file << "  \t\"name\": \"Alice\",\n";
    json_file << "  \t\"age\": \"30\",\n";
    json_file << "  \t\"occupation\": \"Engineer\"\n";
    json_file << "  },\n";

    json_file << "  {\n";
    json_file << "  \t\"name\": \"John\",\n";
    json_file << "  \t\"age\": \"28\",\n";
    json_file << "  \t\"occupation\": \"Software Engineer\"\n";
    json_file << "  },\n";

    json_file << "  {\n";
    json_file << "  \t\"name\": \"Yoshi\",\n";
    json_file << "  \t\"age\": \"47\",\n";
    json_file << "  \t\"occupation\": \"Project Team Leader\"\n";
    json_file << "  }\n";

    json_file << "]\n";

    json_file.close();
    fmt::println("Successfully wrote to: {}", file_path.string());
}

// We are not processing the data, we are just reading the file
auto json_handling::reading_json_file(const std::filesystem::path &file_path) -> void {
    if (!std::filesystem::exists(file_path)) {
        throw std::runtime_error("File does not exist.");
    }

    std::ifstream json_file(file_path, std::ios::in);

    if (!json_file.is_open()) {
        throw std::runtime_error("JSON file cannot be opened.");
    }

    std::string line;
    while (std::getline(json_file, line)) {
        fmt::print("{}\n", line);
    }

    json_file.close();
}
