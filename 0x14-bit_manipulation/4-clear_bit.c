#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * clear_bit - S function that sets the value of a bit to 0 at a given index.
 * @n: Pointer.
 * @index: Indices start at 0.
 *
 * Return: 1 if it worked, or -1 if an error occurred.
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= 64)
		return (-1);

	*n &= ~(1 << index);

	return (1);
}
