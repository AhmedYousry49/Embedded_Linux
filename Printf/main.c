#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * @brief A simplified version of printf using vsprintf and write.
 *
 * This function mimics the behavior of printf by formatting a string using 
 * vsprintf and then printing the result to standard output using the write 
 * system call (low-level I/O).
 * 
 * @param format The format string, which can include format specifiers like %d, %c, and %s.
 * @param    The variable arguments to be formatted as per the format string  ... .
 * 
 * @return the lenth os string the was printed
 */
int my_printf(const char *format, ...) {
    char buffer[1024];  ///< A buffer to store the formatted string
    va_list args;       ///< Variable argument list for the format string

    va_start(args, format);

    // Use vsprintf to format the string and write the result to stdout
   int lenth= write(1, buffer, vsprintf(buffer, format, args));  ///< Write the formatted string to stdout

    va_end(args);
    return lenth;
}

/**
 * @brief Main function to test my_printf.
 * 
 * The main function demonstrates the usage of the simplified printf function
 * by passing various format specifiers and printing the result.
 * 
 * @return Returns 0 upon successful execution.
 */
int main() {

    int num = 42;            ///< Integer to be printed
    char character = 'A';    ///< Character to be printed
    char *str = "Hello, World!";  ///< String to be printed

    // Test the my_printf function
    my_printf("Integer: %d\n", num);         ///< Print an integer
    my_printf("Character: %c\n", character); ///< Print a character
    my_printf("String: %s\n", str);         ///< Print a string

    return 0; ///< Return 0 to indicate successful execution
}