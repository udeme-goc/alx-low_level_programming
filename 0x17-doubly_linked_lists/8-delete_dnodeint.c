#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given index.
 * @head: Pointer to a pointer to the head of the list.
 * @index: Index of the node that should be deleted (starts at 0).
 * Return: 1 if it succeeded, -1 if it failed.
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *temp;
	unsigned int count = 0;

	/* Step 1: Handle the case where the list is empty */
	if (*head == NULL)
		return (-1);

	/* Step 2: If index is 0, update head and free the old head */
	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}

	/* Step 3: Traverse to the node at index - 1 */
	current = *head;
	while (current != NULL && count < index - 1)
	{
		current = current->next;
		count++;
	}

	/* Step 4: If index is greater than the current node count, return -1 */
	if (current == NULL || current->next == NULL || count < index - 1)
return -1;

	/* Step 5: Update pointers to skip the node at the specified index */
	temp = current->next;
	current->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = current;
	free(temp);
    
return (1);
}

