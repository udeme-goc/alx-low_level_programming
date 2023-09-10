#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print - Prints a hash table.
 * @ht: The hash table to print.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node;
	int first = 1; /* Flag to manage comma formatting */

	if (ht == NULL)
		return;

	printf("{"); /* Begin printing the hash table */

	/* Loop through each index in the array */
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i]; /* Get the node at this index */

		/* Iterate through linked list at this index */
		while (node != NULL)
		{
			if (!first)
				printf(", "); /* Print comma if not the first element */
			printf("'%s': '%s'", node->key, node->value); /* Print key-value pair */
			first = 0; /* Set flag to indicate first element has been printed */
			node = node->next; /* Move to next node in the linked list */
		}
	}

	printf("}\n"); /* End printing the hash table */
}
