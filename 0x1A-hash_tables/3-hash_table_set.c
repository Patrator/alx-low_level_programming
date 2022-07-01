#include "hash_tables.h"

/**
 * hash_table_set - adds element to the hash table
 *
 * @key: the key to be identified
 * @value: value to be added
 * @ht: pointer to the hash table
 *
 * Return: 1 if it succesfully sets the element
 * else 0 if it fails
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node, *future;

	if (strlen(key) == 0 || !ht)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);   /* gets index */

	future = ht->array[index];
	while (future)    /* checks for duplicates */
	{
		if (strcmp(key, future->key) == 0)
		{
			free(future->value);
			future->value = strdup(value);
			return (1);
		}
		future = future->next;
	}

	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
		return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = ht->array[index];  /* add to beginning of node */
	ht->array[index] = new_node;
	return (1);
}
