# 0x18. C - Dynamic Libraries

This project focuses on the creation and usage of dynamic libraries in C programming. Dynamic libraries allow you to separate code into reusable modules that can be loaded into memory at runtime, enhancing modularity and efficiency in programs.

## Requirements

- Allowed editors: vi, vim, emacs
- Compiled on Ubuntu 20.04 LTS using gcc with options -Wall -Werror -Wextra -pedantic -std=gnu89
- All files must end with a new line
- A `README.md` file at the root of the project is mandatory
- Code must follow the Betty style
- No global variables are allowed
- Each file should contain no more than 5 functions
- Standard library functions like printf, puts, etc., are forbidden; only `_putchar` can be used
- Prototypes of functions and the `_putchar` function must be included in `main.h`
- Do not push `_putchar.c`

## Files

- `main.h`: Header file containing function prototypes.
- `_putchar.c`: Provided `_putchar` function.
- Other `.c` files: Implementation of various functions required by the project.
- `1-create_dynamic_lib.sh`: Script to create a dynamic library from all `.c` files in the current directory.

## Compilation and Usage

To compile your C files into a dynamic library:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -shared -o libdynamic.so *.c
To use the created dynamic library in your C programs:

gcc -o your_program your_program.c -L. -ldynamic
Make sure to set the LD_LIBRARY_PATH before running your program:

export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
./your_program

## Author
Udeme Harrison
GitHub: udeme-goc
