#include "lists.h"

/**
 * print_dlistint - Prints all elements of a doubly linked list.
 * @h: Pointer to the head of the doubly linked list.
 * Return: The number of nodes in the list.
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	/* Step 1: Initialize a variable to keep track of the node count */
	while (h != NULL)
	{
		/* Step 2: Print the value of the current node */
		printf("%d\n", h->n);

		/* Step 3: Move to the next node */
		h = h->next;

		/* Step 4: Increment the node count */
		count++;
	}

	/* Step 5: Return the total number of nodes */
	return (count);
}
