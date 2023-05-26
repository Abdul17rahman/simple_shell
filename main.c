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
	char *line = NULL, *del = " \n";
	size_t i = 0;
	ssize_t bytes;

	(void)argc;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			_puts("($) ");
			if (getline(&line, &i, stdin) == -1)
			{
				free(line);
				return (-1);
			}
			argv = _split(line, del);
			_exit_command(argv, line);
			_getenv(argv);
			execute_cmd(argv);
			_free_words(argv);
		}
	}
	else
	{
		bytes = getline(&line, &i, stdin);
		if (bytes == -1)
			return (-1);
		argv = _split(line, del);
		execute_cmd(argv);
		_free_words(argv);
	}
	free(line);
	return (0);
}
