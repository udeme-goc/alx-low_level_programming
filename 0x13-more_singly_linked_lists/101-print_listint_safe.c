#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list, handling loops
 * @head: A pointer to the head node of the list
 * code by Udeme Harrison
 * Return: The number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0; /* Keep track of number of nodes printed */
	const listint_t *slow = head, *fast = head; /* Pointers for loop detection */

	/* Traverse the list with the two pointers */
	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		slow = slow->next; /* Move slow pointer by one node */
		fast = fast->next->next; /* Move fast pointer by two nodes */

		/* If a loop is detected, print error message and exit with status 98 */
		if (slow == fast)
		{
			printf("-> [%p] %d\n", (void *)slow, slow->n);
			printf("Loop detected in list\n");
			exit(98);
		}

		/* Print the current node and update count */
		printf("[%p] %d\n", (void *)slow, slow->n);
		count++;
	}

	/* Handle the case where the list ends in a loop */
	if (fast != NULL && fast->next == NULL)
	{
		printf("[%p] %d\n", (void *)slow->next, slow->next->n);
		count++;
	}

	/* Handle the case where the list does not end in a loop */
	while (slow != NULL)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		count++;
		slow = slow->next;
	}

	return (count);
}
