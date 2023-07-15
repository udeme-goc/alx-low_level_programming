#include "main.h"

/**
 * error_exit - Prints an error message and exits with a specific code.
 * @code: The exit code.
 * @message: The error message to print.
 *
 * Description: This function prints the error message to stderr and exits
 *              the program with the given exit code.
 */

void error_exit(int code, char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(code);
}


/**
 * print_header_field - Prints a specific field of the ELF header.
 * @field: The field value to print.
 * @format: The format string for printing the field.
 *
 * Description: This function prints a specific field of the ELF header
 *              with the given format string.
 */
void print_header_field(void *field, char *format)
{
	printf(format, *((unsigned int *)field));
}


/**
 * print_header_string - Prints a string field of the ELF header.
 * @field: The field value to print.
 *
 * Description: This function prints a string field of the ELF header.
 */

void print_header_string(char *field)
{
	printf("  %s: %s\n", field, field + sizeof(unsigned int));
}


/**
 * read_elf_header - Reads and prints the ELF header of the given file.
 * @filename: The name of the file to read.
 *
 * Description: This function reads and prints the ELF header of the
 *              specified file.
 */

void read_elf_header(char *filename)
{
	int fd;
	Elf64_Ehdr header;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit(98, "Error: Cannot open file");

	if (read(fd, &header, sizeof(header)) != sizeof(header))
		error_exit(98, "Error: Cannot read from file");

	close(fd);

	printf("ELF Header:\n");
	print_header_field(header.e_ident, "  Magic:   %02x %02x %02x %02x %02x	"
			" %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n");
	print_header_string(header.e_ident + EI_CLASS);
	print_header_string(header.e_ident + EI_DATA);
	print_header_field(&header.e_ident[EI_VERSION], "  Version: %d (current)\n");
	print_header_string(header.e_ident + EI_OSABI);
	printf("  ABI Version: %d\n", header.e_ident[EI_ABIVERSION]);
	print_header_field(&header.e_type, "  Type:    %d\n");
	print_header_field(&header.e_entry, "  Entry point address: 0x%lx\n");
}


/**
 * main - Displays the information contained in the ELF header of an ELF file.
 * @argc: The number of arguments.
 * @argv: The arguments array.
 *
 * Return: 0 on success.
 *
 * Description: This is the main function that reads the name of an ELF file
 *              from the command line and displays the information contained
 *              in the ELF header of the file.
 */

int main(int argc, char **argv)
{
	if (argc != 2)
		error_exit(97, "Usage: elf_header elf_filename");

	read_elf_header(argv[1]);

	return (0);
}
