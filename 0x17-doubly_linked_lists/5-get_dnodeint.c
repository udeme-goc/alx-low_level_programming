#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list.
 * @head: Pointer to the head of the list.
 * @index: Index of the node (starting from 0).
 * Return: Pointer to the nth node, or NULL if the node does not exist.
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current = head; /* Declare and init pointer to traverse list */
	unsigned int count = 0; /* Init counter to keep track of current index */

	while (current != NULL)
	{
		if (count == index) /* Check if current index matches desired index */
			return (current); /* Return current node if index matches */
		current = current->next; /* Move to the next node */
		count++; /* Increment index counter */
	}

	return (NULL); /* Return Null if the desired index is not found */
}
