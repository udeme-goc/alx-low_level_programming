#include "main.h"
/**
 * _islower - check if character is lower case
 * @c: char to be checked
 * code by Udeme Harrison
 * Return: 1 if char is lowercase, otherwise 0
*/

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
