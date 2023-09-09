#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_create - Create a hash table with a given size
 * @size: The size of the array
 *
 * Return: A pointer to the created hash table, or NULL on error
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;  /* Declare a pointer to a hash table structure */
	hash_node_t **array;  /* Declare a pointer to an array of hash nodes */
	unsigned long int i = 0;  /* Initialize a counter variable */

	if (size == 0)
		return (NULL);  /* If size is 0, return NULL as it's an invalid size */

	ht = malloc(sizeof(hash_table_t));  /* Allocate memory for the hash table */
	if (!ht)
		return (NULL);  /* If memory allocation fails, return NULL */

	array = malloc(sizeof(*array) * size);  /* Alct mem 4 array of hash nodes */
	if (!array)
	{
		free(ht);  /* Free the allocated memory for the hash table */
		return (NULL);  /* If memory allocation fails, return NULL */
	}

	while (i < size)
	{
		array[i] = NULL;  /* Initialize each element of the array to NULL */
		i++;
	}

	ht->size = size;  /* Set the size of the hash table */
	ht->array = array;  /* Set the array of hash nodes */

	return (ht);  /* Return the created hash table */
}
