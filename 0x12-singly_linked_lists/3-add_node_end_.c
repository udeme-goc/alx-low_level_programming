#include "lists.h"

/**
 * add_node_end - adds a new node at the end
 * of a list_t list.
 * @head: head of the linked list.
 * @str: string to store in the list.
 * Return: address of the head.
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *newNode, *temp;
	size_t nchar;

	newNode = malloc(sizeof(list_t));
	if (newNode == NULL)
		return (NULL);

	newNode->str = strdup(str);

	for (nchar = 0; str[nchar]; nchar++)
	newNode->len = nchar;
	newNode->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = newNode;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newNode;
	}

	return (*head);
}

/**
* Note - The function add_node_end takes a pointer to a pointer to
* list_t struct, head, and a pointer to a string, str,
* and adds a new node to the end of the linked list.
*
* First, it allocates memory for a new list_t struct and checks if
* the allocation was successful.
* If the allocation was unsuccessful, the function returns NULL.
*
* Next, the function sets the str member of the new node to a duplicate
* of the input string, str, and sets the len member to the length of str.
*
* Then, the function sets the next member of the new node to NULL and
* initializes a temp pointer to point to head.
*
* The function then checks if the head pointer is pointing to
* an empty linked list.
* If it is, the function sets the head pointer to point to the new node.
* Otherwise, the function iterates through the linked list using
* the temp pointer until it reaches the last node, and sets
* the next member of the last node to point to the new node.
* Finally, the function returns the address of the head node.
*/
