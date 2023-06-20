#include "main.h"

/**
 * _puts - Prints a string .
 * @s: string.
 */
void _puts(char *s)
{
	while (*s)
		_putchar(*s++);

	_putchar('\n');
}
