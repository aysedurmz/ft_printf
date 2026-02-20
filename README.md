*This project has been created as part of the 42 curriculum by aysdurma*

## Description
The `ft_printf` project aims to recreate the standard C library's `printf` function. The primary goal of this exercise is to discover how variadic functions work in C by managing a variable number of arguments. It provides hands-on experience with the `<stdarg.h>` library macros, string parsing, and structured code organization.



## Instructions

### Compilation
To compile the library, run: `make`

This will generate `libftprintf.a`.

### Usage
Include the header in your C file: `#include "ft_printf.h"`
```c
int main(void)
{
    ft_printf("Hello %s, number: %d\n", "World", 42);
    return (0);
}
```
Compile your program with the library: `cc main.c libftprintf.a`



## Resources
1. **Man pages**
2. **AI**: Used for generating and formatting this README, as well as for assisting in testing the implemented functions.



## Features
Supported conversions:
- `%c`: Prints a single character.
- `%s`: Prints a string.
- `%p`: The void * pointer argument has to be printed in hexadecimal format.
- `%d`: Prints a decimal (base 10) number.
- `%i`: Prints an integer in base 10.
- `%u`: Prints an unsigned decimal (base 10) number.
- `%x`: Prints a number in hexadecimal (base 16) lowercase format.
- `%X`: Prints a number in hexadecimal (base 16) uppercase format.
- `%%`: Prints a percent sign.




## Algorithm and Data Structure
**Data Structure**: No complex data structures (like arrays or linked lists) were needed for this project. The only necessary tool is `va_list` from the `<stdarg.h>` library, which allows processing an unknown amount of arguments safely.

**Algorithm**: The algorithm simply loops through the given string character by character. If it reads a normal character, it prints it directly. When it encounters a `%` symbol, it checks the next character to figure out the data type (e.g., `s` for string, `d` for number) and calls the matching helper function to convert and print that specific data. Number conversions (such as printing integers or hexadecimals) are handled simply using a recursive division method.