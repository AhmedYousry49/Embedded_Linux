# cmake_minimum_required(VERSION 3.5)

# # Define the project
# project(binarysearch)
# set(CMAKE_CXX_COMPILER ${CPP_COMPILER})
# set(CMAKE_C_COMPILER ${C_COMPILER})
# # Add subdirectory for the "remainder" library
# add_subdirectory(lib/binary_search)

# # Include the library headers
# include_directories(lib/binary_search/include)

# # Add the main source file
# set(SOURCE_FILES src/main.cpp)

# # Create an executable for the main application
# add_executable(main_app ${SOURCE_FILES})

# # Link the "remainder" library to the executable
# target_link_libraries(main_app binary_search)

# Specify the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Set the project name


project(BinarySearchProject)
add_subdirectory(lib/binary_search)

include_directories(lib/binary_search/include)

# Define the source files
set(SOURCE_FILES src/main.cpp)

# Add the executable
add_executable(BinarySearchApp ${SOURCE_FILES})

target_link_libraries(BinarySearchApp binary_search)