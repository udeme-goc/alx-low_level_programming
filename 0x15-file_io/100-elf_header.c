#include "main.h"

/**
 * error_exit - Prints an error message and exits with a specific code.
 * @code: The exit code.
 * @message: The error message to print.
 */

void error_exit(int code, char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(code);
}


/**
 * print_magic - Prints the ELF magic numbers.
 * @magic: The magic numbers array.
 */

void print_magic(unsigned char *magic)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < 16; i++)
		printf("%02x ", magic[i]);
		printf("\n");
}


/**
 * print_class - Prints the ELF class.
 * @class: The ELF class.
 */

void print_class(unsigned char class)
{
	printf("  Class:                             ");
	switch (class)
	{
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown>\n");
			break;
	}
}


/**
 * print_data - Prints the ELF data encoding.
 * @data: The ELF data encoding.
 */

void print_data(unsigned char data)
{
	printf("  Data:                              ");
	switch (data)
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown>\n");
			break;
	}
}


/**
 * print_version - Prints the ELF version.
 * @version: The ELF version.
 */

void print_version(unsigned char version)
{
	printf("  Version:                           %d (current)\n", version);
}


/**
 * print_osabi - Prints the ELF OS/ABI.
 * @osabi: The ELF OS/ABI.
 */

void print_osabi(unsigned char osabi)
{
	printf("  OS/ABI:                            ");
	switch (osabi)
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("TRU64 UNIX\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM architecture\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone (embedded) application\n");
			break;
		default:
			printf("<unknown>\n");
			break;
	}
}


/**
 * print_type - Prints the ELF file type.
 * @type: The ELF file type.
 */

void print_type(unsigned int type)
{
	printf("  Type:                              ");
	switch (type)
	{
		case ET_NONE:
			printf("NONE (Unknown type)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown>\n");
			break;
	}
}


/**
 * print_entry - Prints the ELF entry point address.
 * @entry: The ELF entry point address.
 */

void print_entry(unsigned long int entry)
{
	printf("  Entry point address:               0x%lx\n", entry);
}


/**
 * read_elf_header - Reads the ELF header of the given file.
 * @filename: The name of the file to read.
 */

void read_elf_header(char *filename)
{
	int fd, bytes_read;
	Elf64_Ehdr header;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit(98, "Error: Cannot open file");

	bytes_read = read(fd, &header, sizeof(header));
	if (bytes_read == -1 || bytes_read != sizeof(header))
		error_exit(98, "Error: Cannot read from file");

	close(fd);

	printf("ELF Header:\n");
	print_magic(header.e_ident);
	print_class(header.e_ident[EI_CLASS]);
	print_data(header.e_ident[EI_DATA]);
	print_version(header.e_ident[EI_VERSION]);
	print_osabi(header.e_ident[EI_OSABI]);
	printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
	print_type(header.e_type);
	print_entry(header.e_entry);
}


/**
 * main - Displays the information contained in the ELF header of an ELF file.
 * @argc: The number of arguments.
 * @argv: The arguments array.
 *
 * Return: 0 on success.
 */

int main(int argc, char **argv)
{
	if (argc != 2)
		error_exit(97, "Usage: elf_header elf_filename");

	read_elf_header(argv[1]);

	return (0);
}

