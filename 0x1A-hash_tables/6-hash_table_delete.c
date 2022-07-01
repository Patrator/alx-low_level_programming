#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table
 *
 * @ht: hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *future;
	unsigned long int i;

	if (!ht)	/* head is empty */
		return;

	for (i = 0; i < ht->size; i++)
	{
		future = ht->array[i];
		while (ht->array[i])
		{
			ht->array[i] = ht->array[i]->next;
			free(future->key);
			free(future->value);
			free(future);
			future = ht->array[i];
		}
	}
	free(ht->array);
	free(ht);
}
