module;

#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <string>
#include <fmt/format.h>

module csv_handling;


auto csv_handling::writing_csv_file(const std::filesystem::path &csv_file_path) -> void {
    std::ofstream csv_file{csv_file_path, std::ios::out};

    if (!csv_file.is_open()) {
        throw std::runtime_error{"Cannot open file: " + csv_file_path.string()};
    }

    csv_file << "name, age, occupation\n";
    csv_file << "Alice, 40, Engineer\n";
    csv_file << "Bob, 24, Junior Engineer\n";
    csv_file << "Roberta, 19, Intern\n";
    csv_file << "Mikael, 71, Regional Manager\n";

    csv_file.close();
    fmt::println("Successfully wrote to {}", csv_file_path.string());
}

auto csv_handling::reading_csv_file(const std::filesystem::path &csv_file_path) -> void {
    if (!std::filesystem::exists(csv_file_path)) {
        throw std::runtime_error{"File: " + csv_file_path.string() + " does not exist."};
    }

    std::ifstream csv_file{csv_file_path, std::ios::in};

    if (!csv_file.is_open()) {
        throw std::runtime_error{"Cannot open file: " + csv_file_path.string()};
    }

    std::string line{};
    while (std::getline(csv_file, line)) {
        fmt::print("{}\n", line);
    }
    
    csv_file.close();
    fmt::print("Successfully read {}\n", csv_file_path.string());
}
