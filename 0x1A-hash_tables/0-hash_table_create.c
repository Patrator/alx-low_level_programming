#include "hash_tables.h"

/**
 * hash_table_create - creates a hastable
 *
 * @size: Size of the hash table
 * Return: pointer to the newly create hash table
 * or NULL if something happens
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *htable;
	unsigned long int i;

	/* Malloc space for one hashtable */
	htable = malloc(sizeof(hash_table_t) * 1);
	if (!htable)
		return (NULL);

	/* init size of hashtable */
	htable->size = size;

	/* Malloc space for the array in the table */
	htable->array = malloc(htable->size * sizeof(hash_table_t *));
	if (!htable->array)
		return (NULL);

	/* set all malloced spots in array to NULL */
	for (i = 0; i < htable->size; i++)
		htable->array[i] = NULL;

	return (htable);
}
