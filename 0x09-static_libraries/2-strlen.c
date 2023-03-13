#include "main.h"
/**
* _strlen - Returns the length of a string.
* @s: The pointer.
*
* Return: To the value of s.
*/
int _strlen(char *s)
{
int cont;
int i;
i = 0;
cont = 0;
while (s[i] != 0)
{
i++;
}
cont = cont + i;
return (cont);
}
