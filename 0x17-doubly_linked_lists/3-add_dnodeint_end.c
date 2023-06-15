#include "lists.h"

/**
 * add_dnodeint_end - To add a new node at the end of a dlistint_t list.
 * @head: Pointer to the head of the dlistint_t list.
 * @n: The integer for the new node to contain.
 *
 * Return: The address of the new node.
 *         Otherwise - NULL If the function fails.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *i, *j;

	i = malloc(sizeof(dlistint_t));
	if (i == NULL)
		return (NULL);

	i->n = n;
	i->next = NULL;

	if (*head == NULL)
	{
		i->prev = NULL;
		*head = i;
		return (i);
	}

	j = *head;
	while (j->next != NULL)
		j = j->next;
	j->next = i;
	i->prev = j;

	return (i);
}
