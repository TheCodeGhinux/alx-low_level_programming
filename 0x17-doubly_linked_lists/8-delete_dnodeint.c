#include "lists.h"

/**
 * delete_dnodeint_at_index - It Deletes a node from a dlistint_t
 *                            at a given index.
 * @head: Pointer to the head of the dlistint_t.
 * @index: Index of the node to delete.
 *
 * Return: 1 - If successful.
 *         Else - -1.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *j = *head;

	if (*head == NULL)
		return (-1);

	for (; index != 0; index--)
	{
		if (j == NULL)
			return (-1);
		j = j->next;
	}

	if (j == *head)
	{
		*head = j->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}

	else
	{
		j->prev->next = j->next;
		if (j->next != NULL)
			j->next->prev = j->prev;
	}

	free(j);
	return (1);
}
