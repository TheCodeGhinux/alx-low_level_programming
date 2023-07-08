#include "hash_tables.h"

/**
 * key_index - To give the index of a key.
 * @key: key
 * @size: Size of the array of the hash table.
 *
 * Return: Index number for the key/value pair.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
