#include "search_algos.h"
#include <math.h>

/**
 * jump_list - Searches for an algorithm in a sorted singly
 *             linked list of integers using jump search.
 * @list: input list
 * @size: size of the array
 * @value: The value to search for.
 *
 * Return: A pointer to the first node where the value is located.
 *         Else, Null If the value is not present or 
 *         the head of the list is NULL, NULL.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t jump, a, b;
	listint_t *node;

	if (list == NULL || size == 0)
		return (NULL);

	b = (size_t)sqrt((double)size);
	jump = 0;
	a = 0;

	do
	{
		node = list;
		a++;
		jump = a * b;

		while (list->next && list->jump < jump)
			list = list->next;

		if (list->next == NULL && jump != list->jump)
			jump = list->jump;

		printf("Value checked at jump [%d] = [%d]\n", (int)jump, list->n);

	} while (jump < size && list->next && list->n < value);

	printf("Value found between jumpes ");
	printf("[%d] and [%d]\n", (int)node->jump, (int)list->jump);

	for (; node && node->jump <= list->jump; node = node->next)
	{
		printf("Value checked at jump [%d] = [%d]\n", (int)node->jump, node->n);
		if (node->n == value)
			return (node);
	}

	return (NULL);
}