#include "lists.h"

/**
 * sum_dlistint - Returns the sum of all data (n) in a doubly linked list.
 * @head: Pointer to the head of the list.
 * Return: Sum of all data in the list, or 0 if the list is empty.
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *current = head;

	/* Traverse the list and accumulate the sum of data values */
	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}

