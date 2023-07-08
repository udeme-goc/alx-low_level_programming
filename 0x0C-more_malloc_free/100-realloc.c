#include "main.h"

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: Pointer to the memory previously allocated
 * @old_size: The size, in bytes, of the allocated space for ptr
 * @new_size: The new size, in bytes, of the new memory block
 * code by Udeme Harrison
 * Return: Pointer to the reallocated memory block
 *         NULL if new_size = 0 and ptr is not NULL
 *         NULL if memory allocation fails
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr, *old_ptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
		return (new_ptr);
	}

	old_ptr = ptr;
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	/* Copy the minimum of old_size and new_size bytes */
	for (i = 0; i < old_size && i < new_size; i++)
		new_ptr[i] = old_ptr[i];

	free(ptr);

	return (new_ptr);
}
