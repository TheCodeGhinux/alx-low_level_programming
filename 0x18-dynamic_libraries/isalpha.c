#include "main.h"

/**
 * _isalpha - checks for alphabetic character
 * @c: single letter input
 * Return: 1 if c is a letter (lower or uppercase), else 0
 */
int _isalpha(int c)
{
	if (_islower(c) || _isupper(c))
		return (1);
	else
		return (0);
}
