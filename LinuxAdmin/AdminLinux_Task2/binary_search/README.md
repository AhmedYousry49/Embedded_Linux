# Binary Search Application

This project demonstrates a C++ implementation of a binary search algorithm for searching a target string in a list of strings passed as command-line arguments. It utilizes recursion and templates to perform the binary search efficiently.

---

## Features

- **Recursive Binary Search**: A generic, templated binary search function.
- **Command-line Interface**: Accepts a target string and a list of strings via command-line arguments.
- **Sorting**: Automatically sorts the list of strings before performing the search to ensure correctness.

---

## Directory Structure

```
ProjectRoot/
├── CMakeLists.txt    # CMake configuration file
├── src/
│   ├── main.cpp      # Main source file containing the program logic
├── lib/──binary_search/
│           └── binary_search.h # Header file with binary search template function
└── build/            # Build directory (created during compilation)
```

---

## Prerequisites

Ensure you have the following installed:

- A C++ compiler (e.g., `g++`, `clang`)
- CMake (version 3.10 or higher)

---

## Building and Running the Project

Follow these steps to build and run the project:

1. **Clone the repository** (if you haven't already):
   ```bash
   git clone <repository-url>
   cd <repository-name>
   ```

2. **Create a build directory**:
   ```bash
   mkdir build && cd build
   ```

3. **Generate the build files using CMake**:
   ```bash
   cmake ..
   ```

4. **Build the project**:
   ```bash
   cmake --build .
   ```

5. **Run the executable**:
   ```bash
   ./BinarySearchApp target_string string1 string2 string3 ...
   ```

   Where `target_string` is the string you're searching for, and the remaining arguments are the strings in which you want to perform the binary search.

---

## Example Usage

### Example Command:
```bash
./BinarySearchApp cherry apple banana cherry grape kiwi
```

### Expected Output:
If the element is found:
```
Element 'cherry' found at index: 1
```

If the element is not found:
```
Element 'pineapple' not found.
```

---

## Customization

- **Modify the list of strings**: You can pass any list of strings in the command line, and the program will search for the target string.
- **Sorting**: The program automatically sorts the input list to ensure the binary search algorithm works correctly.

---

## License

This project is open-source and available under the [MIT License](LICENSE).

---

## Acknowledgments

Thanks for using this project! If you encounter issues or have suggestions, feel free to submit an issue or a pull request.
