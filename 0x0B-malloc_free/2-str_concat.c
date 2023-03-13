#include "main.h"
#include <stdlib.h>

/**
* str_concat - Concatenates two strings.
* @s1: First string
* @s2: Second string
*
* Return: The pointer to the array.
*/
char *str_concat(char *s1, char *s2)
{
int a, b, c, d;
char *e;
	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	for (a = 0; s1[a] != '\0'; a++)
	{
	;
	}
	for (b = 0; s2[b] != '\0'; b++)
	{
	;
	}
	e = malloc(sizeof(char) * (a + b + 1));
	if (e == NULL)
	{
		return (NULL);
	}
	for (c = 0; s1[c] != '\0'; c++)
	{
		e[c] = s1[c];
	}
	for (d = 0; s2[d] != '\0'; d++)
	{
		e[c] = s2[d];
		c++;
	}
return (e);
}
