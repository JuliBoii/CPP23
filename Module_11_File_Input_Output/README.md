# File I/O

For this module, we will be learning how to write & read files in our system using C++.

<!--@formatter:off-->
<!-- TOC -->
* [File I/O](#file-io)
  * [Writing and Reading Files](#writing-and-reading-files)
    * [`std::ifstream`](#stdifstream)
      * [Method 1: Line-by-Line](#method-1-line-by-line)
      * [Method 2: Word-by-Word](#method-2-word-by-word)
      * [Method 3: Character-by-character](#method-3-character-by-character)
    * [`std::ofstream`](#stdofstream)
    * [`std::fstream`](#stdfstream)
  * [Modern File Handling](#modern-file-handling)
    * [Foundational Components](#foundational-components)
      * [Common Operations](#common-operations)
        * [Examples of Common Operations](#examples-of-common-operations)
    * [Platform Independence](#platform-independence)
    * [Error Handling Note](#error-handling-note)
<!-- TOC -->
<!--@formatter:on-->

## Writing and Reading Files

File reading and writing are primarily handled using the `<fstream>` library. Within this library, are three main
classes used:

- `std::ifstream`
- `std::ofstream`
- `std::fstream`

These three classes are used to handle file operations. Acting as "streams" or data pipelines that connect one's
program to files stored on a hard drive or SSD.

### `std::ifstream`

First class we will focus on is `std::ifstream`. Used for strictly extracting or reading information from an
existing file. Protects one's file from accidental modifications since it cannot write data.

When trying to open the file, if the file does not exist, the operation will fail.

There are three methods for extracting information from a file:

1. Line-by-line (Recommended for Text)
2. Word-by-word
3. Character-by-character

Let us look at examples.

#### Method 1: Line-by-Line

This method is best for text files, where we want to preserve spaces. So program reads until the occurrence of the
newline character (`\n`) or custom delimiter. Utilize the `std::getline()` method to obtain each line.

Example:

```c++
#include <print>
#include <iostream>
#include <fstream>
#include <string>

auto main() -> int {
    std::string file_name = R"(C:\\Document\Path\ifstream.txt)";
    std::ifstream input_file{filename}; // File we want to open

    if (!input_file.is_open()) {
        std::cerr << "Error! Could not open file for reading!\n";
        return;
    }

    std::string line{};

    while (std::getline(input_file, line)) {
        std::print("{}\n", line);
    }
    input_file.close();
    
    return 0;
}
```

#### Method 2: Word-by-Word

Best used if file being opened is structured. Specifically, has data items (like a list of numbers or words). We
utilize the extraction operator (`>>`), which skips whitespaces (spaces, tabs, newlines).

Example:

```c++
#include <print>
#include <iostream>
#include <fstream>
#include <string>

auto main() -> int {
    std::string filename = R"(C:\\Document\Path\ifstream.txt)";
    std::ifstream input_file{filename};

    if (!input_file.is_open()) {
        std::cerr << "Error! Could not open file for reading!\n";
        return;
    }

    std::string word{};

    while (input_file >> word) {
        fmt::println("{}", word);
    }
    input_file.close();
    
    return 0;
}
```

#### Method 3: Character-by-character

This is best option for precise, character-by-character reading. This method captures all whitespace characters
unlike method 2, which skips them. Utilize the `get()` method to obtain characters.

Example:

```c++
#include <iostream>
#include <fstream>
#include <print>
#include <string>
#include <cctype>

auto main() -> int {
    std::string filename = R"(C:\\Document\Path\ifstream.txt)";
    std::ifstream input_file{filename};

    if (!input_file.is_open()) {
        std::cerr << "Error! Could not open file for reading!\n";
        return;
    }

    char character{};

    while (input_file.get(character)) {
        // Check to see if the character we are handling
        // can be printed properly, otherwise we move on to next character
        if (std::isprint(static_cast<unsigned char>(character))) {
            fmt::print("{}", character);
        }
    }
    
    input_file.close();

    return 0;
}
```

### `std::ofstream`

In turn, `std::ofstream` is used to create a file or overwrite an existing file's content with new data.

If the file exists, using `std::ofstream` will erase (truncate) its content by default.

To write data to a file, one creates an object of the `std::ofstream` class. Allowing us to interact with it using
the exact same stream insertion operator (`<<`), utilized with `std::cout`.

We can also utilize the `put()` method to write to a file character-by-character.

Example:

```c++
#include <string>
#include <iostream>
#include <fstream>

auto main() -> int
{
    std::string output_file = R"(C:\\Document\Path\ofstream.txt)";
    std::ofstream output_file{filename};

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
    output_file.write(reinterpret_cast<char*>(413), sizeof(int));
    output_file.put('A');
    output_file.put('B');
    output_file.put('C');
    output_file.put('\n');

    output_file.close();

    fmt::println("File written successfully!");
    
    return 0;
}
```

### `std::fstream`

This class is a hybrid stream capable of simultaneously reading from and writing to the same file. Since,
`std::fstream` can do both read and write, one needs to explicitly state the "mode" being used, when opening a
file. Some modes used are:

- `std::ios::in`
  - Used for reading file
- `std::ios::out`
  - Used for writing to file
- `std::ios::app`
  - Used to append to a file
    - Rather than overwriting existing text, if file existed already, `std::ios::app` adds new text to the end of
      the file without erasing it.
- [More comprehensive list](https://cppreference.com/cpp/io/ios_base/openmode)

Example:

```c++
#include <string>
#include <print>
#include <fstream>
#include <iostream>

auto main() -> int
{
    // Open file for reading and writing using bitwise OR (operator|)
    std::string filename = R"(fstream.txt)";
    std::fstream file{filename, std::ios::in | std::ios::out};

    if (!file.is_open()) {
        std::cerr << "Error! Could not open file!\n";
        return;
    }

    std::string line{};

    while (std::getline(file, line)) {
        fmt::print("{}\n", line);
    }

    std::println("File Read successfully!\n");

    // Clear EOF State Flags before continuing
    // Reaching the end of the file sets the 'eof' and 'fail' flags
    // Blocking us from doing anything else
    file.clear();

    // Switch to writing:
    file.seekp(0, std::ios::end);
    file << "Appended after reading\n";

    // Force synchronization before Reading again
    file.flush();

    file.seekg(0, std::ios::beg);
    while (std::getline(file, line)) {
        fmt::print("{}\n", line);
    }

    file.close();
    return 0;
}
```

> Rule of thumb, better to use the more restrictive classes if possible. If one only needs to read a file, utilize
> `std::ifstream` over `std::fstream`. Prevents accidental data deletion and makes one's program safer, cleaner.

## Modern File Handling

In Modern C++ (>=C++17), file handling has shifted from raw character buffers and manual pointer manipulation. New
principles emphasize type safety, portability via the `<filesystem>` header, and cleaner memory management utilizing
standard containers like `std::string` and `std::vector`.

This library eliminates the need to rely on platform-specific C APIs (like POSIX or Windows API) for routine file
system management.

This library is heavily modeled after the popular `Boost.Filesystem` Library, which was widely used before being
standardized in C++.

### Foundational Components

The `std::filesystem` library is built around three core components:

<!--@formatter:off-->
1. `std::filesystem::path`
  - Represents a file or directory path
  - Automatically abstracts away platform-specific details
2. `std::filesystem::directory_entry`
  - Represents a specific object on the file system
  - Caches its metadata (i.e., file size, permissions, or modification time) for high-performance access
3. Directory Iterators
  - Tools used to loop through folders
    - `directory_iterator`
      - Views a single folder level
    - `recursive_directory_iterator`
      - Automatically traverses down into all subfolders
<!--@formatter:on-->

#### Common Operations

The library exposes dozen of non-member functions to perform everyday actions safely without needing external scripts.

- `std::filesystem::exists()`
  - Checks for existence
- `std::filesystem::create_directory()`
  - Creates a directory
- `std::filesystem::copy_file()`
  - Copies a file
- `std::filesystem::remove()`
  - Deletes a file
- `std::filesystem::file_size()`
  - Access file attribute

##### Examples of Common Operations

Path manipulation & decomposition:

```c++
#include <filesystem>
#include <print>

namespace fs = std::filesystem;

auto main() -> int {
    fs::path file_path{R"(G:\report_file.txt)"};

    std::println("File name: {}", file_path.filename().string());   // "report_file.txt"
    std::println("Extension: {}", file_path.extension().string());  // ".txt"
    std::println("Stem: {}", file_path.stem().string());  // ".txt"
    std::println("Parent Path: {}", file_path.parent_path().string());  // "G:\report_file.txt"
    
    // Appending to path
    fs::path build_dir{R"(C:\project)"};
    // Either option below results in: "C:\project\build"
    //build_dir /= "build";   
    build_dir.append("build");
    
    return 0;
}
```

Querying Attributes

```c++
#include <filesystem>
#include <print>

namespace fs = std::filesystem;

auto main() -> int {
    fs::path file_path{R"(G:\report_file.txt)"};
    
    if (fs::exists(file_path)) { // Checks existance, if path exists
        if (fs::is_regular_file(file_path)) {
            std::println("File size: {} bytes", fs::file_size(file_path));
        }
        else if (fs::is_directory(file_path)) {
            std::println("This is a Directory!");
        }
    }
    
    return 0;
}
```

Metadata

```c++
#include <filesystem>
#include <cstdint>
#include <ctime>

namespace fs = std::filesystem;

auto main() -> int {
    fs::path file_path{R"(G:\report_file.txt)"};
    
    if (fs::exists(file_path)) {
        if (fs::is_regular_file(file_path)) {
            std::uintmax_t f_size = fs::file_size(file_path);
            auto time = fs::last_write_time(file_path);
        }
    }
    
    return 0;
}
```

File System Modifications:
Creation

```c++
#include <filesystem>
#include <print>

namespace fs = std::filesystem;

auto main() -> int {
    fs::create_directory("sandbox");
    fs::create_directories("sandbox/a/b/c/"); // Creates a nested tree
    
    return 0;
}
```

Copying and moving

```c++
#include <filesystem>
#include <print>

namespace fs = std::filesystem;

auto main() -> int {
    fs::path root_path{R"(G:\)"};
    fs::copy("Source_file.txt", "Destination_file.txt");
    fs::copy("source_directory", "destination_directory", fs::copy_option::recursive); // Copy Recursivly
    fs::rename("vnbab.txt", "new_name.txt"); // Move or rename
    
    return 0;
}
```

Deletion (directories)

```c++
#include <filesystem>
#include <print>

namespace fs = std::filesystem;

auto main() -> int {
    fs::path nested_folder{R"(G:\src\a\b\c)"};
    fs::path src_folder{R"(G:\src)"};
    fs::remove(nested_folder);  // Removes file or empty directory
    fs::remove_all(src_folder); // Deletes the contents of src_folder (if a directory), and contents recursivly
    
    return 0;
}
```

### Platform Independence

Before we read or write a file, we need to know where, if it exists, the file is located. Instead of hardcoding the
full path to the file we want to access, [like in our examples above](#writing-and-reading-files), we utilize
`std::filesystem` to handle file paths. This is especially helpful for portability across different operating systems.

So this library helps abstract away operating system difference, such as handling directory separators. Such as `\`
for Windows and `/` for Linux/macOS.

For the example below, we write out the namespace for library components. However, it is common practice to create a
namespace alias for the `std::filesystem` namespace. Commonly, `fs` is used as the alias.

Example:

```c++
#include <filesystem>
#include <print>
#include <iostream>

auto main() -> int {
    const std::filesystem::path execution_path = std::filesystem::current_path();
    std::filesystem::path project_path{}; // Absolute Path to our Project Directory

    // navigates to target directory
    for (auto directory = execution_path.begin(); *directory != "cmake-build"; ++directory) {
        project_path /= *directory;
    }

    std::println("Path for Project Directory: {}\n", project_path.string());

    std::println("Appending file name to path, then checking to see if it exists:");

    // Both methods append to a path
    project_path.append("read_only_file.txt");

    // Check if path exists
    if (!std::filesystem::exists(project_path)) {
        std::cerr << "Error! File not found!";
        return;
    }

    std::println("File Exists!: {}", project_path.string());
    return 0;
}
```

Another example:

```c++
#include <filesystem>
#include <print>
#include <iostream>

namespace fs = std::filesystem;

auto main() -> int {
    const fs::path execution_path = fs::current_path();
    fs::path project_path{}; // Absolute Path to our Project Directory

    for (auto directory = execution_path.begin(); *directory != "cmake-build"; ++directory) {
        project_path /= *directory;
    }
    
    project_path.append("read_only_file.txt");
    std::println("File name: {}", project_path.filename().string());
    std::println("Extension: {}", project_path.extension().string());
    std::println("Parent Path: {}", project_path.parent_path().string());
    
    // Creating a new directory
    fs::path new_folder_path{"temp_folder"};
    if (!fs::exists(new_folder_path)) {
        fs::create_directory(new_folder_path);
    }
    
    // Iterating through a directory recursively
    std::println("Contents of Parent directory");
    for (const auto& item : fs::recursive_directory_iterator(project_path.parent_path())) {
        std::println("{} {}", item.is_directory() ? "[Dir]" : "[File]", item.path().filename().string());
    }

    return 0;
}
```

### Error Handling Note

Most `std::filesystem` functions offer two versions:

<!--@formatter:off-->
1. Throwing: Throws `std::filesystem::filesystem_error` on failure
2. Error-code: Takes a `std::error_code` out-parameter.
   - Prevents exceptions from throwing.
   - Often preferred for performance or when a missing file is expected behavior
<!--@formatter:on-->

Example:

```c++
#include <iostream>
#include <cstdint>
#include <filesystem>

namespace fs = std::filesystem;

auto main() -> int {
    fs::path p = "/invalid/path/file.txt";

    // Approach 1: Exception
    try {
        std::uintmax_t size = fs::file_size(p);
    } catch (const fs::filesystem_error& e) {
        std::cerr << e.what() << "\n";
    }
    
    // Approach 2: std::error_code (No exceptions thrown)
    std::error_code ec;
    std::uintmax_t size = fs::file_size(p, ec);
    
    if (ec) {
        std::cerr << "Error: " << ec.message() << "\n";
    }

    return 0;
}
```

## Working with Binary I/O

Binary file input and output in C++ allows for reading and writing data utilizing raw byte-level representation.
Exactly as it is in a computer's memory. Unlike our previous examples, which converts numbers and other various data
types into readable characters, then formats them with spaces or newlines. Binary I/O disregards the need for
formatting. Making the reading and writing faster, while also resulting in smaller file sizes.

When writing, we have to specify that we are writing data in a bunch of bytes. We also need to know how many bytes
we already have written. This aids when reading back the data.

> A byte is the same size of a `char`. Which is why we utilize `char` in our upcoming example.

### Read/Write Binary (`fstream`)

When writing binary, we need to remember 4 core concepts:

<!--@formatter:off-->
1. `ios::binary` flag
   - When opening a stream, one must explicitly pass the binary flag
   - This prevents the OS from translating special characters
2. `write()`
   - Used to save raw data from memory into a file
   - Its prototype requires a character pointer `const char*` and the size of the block in bytes
3. `read()` Member Function
   - Used to read raw data from a file back into memory
   - Also requires a special character pointer (`char*`) pointing to destination buffer
     - Along with the expected size in bytes
4. `reinterpret_cast<char*>`
   - Since binary functions exclusively expect a block of raw bytes
   - One must type-cast the address of custom variable or structures so the stream can process it byte-by-byte
<!--@formatter:on-->

> Casting an entire structure/object to `char*` only works for Plain Old Data or trivial types. Dynamically
> allocated types (`std::string`, `std::vector`, or raw pointer) does not work with `sizeof()`. Doing so, will
> result in a crash or garbage data when reading.

```c++
#include <fstream>
#include <iostream>
#include <cstring>

struct Player {
    int id;
    char name[40];
    double health;
};

auto main() -> int {
    const char* filename = "player_data.bin";
    
    // INIT data
    Player mainPlayer;
    mainPlayer.id = 24;
    std::strcpy(mainPlayer.name, "MainOne");
    mainPlayer.health = 100;
    
    // Write (Bin)
    std::ofstream outFile(filename, std::ios::out | std::ios::binary);
    
    if (!outFile.is_open()) {
        std::cerr << "Error opening file for writing\n";
        return 1;
    }
    
    // write raw memory block of object to file
    outFile.write(reinterpret_cast<const char*>(&mainPlayer), sizeof(Player));
    outFile.close();
    
    std::cout << "Success! Wrote to file: " << filename << "\n\n";
    
    // Read (Bin)
    Player loadPlayer; // Empty object
    
    // Open file
    std::ifstream inFile(filename, std::ios::in | std::ios::binary);
    
    if (!inFile.is_open()) {
        std::cerr << "Error opening file\n\n";
        return 1;
    }
    
    // Read raw memory bytes
    inFile.read(reinterpret_cast<char*>(&loadPlayer), sizeof(Player));
    inFile.close();
    
    // Print Data
    std::cout << "Data: ---------\n";
    std::cout << "Player ID: " << loadPlayer.id << "\n";
    std::cout << "Player Name: " << loadPlayer.name << "\n";
    std::cout << "Player Health: " << loadPlayer.health << "\n";
    
    return 0;
}
```

### Read/Write Binary (Modern C++)

We can rewrite our example to incorporate modern C++ features/facilites. With the use of `<filesystem>` to handle
paths, or check directory existence and clean up the file afterward. We can also replace the use of
`reinterpret_cast` with `std::bit_cast` (C++20 Feature) for safer memory conversions.

```c++
#include <iostream>
#include <fstream>
#include <filesystem>
#include <array>
#include <print> // C++23 standard printing
#include <bit> // C++20 for std::bit_cast

namespace fs = std::filesystem;

struct Player {
    int id;
    char name[40];
    double health;
};

auto main() -> int {
    // File path generation
    fs::path filepath = [] -> fs::path {
        fs::path execution_path{fs::current_path()};
        fs::path temp_path{};

        for (auto directory = execution_path.begin(); *directory != "cmake-build"; ++directory) {
            temp_path /= *directory;
        }
        return temp_path /= "player_data.bin";
    }();
    
    // Init Object
    Player mainPlayer{14, "myName", 54.641};
    
    try {
        // Write binary
        std::ofstream outFile(filepath, std::ios::binary);
        if (!outFile.is_open()) {
            throw std::runtime_error("Failed to open file for writing: " + filepath.filename().string());
        }
        
        // Bit cast into raw byte array
        auto bytes = std::bit_cast<std::array<char, sizeof(Player)>>(mainPlayer);
        
        // Write out
        outFile.write(bytes.data(), bytes.size());
        outFile.close();
        
        // Read Binary
        std::ifstream inFile(filepath, std::ios::binary);
        
        if (!inFile.is_open()) {
            throw std::runtime_error("Failed to open file for reading: ", filepath.filename().string());
        }
        
        std::array<char, sizeof(Player)> readBytes{};
        
        inFile.read(readBytes.data(), readBytes.size());
        
        Player loadPlayer = std::bit_cast<Player>(readBytes);
        
        std::println("Reading from file {}", filename);
        std::println("Player ID: {}", loadPlayer.id);
        std::println("Player Name: {}", loadPlayer.name);
        std::println("Player Health: {}\n", loadPlayer.health);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    
    return 0;
}
```