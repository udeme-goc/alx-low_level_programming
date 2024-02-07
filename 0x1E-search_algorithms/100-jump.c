#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array of integers
 *		using the Jump search algorithm
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the value if found, otherwise -1
 */

int jump_search(int *array, size_t size, int value)
{
	size_t step = sqrt(size);	/* Jump step: square root of the size */
	size_t prev = 0, curr = 0;	/* Previous and current indices */

	/* Check if the array is NULL */
	if (array == NULL)
		return (-1);	/* Value not found */

	printf("Value checked array[%lu] = [%d]\n", curr, array[curr]);

	/* Perform the jump search */
	while (array[curr] < value && curr < size)
	{
		prev = curr;	/* Update the previous index */
		curr += step;	/* Move to the next block */
		if (curr >= size) /* Check if index exceeds the size */
			break;	/* Exit the loop */
		printf("Value checked array[%lu] = [%d]\n", curr, array[curr]);
	}

	printf("Value found between indexes [%lu] and [%lu]\n", prev, curr);

	/* Perform a linear search within the identified block */
	while (array[prev] < value && prev < size)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		prev++;	/* Move to the next element */
	}

	/* Check if the value is found */
	if (array[prev] == value)
		return (prev);	/* Return its index */

	return (-1);	/* Value not found */
}
