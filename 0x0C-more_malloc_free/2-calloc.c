#include "main.h"

/**
 * _calloc - Allocates memory for an array using malloc and sets it to zero
 *
 * @nmemb: Number of elements in the array
 * @size: Size of each element in bytes
 * code by Udeme Harrison
 * Return: Pointer to the allocated memory or NULL if failed
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int i;
	char *mem;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);

	/* Cast ptr as char pointer */
	mem = ptr;

	/* Set each byte to 0 */
	for (i = 0; i < (nmemb * size); i++)
		mem[i] = 0;

	return (ptr);
}
