module;

#include <filesystem>

export module json_handling;

namespace json_handling {
    export auto writing_json_file(const std::filesystem::path& path) -> void;
    export auto reading_json_file(const std::filesystem::path& path) -> void;
}