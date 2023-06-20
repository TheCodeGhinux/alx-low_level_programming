#include "main.h"

/**
 * main - Entry point
 * @c: character c
 * Return: Always 0 (Success)
 */
int _putchar(char c)
{
return (putchar(c));
}


/**
 * _islower - a function that checks for lowercase character
 * @c: single letter input
 * Return: 1 if int c is lowercase, else 0
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}


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


/**
 * _abs - a function that computes the absolute value of an integer
 * @n: integer input
 * Return: absolute value of a letter (lower or uppercase), else 0
*/

int _abs(int n)
{
return (n >= 0 ? n : -n);
}



/**
 * _isupper - uppercase letters
 * @c: character to check
 *
 * Return: 0 or 1
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}