#ifndef MAIN_H
#define MAIN_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <elf.h>

/* Function prototypes */
void error_exit(int code, char *message);
void print_magic(unsigned char *magic);
void print_class(unsigned char class);
void print_data(unsigned char data);
void print_version(unsigned char version);
void print_osabi(unsigned char osabi);
void print_type(unsigned int type);
void print_entry(unsigned long int entry);
void read_elf_header(char *filename);
void close_file(int FD);
int create_file(const char *filename, char *text_content);
int _strlen(char *str);
ssize_t read_textfile(const char *filename, size_t letters);
int append_text_to_file(const char *filename, char *text_content);

#define BUF_SIZE 1024

#endif /* MAIN_H */

