#include <stdio.h>
#include "search_algos.h"

/**
 * exponential_search - Searches for a value in a sorted array of integers
 *                       using the Exponential search algorithm
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the value if found, otherwise -1
 */

int exponential_search(int *array, size_t size, int value)
{
    size_t bound = 1;
    size_t prev_bound = 0;
    int result;

    if (array == NULL || size == 0) /* Check if the array is NULL or empty */
        return (-1); /* If so, return -1 indicating value not found */

    while (bound < size && array[bound] < value)
    {
	/* Print the value being checked */
        printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
        prev_bound = bound; /* Store the previous bound */
        bound *= 2; /* Double the bound for the next iteration */
    }

    if (bound >= size) /* If the bound exceeds the array size */
        bound = size - 1; /* Set the bound to the last index */

    /* Indicate the range */
    printf("Value found between indexes [%lu] and [%lu]\n", prev_bound, bound);

     /* Perform binary search within the identified range */
     result = binary_search(array, prev_bound, bound, value);

    return (result); /* Return the result */
}


/**
 * binary_search - Searches for a value in a sorted array of integers
 *                 using the Binary search algorithm
 * @array: Pointer to the first element of the array
 * @start: Starting index of the range to search in
 * @end: Ending index of the range to search in
 * @value: Value to search for
 *
 * Return: Index of the value if found, otherwise -1
 */

int binary_search(int *array, size_t start, size_t end, int value)
{
    size_t mid;

    while (start <= end)
    {
        mid = (start + end) / 2;
        /* Print the current subarray being searched */
	printf("Searching in array: ");

        for (size_t i = start; i < end; i++)
            printf("%d, ", array[i]);
        printf("%d\n", array[end]);

        if (array[mid] == value) /* If the value is found */
            return (mid); /* Return its index */

        if (array[mid] < value) /* If the value is greater than the mid element */
            start = mid + 1; /* Move the start index to the right */
        else /* If the value is smaller than the mid element */
            end = mid - 1; /* Move the end index to the left */
    }

    return (-1); /* Return -1 indicating value not found */
}
