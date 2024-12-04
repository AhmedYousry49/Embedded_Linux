cmake_minimum_required(VERSION 3.5)

# Define the library
project(binary_search)

# Include the header files
include_directories(include)

# Add source files for the library
set(SOURCE_FILES src/binary_search.cpp)

# Create a static library
add_library(binary_search STATIC ${SOURCE_FILES})