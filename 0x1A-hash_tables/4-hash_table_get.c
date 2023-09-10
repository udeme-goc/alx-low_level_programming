#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_get - Retrieves a value associated with a key.
 * @ht: The hash table to look into.
 * @key: The key you are looking for.
 *
 * Return: The value associated with the element, or NULL if key couldn’t be found.
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *current_node;

	/* Check if the hash table and key are valid */
	if (ht == NULL || key == NULL || strcmp(key, "") == 0)
		return (NULL);

	/* Calculate the index for the key */
	index = key_index((const unsigned char *)key, ht->size);
	current_node = ht->array[index];

	/* Traverse the linked list at the index */
	while (current_node != NULL)
	{
		if (strcmp(current_node->key, key) == 0)
			return (current_node->value); /* Return the value if key is found */
		current_node = current_node->next;
	}

	return (NULL); /* Return NULL if key is not found */
}
