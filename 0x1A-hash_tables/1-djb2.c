#include "hash_tables.h"

/**
 * hash_djb2 - Func implementing the djb2 algorithm.
 * @str: The string to hash.
 *
 * Return: The calculated hash.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int y;
	int a;

	y = 5381;
	while ((a = *str++))
		y = ((y << 5) + y) + a; /* hash * 33 + c */

	return (y);
}
