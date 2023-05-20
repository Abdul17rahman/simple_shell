#include "main.h"

/**
 * main - test shell
 * @argc: argument count
 * @argv: array of arguments
 *
 * Description: uses all function and sys calls
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *lineptr, **words;
	size_t i;
	(void)argc;
	(void)argv;

	while (1)
	{
		_puts("($) ");
		lineptr = _read_line();
		words = _split(lineptr, " ");
		for (i = 0; words[i] != NULL; i++)
		{
			_puts(words[i]);
		}
		free(lineptr);
		_free_words(words);
	}
	return (0);
}
