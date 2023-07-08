#include "main.h"

/**
 * _isalpha - check if char is alphabet
 * @c: char to be checked
 * code by Udeme Harrison
 * Return: 1 if char is lower or uppercase and otherwise 0
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
