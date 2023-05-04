#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: character
 *
 * Return: On success 1. -1 is returned if it fails.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
