#include "3-calc.h"

/**
 * int_index - Searches for an integer in an array.
 *
 * @array: The array to search in.
 * @size: The number of elements in the array.
 * @cmp: The function to be used to compare values.
 *
 * Return: The index of the first element for which the cmp function does not
 *         return 0. If no element matches, return -1. If size <= 0, return -1.
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;  /* declare a counter variable */

	/* check if array and cmp function pointers are not NULL */
	if (array == NULL || cmp == NULL)
		return (-1);

	/* check if size is greater than 0 */
	if (size <= 0)
		return (-1);

	/* loop through the array */
	for (i = 0; i < size; i++)
	{
		/* apply the cmp function to each element */
		if (cmp(array[i]) != 0)
			/* if function does not return 0, return the index */
			return (i);
	}

	/* if no element matches, return -1 */
	return (-1);
}
