#include "lists.h"

/**
 * free_dlistint - TO free a linked dlistint_t list.
 * @head: Head of the dlistint_t list.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *j;

	while (head)
	{
		j = head->next;
		free(head);
		head = j;
	}
}
