#include "lists.h"

/**
 * listint_len - Returns the number of elements in a linked listint_t list.
 * @h: Pointer to the head of the linked list.
 * code by Udeme Harrison
 * Return: The number of elements in the linked list.
 */

size_t listint_len(const listint_t *h)
{
	/* Initialize a count variable to 0. */
	size_t count = 0;

	/* Loop through the linked list until the end is reached. */
	while (h != NULL)
	{
		/* Increment the count for each element in the list. */
		count++;
		/* Move to the next element in the list. */
		h = h->next;
	}

	/* Return the total number of elements in the list. */
	return (count);
}
