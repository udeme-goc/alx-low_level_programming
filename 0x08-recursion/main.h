#ifndef MAIN_H
#define MAIN_H

/* Function prototypes */
int _putchar(char c);
int _isupper(int c);
int _isdigit(int c);
int _strlen(char *s);
void _puts(char *s);
void _print_rev(char *s);
int _atoi(char *s);
int _isalpha(int c);
int _abs(int n);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept);
char *_strstr(char *haystack, char *needle);

/* Standard libraries */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#endif /* MAIN_H */
