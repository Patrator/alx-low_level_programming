#include "hash_tables.h"

/**
 * key_index - gets the index of a key
 *
 * @key: the key to identified with
 * @size: size of array
 * Return: key index
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
