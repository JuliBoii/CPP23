cmake_minimum_required(VERSION 3.31)

project(Sequences VERSION 1.0.0 LANGUAGES CXX)

#Require C++23
set(CMAKE_CXX_STANDARD_REQUIRED ON) #Make C++23 a hard requirement
set(CMAKE_CXX_STANDARD 23) # Default C++ standard for targets

# Needed if you want to use a C++20 Module
 set(CMAKE_CXX_SCAN_FOR MODULES ON)

find_package(fmt CONFIG REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_sources(${PROJECT_NAME}
			   PUBLIC
			   FILE_SET CXX_MODULES FILES
			   utilities.ixx
)

target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)
