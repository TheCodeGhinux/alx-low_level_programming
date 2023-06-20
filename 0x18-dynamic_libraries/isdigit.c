#include "main.h"

/**
 * _isdigit - checks if a character is a digit
 * @c: character to check
 *
 * Return: 1 if the character is a digit, otherwise 0
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
