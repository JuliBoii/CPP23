module;

#include <filesystem>

export module csv_handling;

namespace csv_handling {
    export auto writing_csv_file(const std::filesystem::path &csv_file_path) -> void;

    export auto reading_csv_file(const std::filesystem::path &csv_file_path) -> void;
}
