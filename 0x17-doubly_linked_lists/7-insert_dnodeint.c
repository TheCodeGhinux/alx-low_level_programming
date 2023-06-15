#include "lists.h"

/**
 * insert_dnodeint_at_index - It inserts a new node at a position
 *                             in dlistint_t list.
 * @h: Pointer to the head of the dlistint_t list.
 * @idx: Index where the new node should be inserted.
 * @n: Data to be stored in the new node.
 *
 * Return: Address of the new node.
 *          Else - Null
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_nd, *j = *h;
	unsigned int i;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (i = 0; i < idx - 1; i++)
	{
		if (j == NULL)
			return (NULL);
		j = j->next;
	}

	if (j == NULL)
		return (NULL);

	if (j->next == NULL)
		return (add_dnodeint_end(h, n));

	new_nd = malloc(sizeof(dlistint_t));
	if (new_nd == NULL)
		return (NULL);

	new_nd->n = n;
	new_nd->next = j->next;
	new_nd->prev = j;
	j->next->prev = new_nd;
	j->next = new_nd;

	return (new_nd);
}
