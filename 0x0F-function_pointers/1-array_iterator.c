#include "function_pointers.h"

/**
 * array_iterator - Executes a function on each element of an array.
 *
 * @array: The array to be iterated over.
 * @size: The size of the array.
 * @action: A pointer to the function to be executed.
 *
 * Return: Nothing.
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;  /* Declare a variable for iteration. */

	/* Check if array and action are not NULL to avoid segmentation faults. */
	if (array != NULL && action != NULL)
	{
		/* Iterate over each element of the array. */
		for (i = 0; i < size; i++)
		{
			/* Call the action function on the current element. */
			(*action)(array[i]);
		}
	}
}
