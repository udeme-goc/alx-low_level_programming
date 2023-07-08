#include "lists.h"

/**
 * list_len - returns the number of elements in a linked list_t list
 * @h: a pointer to the head of the linked list
 * code by Udeme Harrison
 * Return: the number of elements in the linked list
 */

size_t list_len(const list_t *h)
{
	size_t count = 0; /* Init counter vrb to keep track of # of nodes in list */

	while (h != NULL) /* Traverse the list until current node is NULL). */
	{
		count++; /* Increment the counter for each node encountered. */
		h = h->next; /* Move to the next node in the list. */
	}
	return (count); /* Return the final count of nodes in the list. */
}
