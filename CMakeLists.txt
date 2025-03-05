cmake_minimum_required(VERSION 3.28)

# Set the project name
project(AoC VERSION 1.0 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Input file options to choose which one is used
option(REAL "Use real input or test" OFF)

# Add compiler options
add_compile_options("")
add_subdirectory(2024)
