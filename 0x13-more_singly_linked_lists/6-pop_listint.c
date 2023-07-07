#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 *               and returns the head node's data (n)
 * @head: pointer to pointer to the head of the list
 * code by Udeme Harrison
 * This function removes the head node of a linked list of integers
 * and returns the data stored in the removed node.
 *
 * Return: the data stored in the removed head node, or 0 if the list is empty.
 */

int pop_listint(listint_t **head)
{
	listint_t *temp; /* Temporary pointer */
	int n; /* Variable to hold head node's data */

	/* Check if head pointer is NULL */
	if (head == NULL || *head == NULL)
		return (0);

	/* Save head node's data */
	n = (*head)->n;

	/* Update head pointer to point to next node */
	temp = (*head)->next;

	/* Free memory allocated for old head node */
	free(*head);
	*head = temp;

	/* Return head node's data */
	return (n);
}
