#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the head of the linked list
 * code by Udeme Harrison
 * Return: address of the node where the loop starts, or NULL if no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;
		return (NULL);

	slow = head;
	fast = head;

	/* move slow pointer one node at a time */
	slow = slow->next;
	/* move fast pointer two nodes at a time */
	fast = fast->next->next;
	/* if they meet, there is a loop */
	if (slow == fast)
	{
		/* move slow back to head, keep fast at meeting point */
		slow = head;
		while (slow && fast)
		{
			/* move both pointers one node at a time */
			if (slow == fast)
				return (slow);
			slow = slow->next;
			fast = fast->next;
		}
	}

	return (NULL);
}

