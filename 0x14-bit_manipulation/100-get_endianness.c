#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * get_endianness -  function that checks the endianness.
 *
 * Return: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
	int y = 1;
	char *x = (char *)&y;

	if (*x == 1)
		return (1);

	return (0);
}
