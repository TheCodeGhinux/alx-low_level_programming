#include "lists.h"

/**
 * print_dlistint - T print all elements of a dlistint_t list.
 * @h: Head of the dlistint_t list.
 *
 * Return: Number of i in list.
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t i = 0;

	while (h)
	{
		i++;
		printf("%d\n", h->n);
		h = h->next;
	}

	return (i);
}
