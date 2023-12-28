#include "search_algos.h"
#include <math.h>

/**
 * index_list - Searches for an algorithm in a sorted singly
 *             linked list of integers using index search.
 * @list: input list
 * @size: size of the array
 * @value: The value to search for.
 *
 * Return: A pointer to the first node where the value is located.
 *         Else, Null If the value is not present or
 *         the head of the list is NULL, NULL.
 */
listint_t *index_list(listint_t *list, size_t size, int value)
{
	size_t index, a, b;
	listint_t *node;

	if (list == NULL || size == 0)
		return (NULL);

	b = (size_t)sqrt((double)size);
	index = 0;
	a = 0;

	do {
		node = list;
		a++;
		index = a * b;

		while (list->next && list->index < index)
			list = list->next;

		if (list->next == NULL && index != list->index)
			index = list->index;

		printf("Value checked at index [%d] = [%d]\n", (int)index, list->n);

	} while (index < size && list->next && list->n < value);

	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)node->index, (int)list->index);

	for (; node && node->index <= list->index; node = node->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)node->index, node->n);
		if (node->n == value)
			return (node);
	}

	return (NULL);
}
