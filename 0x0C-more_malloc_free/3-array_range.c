#include "main.h"

/**
 * array_range - create an array of integers from min to max
 * @min: the minimum value (inclusive)
 * @max: the maximum value (inclusive)
 * code by Udeme Harrison
 * Return: a pointer to the newly created array, or NULL if an error occurs
 */

int *array_range(int min, int max)
{
	int *arr, i;

	if (min > max)
		return (NULL);

	/* allocate memory for the array */
	arr = malloc(sizeof(int) * (max - min + 1));

	if (arr == NULL)
		return (NULL);

	/* initialize the array */
	for (i = 0; min <= max; i++, min++)
	arr[i] = min;

	return (arr);
}
