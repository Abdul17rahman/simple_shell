#include "main.h"

/**
 * _read_line - Reads the line.
 *
 * Description: Function reads a line using getline
 * Return: the line as a string
 */
char *_read_line(void)
{
	size_t buffer_size = 0;
	char *line = NULL;

	if (getline(&line, &buffer_size, stdin) < 0)
	{
		return (NULL);
	}
	return (line);
}
