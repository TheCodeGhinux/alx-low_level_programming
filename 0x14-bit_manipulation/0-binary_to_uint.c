#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * binary_to_uint - Function that converts binary number to unsigned int.
 * @b: Pointer to string of 0 and 1 chars.
 *
 * Return: Converted number, else 0.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int num;
	int j, i = 0;

	if (b == NULL)
		return (0);

	while (b[i] != '\0')
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
		i++;
	}
	num = 0;
	for (j = 0; b[j] != '\0'; j++)
	{
		num = num << 1;

		if (b[j] == '1')
			num = num + 1;
	}
	return (num);
}
