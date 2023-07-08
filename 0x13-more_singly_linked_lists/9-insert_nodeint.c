#include "lists.h"

/**
 * insert_nodeint_at_index - inserts new node at given positn in listint_t list
 * @head: pointer to the pointer to the head of the list
 * @idx: index of the list where the new node should be added (starting from 0)
 * @n: integer data to be stored in the new node
 * code by Udeme Harrison
 * Return: address of the new node, or NULL if it failed to add the node
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node; /* pointer to the new node */
	listint_t *current_node; /* pointer to the current node */
	unsigned int i;

	if (head == NULL)
		return (NULL);

	/* create a new node */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;

	/* insert the new node at the given position */
	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	current_node = *head;
	for (i = 0; i < idx - 1; i++)
	{
		if (current_node == NULL)
		{
			free(new_node);
			return (NULL);
		}
		current_node = current_node->next;
	}
	if (current_node == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = current_node->next;
	current_node->next = new_node;

	return (new_node);
}
