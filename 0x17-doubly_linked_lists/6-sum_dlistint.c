#include "lists.h"

/**
 * sum_dlistint - It returns the sum of data of a dlistint_t linked list.
 * @head: Pointer to the head of the dlistint_t list.
 *
 * Return: Sum of all the data (n) in the list.
 *          Else -  0 if the list is empty.
 */
int sum_dlistint(dlistint_t *head)
{
	int total = 0;
	dlistint_t *j = head;

	while (j != NULL)
	{
		total += j->n;
		j = j->next;
	}

	return (total);
}
