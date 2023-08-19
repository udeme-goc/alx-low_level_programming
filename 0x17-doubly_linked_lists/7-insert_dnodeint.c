#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position.
 * @h: Pointer to a pointer to the head of the list.
 * @idx: Index of the list where the new node should be added (starts at 0).
 * @n: Value to be assigned to the new node.
 * Return: Address of the new element, or NULL if it failed.
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *current = *h;
	unsigned int count = 0;

	/* Step 1: Find the node at index idx - 1 */
	while (current != NULL && count < idx - 1)
	{
		current = current->next;
		count++;
	}

	/* Step 2: If the index is greater than the current node count, return NULL */
	if (current == NULL && count < idx - 1)
		return (NULL);

	/* Step 3: Allocate memory for the new node */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	/* Step 4: Initialize the new node */
	new_node->n = n;

	/* Step 5: Update pointers to insert the new node at the specified position */
	new_node->next = (current == NULL) ? NULL : current->next;
	if (current != NULL)
		current->next = new_node;
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
	new_node->prev = (current == NULL) ? NULL : current;

	/* Step 6: If the new node was inserted at the beginning, update the head */
	if (current == *h && count == idx - 1)
		*h = new_node;

	/* Step 7: Return the address of the new node */
	return (new_node);
}
