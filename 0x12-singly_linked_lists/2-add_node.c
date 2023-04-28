#include "lists.h"

/**
 * add_node - add new node at beginning of list_t
 * @head: pointer to structure
 * @str: string
 * Return: address of new element
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *newNode;
	unsigned int length = 0;

	newNode = malloc(sizeof(list_t));
	if (newNode == NULL)
	{
		free(newNode);
		return (NULL);
	}
	newNode->str = strdup(str);
	while (str[length] != '\0')
	{
		length++;
	}
	newNode->len = length;
	if (*head != NULL)
	{
		newNode->next = *head;
	}
	else
	{
		newNode->next = NULL;
	}
	*head = newNode;
	return (*head);
}

/**
 * The function add_node takes a pointer to a pointer to list_t struct, head,
 * and a pointer to a string, str, and adds a new node to the beginning of the linked list.
 *
 * First, it allocates memory for a new list_t struct and checks if the allocation was successful.
 * If the allocation was unsuccessful, the function returns NULL and frees the allocated memory.
 *
 * Next, the function sets the str member of the new node to a duplicate of the
 * input string, str, and sets the len member to the length of str.
 *
 * Then, the function checks if the head pointer is pointing to a non-empty linked list.
 * If it is, the function sets the next member of the new node to point
 * to the first element in the existing list. Otherwise, it sets the next member to NULL.
 * Finally, it sets the head pointer to point to the new node and returns the address of the new node.
 */
