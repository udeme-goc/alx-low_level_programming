#include "main.h"

/**
 * malloc_checked - allocate memory using malloc
 * @b: size of memory to allocate
 * code by Udeme Harrison
 * Return: pointer to the allocated memory
 *         exit with a status value of 98 if malloc fails
 */

void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b); /* allocate memory */

	if (ptr == NULL) /* if malloc fails */
		exit(98); /* exit with a status value of 98 */

	return (ptr);
}
