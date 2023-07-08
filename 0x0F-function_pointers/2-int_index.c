#include "function_pointers.h"

/**
 * int_index - Searches for an integer in an array.
 *
 * @array: The array to search.
 * @size: The number of elements in the array.
 * @cmp: A pointer to the function to be used to compare values.
 *
 * Return: The index of the first element for which the cmp function
 *	does not return 0. If no element matches, return -1.
 *	If size <= 0, return -1.
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;  /* Declare a variable for iteration. */

	/* Check if array, cmp and size are valid. */
	if (array != NULL && cmp != NULL && size > 0)
	{
		/* Iterate over each element of the array. */
		for (i = 0; i < size; i++)
		{
			/* Call the cmp function on the current element. */
			if ((*cmp)(array[i]) != 0)
				return (i);
		}
	}

	return (-1);
}

