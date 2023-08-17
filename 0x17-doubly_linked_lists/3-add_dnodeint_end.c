#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a doubly linked list.
 * @head: Pointer to a pointer to the head of the list.
 * @n: Value to be assigned to the new node.
 * Return: Address of the new element, or NULL if it failed.
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *current;

	/* Step 1: Allocate memory for the new node */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	/* Step 2: Initialize the new node */
	new_node->n = n;
	new_node->next = NULL;

	/* Step 3: If the list is empty, set the new node as the head */
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	/* Step 4: Traverse to the end of the list */
	current = *head;
	while (current->next != NULL)
		current = current->next;

	/* Step 5: Update pointers to add the new node to the end */
	current->next = new_node;
	new_node->prev = current;

	/* Step 6: Return the address of the new node */
	return (new_node);
}

