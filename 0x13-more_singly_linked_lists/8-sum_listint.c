#include "lists.h"

/**
 * sum_listint - returns the sum of all the data (n) of a listint_t linked list
 * @head: pointer to the head of the list
 * code by Udeme Harrison
 * Return: sum of all the data (n) of the list, or 0 if the list is empty
 */

int sum_listint(listint_t *head)
{
	int sum = 0; /* variable to hold the sum of the data */

	/* traverse the list and add up the data */
	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	/* return the sum */
	return (sum);
}
