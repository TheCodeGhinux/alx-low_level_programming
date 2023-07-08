#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table.
 * @size: number of array slots to make the table.
 *
 * Return: pointer to the hash table created, 
 *          else NULL if malloc failed.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *hash_table;
    unsigned long int i;

    hash_table = malloc(sizeof(shash_table_t));
    if (hash_table == NULL)
        return NULL;

    hash_table->size = size;
    hash_table->shead = NULL;
    hash_table->stail = NULL;
    hash_table->array = malloc(sizeof(shash_node_t *) * size);
    if (hash_table->array == NULL)
    {
        free(hash_table);
        return NULL;
    }

    for (i = 0; i < size; i++)
        hash_table->array[i] = NULL;

    return hash_table;
}

/**
 * create_spair - creates a key/value pair for the sorted hash table.
 * @key: the key, a non-empty string.
 * @value: the value associated with the key, can be an empty string.
 *
 * Return: pointer to the new node, 
 *          Else NULL if malloc failed.
 */
shash_node_t *create_spair(const char *key, const char *value)
{
    shash_node_t *node = malloc(sizeof(shash_node_t));

    if (node == NULL)
        return NULL;

    node->key = malloc(strlen(key) + 1);
    if (node->key == NULL)
    {
        free(node);
        return NULL;
    }
    strcpy(node->key, key);

    node->value = malloc(strlen(value) + 1);
    if (node->value == NULL)
    {
        free(node->key);
        free(node);
        return NULL;
    }
    strcpy(node->value, value);

    node->next = NULL;
    node->sprev = NULL;
    node->snext = NULL;

    return node;
}

/**
 * insert_spair - inserts a key/value pair node into the sorted hash table.
 * @ht: pointer to the sorted hash table.
 * @node: the node to insert.
 *
 * Return: 1 on success, 
 *          ELse0 on failure.
 */
int insert_spair(shash_table_t *ht, shash_node_t *node)
{
    unsigned long int index = key_index((unsigned char *)node->key, ht->size);
    shash_node_t *curr_node = ht->array[index];
    shash_node_t *prev_node = NULL;

    while (curr_node != NULL && strcmp(curr_node->key, node->key) < 0)
    {
        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    if (prev_node == NULL)
    {
        node->next = ht->array[index];
        ht->array[index] = node;
    }
    else
    {
        prev_node->next = node;
        node->next = curr_node;
    }

    if (ht->shead == NULL || strcmp(node->key, ht->shead->key) < 0)
    {
        node->sprev = NULL;
        node->snext = ht->shead;
        if (ht->shead != NULL)
            ht->shead->sprev = node;
        ht->shead = node;
        if (ht->stail == NULL)
            ht->stail = node;
    }
    else if (strcmp(node->key, ht->stail->key) > 0)
    {
        node->sprev = ht->stail;
        node->snext = NULL;
        ht->stail->snext = node;
        ht->stail = node;
    }
    else
    {
        curr_node = ht->shead;
        while (curr_node != NULL && strcmp(curr_node->key, node->key) < 0)
            curr_node = curr_node->snext;

        node->sprev = curr_node->sprev;
        node->snext = curr_node;
        curr_node->sprev->snext = node;
        curr_node->sprev = node;
    }

    return 1;
}

/**
 * shash_table_set - adds or updates an element to the sorted hash table.
 * @ht: pointer to the sorted hash table.
 * @key: the key, a non-empty string.
 * @value: the value associated with the key, can be an empty string.
 *
 * Return: 1 on success, 
 *          Else 0 on error.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    if (key == NULL || ht == NULL)
        return 0;

    unsigned long int index = key_index((unsigned char *)key, ht->size);
    shash_node_t *node = ht->array[index];

    while (node != NULL && strcmp(node->key, key) != 0)
        node = node->next;

    if (node == NULL)
    {
        node = create_spair(key, value);
        if (node == NULL)
            return 0;
        node->next = ht->array[index];
        ht->array[index] = node;
        insert_spair(ht, node);
    }
    else
    {
        free(node->value);
        node->value = malloc(strlen(value) + 1);
        if (node->value == NULL)
            return 0;
        strcpy(node->value, value);
    }

    return 1;
}

/**
 * shash_table_get - retrieves a value associated with a key.
 * @ht: a pointer to the sorted hash table array.
 * @key: the key, a string that cannot be empty.
 *
 * Return: the value associated with the key, 
 *          Else NULL if key can't be found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *node;

	if (ht == NULL)
		return (NULL);
	if (key == NULL)
		return (NULL);
	index = key_index((unsigned char *)key, ht->size);
	if (ht->array[index] == NULL)
		return (NULL);
	if (strcmp(ht->array[index]->key, key) == 0)
		return (ht->array[index]->value);
	node = ht->array[index];
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}

/**
 * shash_table_print - prints key/value pairs in sorted hash table order.
 * @ht: the sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	unsigned long int count = 0;
	shash_node_t *node = ht->shead;

	if (ht == NULL)
		return;
	printf("{");
	while (node != NULL)
	{
		if (count > 0)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		count++;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints sorted key/value pairs in reverse.
 * @ht: the sorted hash table.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	unsigned long int count = 0;
	shash_node_t *node = ht->stail;

	if (ht == NULL)
		return;
	printf("{");
	while (node != NULL)
	{
		if (count > 0)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		count++;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i = 0;
	shash_node_t *node;

	while (i < ht->size)
	{
		while (ht->array[i] != NULL)
		{
			node = ht->array[i]->next;
			free(ht->array[i]->key);
			free(ht->array[i]->value);
			free(ht->array[i]);
			ht->array[i] = node;
		}
		i++;
	}
	free(ht->array);
	free(ht);
}
