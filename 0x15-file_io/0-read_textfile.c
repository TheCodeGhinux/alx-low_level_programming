#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - To read and print a text file.
 * @filename: A pointer to the filename.
 * @letters: The number of letters.
 *
 * Return: 1 on success, -1 on failure.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t file, r, w;
	char *text;

	if (filename == NULL)
		return (0);

	text = malloc(sizeof(char) * letters);
	if (text == NULL)
		return (0);

	file = open(filename, O_RDONLY);
	r = read(file, text, letters);
	w = write(STDOUT_FILENO, text, r);

	if (file == -1 || r == -1 || w == -1 || w != r)
	{
		free(text);
		return (0);
	}

	free(text);
	close(file);

	return (w);
}
