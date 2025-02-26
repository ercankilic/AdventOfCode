cmake_minimum_required(VERSION 3.28)

# Set the project name
project(AoC VERSION 1.0 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add compiler options
add_compile_options("")

# Source files
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/main.cpp")
file(GLOB_RECURSE DAYS_LIB "${CMAKE_SOURCE_DIR}/src/**/*.cpp")

#Add the library
add_library(Days ${DAYS_LIB})

# Add the executable
add_executable(AoC ${SOURCES})

# Include directories (if any)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Link directories (add your link directories here)
link_directories(${CMAKE_BINARY_DIR}/**)

# Link libraries (if any)
target_link_libraries(AoC PRIVATE Days)

add_custom_target(copy-inputs ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/inputs/ ${CMAKE_BINARY_DIR}/inputs/
)
