#include "lists.h"

/**
 * free_list - Frees a list.
 * @head: Pointer to the head node of the list to be freed.
 *
 * Return: void.
 */

void free_list(list_t *head)
{
	list_t *temp;

	temp = head;
	while (temp != NULL)
	{
		free(temp->str);
		free(temp);
		temp = temp->next;
	}
}

/**
* note - The function free_list() takes a pointer to the head
* of a linked list as an argument and frees each node in the list
* along with the string that it contains. Function does not return any value.
*/
