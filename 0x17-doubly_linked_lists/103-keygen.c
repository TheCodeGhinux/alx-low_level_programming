#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - TO generate and print passwords for the crackme5 executable.
 * @argc: The number of arguments supplied to the program.
 * @argv: Array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	char password[7], *enc;
	int len = strlen(argv[1]), i, j;

	enc = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	j = (len ^ 59) & 63;
	password[0] = enc[j];

	j = 0;
	for (i = 0; i < len; i++)
		j += argv[1][i];
	password[1] = enc[(j ^ 79) & 63];

	j = 1;
	for (i = 0; i < len; i++)
		j *= argv[1][i];
	password[2] = enc[(j ^ 85) & 63];

	j = 0;
	for (i = 0; i < len; i++)
	{
		if (argv[1][i] > j)
			j = argv[1][i];
	}
	srand(j ^ 14);
	password[3] = enc[rand() & 63];

	j = 0;
	for (i = 0; i < len; i++)
		j += (argv[1][i] * argv[1][i]);
	password[4] = enc[(j ^ 239) & 63];

	for (i = 0; i < argv[1][0]; i++)
		j = rand();
	password[5] = enc[(j ^ 229) & 63];

	password[6] = '\0';
	printf("%s", password);
	return (0);
}
