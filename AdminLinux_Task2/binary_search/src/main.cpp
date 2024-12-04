#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::sort
#include "binary_search.h"
int main(int argc, char *argv[])
{
       if (argc < 2) {
        std::cout << "Please provide a target argument." << std::endl;
        return 1;
    }
    std::string target = argv[1]; 
    std::vector<std::string> arguments(argv+2, argv + argc);
     int index = BinarySearch(arguments, 0, argc-3 , target);
    // Output result
    if (index != -1)
        std::cout << "Element '" << target << "' found at index: " << index << std::endl;
    else
        std::cout << "Element '" << target << "' not found." << std::endl;

    return 0;
}