#include "lists.h"

/**
 * print_listint - Prints all the elements of a listint_t list.
 * @h: A pointer to the head of the linked list.
 * code by Udeme Harrison
 * Return: The number of nodes in the list.
 */

size_t print_listint(const listint_t *h)
{
	size_t count = 0; /* Init counter vrb to keep track of # of nodes in list. */

	while (h != NULL) /* Traverse list until current node is NULL. */
	{
		printf("%d\n", h->n); /* Print the value of the current node. */
		count++; /* Increment the counter for each node encountered. */
		h = h->next; /* Move to the next node in the list. */
	}
	return (count); /* Return the final count of nodes in the list. */
}
