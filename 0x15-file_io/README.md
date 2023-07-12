# 0x15. C - File I/O

This project contains various tasks related to file I/O in the C programming language. The tasks focus on handling file descriptors, permissions, and manipulating file contents.

## Author

Udeme Harrison

GitHub: [udeme-goc](https://github.com/udeme-goc)

## Project Details

The project consists of the following tasks:

1. [Read a Text File](./0-read_textfile.c): Implement a function that reads a text file and prints its content to the standard output.

2. [Create a File](./1-create_file.c): Implement a function that creates a file with the given name and writes the provided text content to it.

3. [Append Text to File](./2-append_text_to_file.c): Implement a function that appends text to the end of a file.

4. [Copy File](./3-cp.c): Create a program that copies the content of one file to another file.

5. [ELF Header](./100-elf_header.c): Develop a program that displays the information contained in the ELF header at the start of an ELF file.

## Compilation and Usage

To compile the C files, use the following command:

gcc -Wall -Werror -Wextra -pedantic -std=c99 -o <output_file> <source_file>

Replace `<output_file>` with the desired name for the executable and `<source_file>` with the name of the C file to compile.

To execute the compiled programs, use the following command:

./<executable> <arguments>

Replace `<executable>` with the name of the compiled program and `<arguments>` with the required arguments for each task.

Make sure to compile each task separately, providing the correct source file and output file name.

## File Descriptions

* `0-read_textfile.c`: Contains the implementation of the `read_textfile` function.

* `1-create_file.c`: Contains the implementation of the `create_file` function.

* `2-append_text_to_file.c`: Contains the implementation of the `append_text_to_file` function.

* `3-cp.c`: Contains the implementation of the `cp` program.

* `100-elf_header.c`: Contains the implementation of the `elf_header` program.

* `main.h`: Header file containing function prototypes and necessary library includes.

## Requirements

* The programs and functions were implemented in C.

* The code follows the Betty coding style.

* The only C standard library functions allowed are `malloc`, `free`, and `exit`. No other standard library functions should be used.

* The only system calls allowed are `read`, `write`, `open`, and `close`.

* The program should not use global variables.

* Each function should have no more than 25 lines.

* The programs should compile without any warnings or errors using the specified compilation flags.

* The programs should run without any issues and produce the expected output.

## License

This project is licensed under the MIT License.

