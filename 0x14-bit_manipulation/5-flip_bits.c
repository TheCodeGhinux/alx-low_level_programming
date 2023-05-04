#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * flip_bits -  function that returns the number of bits you
 *               would need to flip to get from one number to another.
 * @n: number.
 * @m: number to flip n to.
 *
 * Return: The number of bits to flip from n to m.
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int x = n ^ m, y = 0;

	while (x > 0)
	{
		y += (x & 1);
		x >>= 1;
	}

	return (y);
}
