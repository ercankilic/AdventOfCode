cmake_minimum_required(VERSION 3.28)

# Set the project name
project(AoC24 VERSION 1.0 LANGUAGES CXX)

# Add compiler options
add_compile_options("")

# Source files
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/2024/src/main.cpp")
file(GLOB_RECURSE DAYS_LIB "${CMAKE_SOURCE_DIR}/2024/src/Days/*.cpp")

#Add the library
add_library(Days24 STATIC ${DAYS_LIB})

# Add the executable
add_executable(AoC24 ${SOURCES})

# Include directories (if any)
include_directories(${CMAKE_SOURCE_DIR}/2024/include)

# Link directories (add your link directories here)
link_directories(${CMAKE_BINARY_DIR}/2024/**)

# Link libraries (if any)
target_link_libraries(AoC24 PRIVATE Days24)

if(${REAL}) 
    add_custom_target(copy-inputs ALL
       COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/2024/inputs/real/ ${CMAKE_BINARY_DIR}/2024/inputs/
    )
else()
    add_custom_target(copy-inputs ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/2024/inputs/test/ ${CMAKE_BINARY_DIR}/2024/inputs/
    )
endif()
