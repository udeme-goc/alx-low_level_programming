#include "lists.h"

/**
 * free_dlistint - Frees a doubly linked list.
 * @head: Pointer to the head of the list to be freed.
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *current, *temp;

	current = head;

	/* Traverse the list and free each node */
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}
