#include "lists.h"

/**
 * add_nodeint - Adds a new node at the beginning of a listint_t list
 * @head: A pointer to a pointer to the head of the list
 * @n: The integer to be added to the new node
 * code by Udeme Harrison
 * Return: The address of the new element, or NULL if it failed
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;  /* Pointer to the new node */

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)  /* Check if memory allocation failed */
	{
		return (NULL);  /* Return NULL if it failed */
	}

	/* Initialize the new node */
	new_node->n = n;
	new_node->next = *head;

	/* Update the head to point to the new node */
	*head = new_node;

	return (new_node);  /* Return the address of the new node */
}

