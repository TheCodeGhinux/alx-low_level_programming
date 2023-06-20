#include "main.h"

/**
 * _memcpy - fnct to copy memory content source to a char destination .
 * @dest: memory allocation of the destination
 * @src: memory content to copy from the src
 * @n: content in byte to copy
 *
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(dest + i) = *(src + i);
	}
	return (dest);
}



/**
 * _strchr - locates a character in a string .
 * @s: string to check
 * @c: character to found
 * UPDATE V1.0 : Features : Pointers implementation instead of Arrays .
 * Pointer/memory incrementation instead of i .
 * Return: pointer to s or null
 */

char *_strchr(char *s, char c)
{

	while (*s)
	{
		s++;

			if (*s == c)
		{
			return (s);
		}


	}

		return (0);


}


/**
 * _strspn - search a string for a set of bytes
 * @s: char string array
 * @accept: char array to check bytes with
 * Return: Number of bytes in the intial segment of `s`
 */

unsigned int _strspn(char *s, char *accept)
{
	int i;
	int j;
	int c;

	i = 0;
	c = 0;

	while (s[i] != '\0')
	{
		j = 0;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
			{
				c++;
				break;
			}
			j++;
		}
		if (accept[j] == '\0')
			break;
		i++;
	}
	return (c);
}


/**
 * _strpbrk - searches a string for any of a set of bytes.
 * @s: char to check
 * @accept: char to look for
 * Return: char
*/
char *_strpbrk(char *s, char *accept)
{
	int i, k;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (k = 0; accept[k] != '\0'; k++)
		{
			if (s[i] == accept[k])
				return (s + i);
		}
	}
	return (0);
}


/**
 * _strstr - locating a substring
 * @needle: occurance to find
 * @haystack: string to search
 * Return: pointer
*/
char *_strstr(char *haystack, char *needle)
{

	while (*haystack)
	{
	char *src = haystack;
	char *sub = needle;

	while (*haystack && *sub && *haystack == *sub)
	{
		haystack++;
		sub++;
	}
	if (!*sub)
	return (src);
	haystack = src + 1;
	}
return (0);
}
