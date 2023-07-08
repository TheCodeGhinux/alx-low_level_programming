#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - To create a sorted hash table.
 * @size: The size of new sorted hash table.
 *
 * Return:  - Pointer to the new sorted hash table.
 *         Else- Null, If an error occurs 
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int a;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (a = 0; a < size; a++)
		ht->array[a] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - To add an element to a sorted hash table.
 * @ht: Pointer to the sorted hash table.
 * @key: Key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: 1
 *         Else- 0 on failure.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new, *y;
	char *val_cp;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	val_cp = strdup(value);
	if (val_cp == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	y = ht->shead;
	while (y)
	{
		if (strcmp(y->key, key) == 0)
		{
			free(y->value);
			y->value = val_cp;
			return (1);
		}
		y = y->snext;
	}

	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
	{
		free(val_cp);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(val_cp);
		free(new);
		return (0);
	}
	new->value = val_cp;
	new->next = ht->array[index];
	ht->array[index] = new;

	if (ht->shead == NULL)
	{
		new->sprev = NULL;
		new->snext = NULL;
		ht->shead = new;
		ht->stail = new;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new->sprev = NULL;
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new;
	}
	else
	{
		y = ht->shead;
		while (y->snext != NULL && strcmp(y->snext->key, key) < 0)
			y = y->snext;
		new->sprev = y;
		new->snext = y->snext;
		if (y->snext == NULL)
			ht->stail = new;
		else
			y->snext->sprev = new;
		y->snext = new;
	}

	return (1);
}

/**
 * shash_table_get - Retrieve the value associated with
 *                   a key in a sorted hash table.
 * @ht: Pointer to the sorted hash table.
 * @key: Key to get the value of.
 *
 * Return:  The value associated with key
 *         Else- Null, If Key cannot be matched in ht.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	node = ht->shead;
	while (node != NULL && strcmp(node->key, key) != 0)
		node = node->snext;

	return ((node == NULL) ? NULL : node->value);
}

/**
 * shash_table_print - Prints a sorted hash table in order.
 * @ht: Pointer to the sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->shead;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: Pointer to the sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->stail;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: Pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *node, *y;

	if (ht == NULL)
		return;

	node = ht->shead;
	while (node)
	{
		y = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = y;
	}

	free(head->array);
	free(head);
}
