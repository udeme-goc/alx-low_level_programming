#include "lists.h"

/**
 * list_len - returns the number of elements in a linked list
 * @h: pointer to the list_t list
 * code adapted by Udeme Harrison
 * Return: number of elements in h
 */

size_t list_len(const list_t *h)
{
	size_t n = 0;

	while (h)
	{
		n++;
		h = h->next;
	}
	return (n);
}

/**
* The function list_len takes a pointer to a list_t struct
* and returns the number of elements in the linked list pointed to by h.
* It does this by iterating through the list using a while loop
* and incrementing a counter variable n each time.
* Finally, the function returns the value of n
*/
