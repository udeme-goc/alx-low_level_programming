#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list
 * @head: pointer to the head of the list
 * @index: index of the node to return, starting at 0
 * code by Udeme Harrison
 * Return: pointer to nth node of list, or NULL if node does not exist
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current = head; /* pointer to traverse the list */
	unsigned int count = 0; /* index of the current node */

	/* traverse list until index reached or end of list is reached */
	while (current != NULL && count < index)
	{
		current = current->next;
		count++;
	}

	/* if the index is >= number of nodes in the list, return NULL */
	if (current == NULL)
		return (NULL);

	/* otherwise, return a pointer to the node at the given index */
	return (current);
}
