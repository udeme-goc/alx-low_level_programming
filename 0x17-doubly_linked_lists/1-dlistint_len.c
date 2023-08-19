#include "lists.h"

/**
 * dlistint_len - Returns the number of elements in a linked dlistint_t list.
 * @h: Pointer to the head of the list.
 * Return: The number of elements in the list.
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;       /* Initialize a counter to keep track of the number of elements */

	while (h != NULL)
	{
		count++;            /* Increment the counter for each node */
		h = h->next;        /* Move to the next node */
	}

	return (count);           /* Return the total number of elements */
}
