#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * append_text_to_file - Function to append text at the end of a file.
 * @filename: A pointer to the filename.
 * @text_content: The string to be added.
 *
 * Return: 1 on success and -1 on failure.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int file, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	file = open(filename, O_WRONLY | O_APPEND);
	w = write(file, text_content, len);

	if (file == -1 || w == -1)
		return (-1);

	close(file);

	return (1);
}
