#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list
 * @head: A pointer to the head node of the list
 * code by Udeme Harrison
 * Return: A pointer to the first node of the reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *next = NULL;

	/* Check if the head pointer is NULL or the list is empty */
	if (!head || !*head)
		return (NULL);

	while (*head)
	{
		/* Store the next node in a temporary pointer */
		next = (*head)->next;

		/* Reverse link between current node and previous */
		(*head)->next = prev;

		/* Move the pointers forward */
		prev = *head;
		*head = next;
	}

	/* Update head pointer to point to first node of the reversed list */
	*head = prev;

	/* Return a pointer to the first node of the reversed list */
	return (*head);
}
