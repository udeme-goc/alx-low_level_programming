#include "lists.h"

/**
 * free_listint_safe - frees a linked list
 * @h: pointer to the first node in the linked list
 * adapted by Udeme Harrison
 * Return: number of elements in the freed list
 */

size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	int diff;
	listint_t *tmp;

	/* check for NULL or empty list */
	if (!h || !*h)
		return (0);

	/* traverse the list */
	while (*h)
	{
		diff = *h - (*h)->next;

		/* if there's a loop in the list, free one node at a time */
		if (diff > 0)
		{
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
			count++;
		}
		/* if there's no loop, free the whole list at once and break the loop */
		else
		{
			free(*h);
			*h = NULL;
			count++;
			break;
		}
	}

	/* set the head pointer to NULL */
	*h = NULL;

	return (count);
}
