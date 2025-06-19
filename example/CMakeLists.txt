cmake_minimum_required(VERSION 3.31)

#The project name is set here. In this case it's Example, but you can change it to whatever you want.
project(Example VERSION 1.0.0 LANGUAGES CXX)

# Print Configuration Info
message(STATUS "Avaliable Configuration Types: ${CMAKE_CONFIGURATION_TYPES}")
message(STATUS "Current Generator: ${CMAKE_GENERATOR}")
message(STATUS "C++ Compiler ID: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "C++ Compiler Version: ${CMAKE_CXX_COMPILER_VERSION}")

#Require C++23
set(CXX_STANDARD_REQUIRED ON) #Make C++23 a hard requirement
set(CMAKE_CXX_STANDARD 23) # Default C++ standard for targets

# Needed if you want to use a C++20 Module
# set(CMAKE_CXX_SCAN_FOR MODULES ON)

# find_package will not download the depeendency for you
# it just searches your system for the dependency
find_package(fmt CONFIG REQUIRED)

# We're using the project name as the target name, but you can change it to make them different.
# With this setup, the name of the executable will be the same as the project name.
# Files with the .cpp extension should be added in the add_executable()
add_executable(${PROJECT_NAME} main.cpp utilities.cpp)

# If using C++20 Modules use this line not the one above
# add_executable(${PROJECT_NAME} main.cpp)

# Add preprocessor definitions
if(ENABLE_LOGGING)
  target_compile_definitions(${PROJECT_NAME} PRIVATE ENABLE_LOGGING)
endif()

if(ENABLE_OPTIMIZATION)
  target_compile_definitions(${PROJECT_NAME} PRIVATE ENABLE_OPTIMIZATION)
endif()

# Needed if you want to use a C++20 Module
# Command, where we will be listing the module files
# All the module files we put in our system will be placed here
# target_sources(${PROJECT_NAME}
#         PUBLIC
#         FILE_SET CXX_MODULES FILES
#         utilities.ixx
# )

# This command ensures that the things from the desired libraries
# are embedded into our executable, I think 
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)