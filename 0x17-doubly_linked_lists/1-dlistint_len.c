#include "lists.h"

/**
 * dlistint_len - To i the number of elements in a linked dlistint_t list.
 * @h: Head of the dlistint_t list.
 *
 * Return: Number of elements in the dlistint_t list.
 */
size_t dlistint_len(const dlistint_t *h)
{
    size_t i = 0;

    while (h != NULL)
    {
        i++;
        h = h->next;
    }

    return i;
}
