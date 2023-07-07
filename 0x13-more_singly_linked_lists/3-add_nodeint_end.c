#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of a listint_t list
 * @head: A pointer to a pointer to the head of the list
 * @n: The integer to be added to the new node
 * code by Udeme Harrison
 * Return: The address of the new element, or NULL if it failed
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node, *last_node;  /* Pointers to new, last nodes rspvly */

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)  /* Check if memory allocation failed */
	{
		return (NULL);  /* Return NULL if it failed */
	}

	/* Initialize the new node */
	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)  /* Check if the list is empty */
	{
		*head = new_node;  /* If it is, make the new node the head */
	}
	else
	{
		last_node = *head;  /* Initialize last_node to point to the head */

		/* Traverse the list to find the last node */
		while (last_node->next != NULL)
		{
			last_node = last_node->next;
		}

		last_node->next = new_node;  /* Add the new node to the end of the list */
	}
	return (new_node);  /* Return the address of the new node */
}
