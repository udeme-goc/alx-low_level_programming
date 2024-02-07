#include <stdio.h>
#include "search_algos.h"

/**
 * linear_search - Searches for a value in an array of integers
 *		using linear search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the value, if found, otherwise -1
 */

int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL) /* Check if the array is NULL */
		return (-1); /* If so, return -1 indicating value not found */

	for (i = 0; i < size; i++) /* Loop through each element of the array */
	{
		 /* Print the value being checked */
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);

		/* If value found, return its index */
		if (array[i] == value)
			return (i);
	}

	return (-1); /* If the value is not found in the array, return -1 */
}
