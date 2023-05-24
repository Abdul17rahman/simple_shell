#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * main - test shell
 * @argc: argument count
 * @argv: array of arguments
 *
 * Description: uses all function and sys calls
 * Return: 0
 */
int main(__attribute__((unused)) int argc, char *argv[])
{
	char *lineptr, **words;
	extern char ** environ;
	size_t i;

	while (1)
	{
		_puts("($) ");
		lineptr = _read_line();
		words = _split(lineptr, " ");

		 _fork_fun(words , argv, environ, lineptr, getpid(), 0);

		for (i = 0; words[i] != NULL; i++)
		{
			_puts(words[i]);
		}
		free(lineptr);
		_free_words(words);
	}
	return (0);
}
