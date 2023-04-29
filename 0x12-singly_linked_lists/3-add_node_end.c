#include "lists.h"

/**
 * add_node_end - Adds a new node at the end of a list_t list.
 * @head: A pointer to the head of the linked list.
 * @str: The string to be added to the new node.
 * code by Udeme Harrison
 * Return: The address of the new node, or NULL if it failed.
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node, *temp;

	if (head == NULL || str == NULL)
		return (NULL);

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	/* Duplicate the string and set the new node's str and len fields */
	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->len = strlen(str);
	new_node->next = NULL;

	/* If the list is empty, make the new node the head */
	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{

	/* Traverse the list to find the last node */
	temp = *head;
	while (temp->next != NULL)
	temp = temp->next;

	/* Add the new node to the end of the list */
	temp->next = new_node;
	}

	/* Return the address of the new node */
	return (new_node);
}
