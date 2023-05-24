#include "main.h"
#include "stdio.h"
#include <unistd.h>
#include <stdlib.h>
extern char **environ;

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
<<<<<<< HEAD
	char *lineptr, **words;
	char ** env = environ;
	extern char ** environ;
	size_t i;
	char *path;
=======
	char *line = NULL, *del = " \n";
	size_t i = 0;
>>>>>>> 671bdf8c91cc44943396c53e1d188a791653c134

	if (isatty(STDIN_FILENO))
	{
<<<<<<< HEAD
		_puts("($) ");
		lineptr = _read_line();
		words = _split(lineptr, " ");

		_fork_fun(words , argv, environ, lineptr, getpid(), 0);

		for (i = 0; words[i] != NULL; i++)
=======
		(void)argc;
		while (1)
>>>>>>> 671bdf8c91cc44943396c53e1d188a791653c134
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
<<<<<<< HEAD
		free(lineptr);
		_free_words(words);
		/*call _get_path function */
		path = _get_path(env);
		if (path != NULL)
		{
			_puts("PATH variable value: ");
			_puts(path);
			_puts("\n");
			free(path);
		}
=======
>>>>>>> 671bdf8c91cc44943396c53e1d188a791653c134
	}
	else
	{
		if (argc != 2)
			return (-1);
	}
	free(line);
	return (0);
}
