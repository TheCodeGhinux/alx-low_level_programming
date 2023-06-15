#include "lists.h"

/**
 * add_dnodeint - Adds a new node at the beginning of a dlistint_t list.
 * @head: Pointer to a pointer to the head of the dlistint_t list.
 * @n: The integer to be stored in the new node.
 *
 * Return: Address of the new node,
 *         else - NULL if it failed.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_nd = malloc(sizeof(dlistint_t));

	if (new_nd == NULL)
		return (NULL);

	new_nd->n = n;
	new_nd->prev = NULL;
	new_nd->next = *head;
	if (*head != NULL)
		(*head)->prev = new_nd;
	*head = new_nd;

	return (new_nd);
}
