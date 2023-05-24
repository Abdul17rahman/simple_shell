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
	char *line = NULL, *del = " \n", **args;
	size_t i = 0;
	ssize_t bytes;

	if (isatty(STDIN_FILENO))
	{
		(void)argc;
		while (1)
		{
			_puts("($) ");
			if (getline(&line, &i, stdin) == -1)
			{
				free(line);
				return (-1);
			}
			argv = _split(line, del);
			if (argv == NULL)
				return (-1);
			execute_cmd(argv);
			_free_words(argv);
		}
	}
	free(line);
	return (0);
}
