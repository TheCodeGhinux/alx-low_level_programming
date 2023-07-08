#include "hash_tables.h"

/**
 * hash_table_create - To create a hash table.
 * @size: SThe size of the array.
 *
 * Return: A pointer to the new hash table
 *          else If an error occurs - NULL.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_t;
	unsigned long int a;

	hash_t = malloc(sizeof(hash_table_t));
	if (hash_t == NULL)
		return (NULL);

	hash_t->size = size;
	hash_t->array = malloc(sizeof(hash_node_t *) * size);
	if (hash_t->array == NULL)
		return (NULL);
	for (a = 0; a < size; a++)
		hash_t->array[a] = NULL;

	return (hash_t);
}
