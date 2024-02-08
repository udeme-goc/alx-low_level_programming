#include <stdio.h>
#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in a sorted array of integers
 *			using the Interpolation search algorithm
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the value if found, otherwise -1
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t low = 0, high = size - 1;
	size_t pos;

	if (array == NULL) /* Check if the array is NULL */
		return (-1); /* If so, return -1 indicating value not found */

	while (low <= high && value >= array[low] && value <= array[high])
	{
		/* Calculate the probe position */
		pos = low + (((double)(high - low) / (array[high] - array[low])) *
				(value - array[low]));
		if (pos >= size)	/* Check if pos is out of range */
		{
			printf("Value checked array[%lu] is out of range\n", pos);
			return (-1);	/* Value not found */
		}

		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);
		/* Print the value being checked */

		if (array[pos] == value) /* If the value is found */
			return (pos);	/* Return its index */

		if (array[pos] < value) /* If value is greater than probe value */
			low = pos + 1;	/* Move low boudary to right of probe */
		else /* If the value is smaller than the probe value */
			high = pos - 1;	/* Move high boundary to left of probe */		
	}
	/* Indicate the value is out of range */
	printf("Value checked array[%lu] is out of range\n", pos);
	return (-1);	/*return -1 as the values is not found */
}
