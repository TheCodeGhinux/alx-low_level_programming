#include "lists.h"

/**
 * get_dnodeint_at_index - It locates a node in a dlistint_t list.
 * @head: Head of the dlistint_t list.
 * @index: Node to locate.
 *
 * Return: the address of the located node.
 *         Otherwise - NULL, If the node does not exist.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *i = head;
	unsigned int j = 0;

	while (i != NULL)
	{
		if (j == index)
		  return (i);

		i = i->next;
		j++;
	}

	return (NULL);
}
