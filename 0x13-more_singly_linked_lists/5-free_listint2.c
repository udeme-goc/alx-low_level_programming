#include "lists.h"

/**
 * free_listint2 - frees a listint_t list and sets the head to NULL
 * @head: pointer to pointer to the head of the list
 * code by Udeme Harrison
 * Function frees a linked list of integers and sets head pointer to NULL.
 */

void free_listint2(listint_t **head)
{
	listint_t *current;

	/* Check if head pointer is NULL */
	if (head == NULL)
	return;

	/* Iterate through the list and free each node */
	while (*head != NULL)
	{
		current = *head; /* Save current head node */
		*head = (*head)->next; /* Update head pointer to point to next node */
		free(current); /* Free current node */
	}

	/* Set head pointer to NULL to indicate list is empty */
	*head = NULL;
}
