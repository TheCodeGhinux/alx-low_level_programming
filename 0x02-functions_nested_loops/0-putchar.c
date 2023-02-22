/* Online C Compiler and Editor */
#include "main.h"
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *gbemi = "_putchar";

	while (*gbemi)
	{
		_putchar(*gbemi);
		gbemi++;
	}
	_putchar('\n');

	return (0);
}
