#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * hash_table_create - Creates a sorted hash table.
 * @size: The size of the array.
 *
 * Return: A pointer to the newly created sorted hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	/* Allocate memory for the sorted hash table structure */
	hash_table_t *ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);

	/* Initialize the size, array, and head/tail pointers */
	ht->size = size;
	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	memset(ht->array, 0, sizeof(hash_node_t *) * size);

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * hash_table_set - Adds an element to the sorted hash table.
 * @ht: The sorted hash table.
 * @key: The key. Cannot be an empty string.
 * @value: The value associated with the key. Must be duplicated.
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	/* Check for NULL pointers or empty key */
	if (ht == NULL || key == NULL || value == NULL || key[0] == '\0')
		return (0);

	unsigned long int index = key_index((const unsigned char *)key, ht->size);
	hash_node_t *node, *temp, *prev = NULL;

	/* Check for collision in the index */
	temp = ht->array[index];
	while (temp != NULL)
	{
		/* If key exists, update value and return */
		if (strcmp(temp->key, key) == 0)
		{
			free(temp->value);
			temp->value = strdup(value);
			if (temp->value == NULL)
				return (0);
			return (1);
		}
		prev = temp;
		temp = temp->next;
	}

	/* Create a new node */
	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (0);
	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);
		return (0);
	}
	node->value = strdup(value);
	if (node->value == NULL)
	{
		free(node->key);
		free(node);
		return (0);
	}

	/* Insert node at the beginning of the list */
	node->next = ht->array[index];
	ht->array[index] = node;

	/* Sort the linked list */
	for (temp = ht->shead; temp != NULL && strcmp(temp->key, key) < 0; temp = temp->snext)
		prev = temp;
	node->snext = temp;
	node->sprev = prev;
	if (prev != NULL)
		prev->snext = node;
	else
		ht->shead = node;
	if (temp != NULL)
		temp->sprev = node;
	else
		ht->stail = node;

	return (1);
}

/**
 * hash_table_get - Retrieves a value associated with a key.
 * @ht: The sorted hash table.
 * @key: The key you are looking for.
 *
 * Return: The value associated with the element, or NULL if key couldn’t be found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	/* Check for NULL pointers or empty key */
	if (ht == NULL || key == NULL || key[0] == '\0')
		return (NULL);

	unsigned long int index = key_index((const unsigned char *)key, ht->size);
	hash_node_t *temp = ht->array[index];

	/* Traverse the linked list to find the key */
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
			return (temp->value);
		temp = temp->next;
	}

	return (NULL);
}

/**
 * hash_table_print - Prints the hash table using the sorted linked list.
 * @ht: The sorted hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	if (ht == NULL)
		return;

	hash_node_t *temp = ht->shead;
	int first = 1;

	putchar('{');

	while (temp)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", temp->key, temp->value);
		temp = temp->snext;
		first = 0;
	}

	printf("}\n");
}

/**
 * hash_table_print_rev - Prints the hash tables key/value pairs in reverse order using the sorted linked list.
 * @ht: The sorted hash table.
 */
void hash_table_print_rev(const hash_table_t *ht)
{
	if (ht == NULL)
		return;

	hash_node_t *temp = ht->stail;
	int first = 1;

	putchar('{');

	while (temp)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", temp->key, temp->value);
		temp = temp->sprev;
		first = 0;
	}

	printf("}\n");
}

/**
 * hash_table_delete - Deletes a sorted hash table.
 * @ht: The sorted hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	if (ht == NULL)
		return;

	hash_node_t *node, *temp;

	/* Free nodes in the linked list */
	for (node = ht->shead; node != NULL; node = temp)
	{
		temp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
	}

	/* Free array */
	free(ht->array);

	/* Free table structure */
	free(ht);
}
