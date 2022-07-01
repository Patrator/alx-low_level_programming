#include "hash_tables.h"

/**
 * hash_table_get - gets the value associated with a key
 *
 * @ht: hash table
 * @key: the key to be identified
 *
 * Return: the value at the key or NULL if not found
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *future;
	unsigned long int index;

	if (!ht)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);

	future = ht->array[index];

	while (future)  /* get value at key */
	{
		if (strcmp(key, future->key) == 0)
			return (future->value);

		future = future->next;
	}

	/* key doesn't exist */
	return (NULL);
}
