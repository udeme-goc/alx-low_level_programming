#include "lists.h"

/**
 * delete_nodeint_at_index - deletes node at index of a listint_t linked list
 * @head: pointer to the pointer to the head node of the linked list
 * @index: index of the node to be deleted, starting at 0
 * code by Udeme Harrison
 * Return: 1 if successful, -1 if failed
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *prev;
	unsigned int i;

	/* Check if head pointer is NULL or if list is empty */
	if (!head || !*head)
		return (-1);

	/* If index is 0, delete the head node and return success */
	if (index == 0)
	{
		current = *head;
		*head = (*head)->next;
		free(current);

		return (1);
	}

	/* Traverse the list to find the node at the specified index */
	prev = *head;
	current = (*head)->next;

	for (i = 1; current && i <= index; i++)
	{
		if (i == index)
		{
			/* Update pointers to bypass the node to be deleted */
			prev->next = current->next;
			/* Free memory allocated for the node */
			free(current);
			/* Return success */

			return (1);
		}
		/* Move to the next node */
		prev = current;
		current = current->next;
	}

	/* If node is not found, return failure */
	return (-1);
}
