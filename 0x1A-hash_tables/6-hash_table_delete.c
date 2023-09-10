#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: The hash table to be deleted.
 */

void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *current_node, *temp_node;

	if (ht == NULL)
		return; /* Check if hash table is valid */

	/* Loop through each index in the array */
	for (i = 0; i < ht->size; i++)
	{
		current_node = ht->array[i]; /* Get the node at this index */

		/* Iterate through linked list at this index */
		while (current_node != NULL)
		{
			temp_node = current_node->next; /* Save next node */
			free(current_node->key); /* Free key */
			free(current_node->value); /* Free value */
			free(current_node); /* Free node */
			current_node = temp_node; /* Move to next node */
		}
	}

	free(ht->array); /* Free the array of nodes */
	free(ht); /* Free the hash table itself */
}
