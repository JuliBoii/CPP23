CMAKE_MINIMUM_REQUIRED(VERSION 3.31)

PROJECT(FUNCTIONS VERSION 1.0 LANGUAGES CXX)

# Require C++23
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_STANDARD 23)
SET(CMAKE_CXX_SCAN_FOR_MODULES ON)

#FIND_PACKAGE(SFML COMPONENTS Network Graphics Window Audio System CONFIG REQUIRED)
FIND_PACKAGE(FMT CONFIG REQUIRED)

ADD_EXECUTABLE(${PROJECT_NAME} main.cpp functions_implementation.cpp function_parameters.cpp)

TARGET_SOURCES(${PROJECT_NAME}
        PUBLIC
        FILE_SET CXX_MODULES FILES
        utilities.ixx
        example_functions.ixx
        functions_interface.ixx
        function_parameters.ixx
)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} PRIVATE fmt::fmt)