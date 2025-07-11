#The root CMakeLists.txt file.
cmake_minimum_required(VERSION 3.28)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

#The project name is set here. In this case it's main, but you can change it to whatever you want.
project(Main VERSION 1.0.0 LANGUAGES CXX)

# Print Configuration Info
message(STATUS "Configuration types: ${CMAKE_CONFIGURATION_TYPES}")
message(STATUS "Current Generator: ${CMAKE_GENERATOR}")
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER}")

# Config-specific Flags
foreach(cfg IN LISTS CMAKE_CONFIGURATION_TYPES)
    string(TOUPPER "${cfg}" upper_cfg)
    set(CMAKE_CXX_FLAGS_${upper_cfg} "${CMAKE_CXX_FLAGS_${upper_cfg}}")
endforeach()

#Require C++23
set(CXX_STANDARD_REQUIRED ON) #Make C++23 a hard requirement
set(CMAKE_CXX_STANDARD 23) # Default C++ standard for targets

find_package(fmt CONFIG REQUIRED)

#We're using the project name as the target name, but you can change it to make them different.
#With this setup, the name of the executable will be the same as the project name.
add_executable(${PROJECT_NAME} main.cpp utilities.cpp)

# Add preprocessor definitions
if(ENABLE_LOGGING)
  target_compile_definitions(${PROJECT_NAME} PRIVATE ENABLE_LOGGING)
endif()

if(ENABLE_OPTIMIZATION)
  target_compile_definitions(${PROJECT_NAME} PRIVATE ENABLE_OPTIMIZATION)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)