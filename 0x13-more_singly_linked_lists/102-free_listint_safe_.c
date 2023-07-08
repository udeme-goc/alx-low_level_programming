#include "lists.h"

/**
 * free_listint_safe - frees a listint_t linked list
 * @h: double pointer to the head of the linked list
 *
 * Return: the size of the list that was freed
 */

size_t free_listint_safe(listint_t **h)
{
	listint_t *current, *tmp;
	size_t count = 0;

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;
	while (current != NULL)
	{
		/* Check if current node has already been freed */
		if (current < current->next)
		{
			/* Free current node and update count */
			tmp = current;
			current = current->next;
			free(tmp);
			count++;
		}
		else
		{
			/* We have encountered a cycle, set head to NULL and exit */
			*h = NULL;
			exit(98);
		}
	}

	/* Set head to NULL and return count */
	*h = NULL;
	return (count);
}
