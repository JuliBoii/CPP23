cmake_minimum_required(VERSION 3.31)

project(SimpleProject VERSION 1.0.0 LANGUAGES CXX)

#Require C++23
set(CMAKE_CXX_STANDARD_REQUIRED ON) #Make C++23 a hard requirement
set(CMAKE_CXX_STANDARD 23) # Default C++ standard for targets

# Needed if you want to use a C++20 Module
set(CMAKE_CXX_SCAN_FOR MODULES ON)

find_package(fmt CONFIG REQUIRED)
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

# Add preprocessor definitions
if(ENABLE_LOGGING)
  target_compile_definitions(${PROJECT_NAME} PRIVATE ENABLE_LOGGING)
endif()

if(ENABLE_OPTIMIZATION)
  target_compile_definitions(${PROJECT_NAME} PRIVATE ENABLE_OPTIMIZATION)
endif()

target_sources(${PROJECT_NAME}
         PUBLIC
         FILE_SET CXX_MODULES FILES
         utilities.ixx
 )

# This command ensures that the things from the desired libraries
# are embedded into our executable, I think
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt sfml-graphics)