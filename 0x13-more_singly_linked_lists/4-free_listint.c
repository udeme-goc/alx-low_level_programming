#include "lists.h"

/**
 * free_listint - Frees a listint_t list
 * @head: A pointer to the head of the list
 * code by Udeme Harrison
 * Return: There is no return bcos no data manipulated
 */

void free_listint(listint_t *head)
{
	listint_t *current;  /* Pointer to the current node */

	while (head != NULL)  /* Traverse the list */
	{
		current = head;  /* Assign the current node to head */
		head = head->next;  /* Move head to the next node */
		free(current);  /* Free the current node */
	}
}

/**
 * Explanation:
 *
 * free_listint takes pointer the head of singly linked list head
 * as argument, and frees all the nodes in the list.
 *
 * Function initializes pointer (current) to point to current node in list.
 *
 * Function uses a while loop to traverse list.
 * In each iteration, function assigns value of 'head' to 'current',
 * moves head to next node using next pointer, and frees current using the free
 *
 * Function repeats process until it reaches end of list.
 *
 * Function does not return anything, as it only frees memory.
 */
