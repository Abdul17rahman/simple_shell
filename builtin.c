#include "main.h"
/**
 * _exit_command - this function closes the simple_shell when
 * @arg: pointer with the direction argument.
 * @lineptr: standar input string
 * Return: None
 */
void _exit_command(char **arg, char *lineptr)
{
	int exit_status;

	if (strcmp(arg[0], "exit") == 0)
	{
		if (arg[1] != NULL)
			exit_status = atoi(arg[1]);
		else
			exit_status = EXIT_SUCCESS;
		free(lineptr);
		_free_words(arg);
		exit(exit_status);
	}
}

/**
 *_getenv - function to get all env
 *@arg: enviroment
 *Return: 0
 */

int _getenv(char **arg)
{
	size_t run = 0;

	if (strcmp(arg[0], "env") == 0)
	{
		for (run = 0; environ[run] != NULL; run++)
		{
			_puts(environ[run]);
			_puts("\n");
		}
	}
	return (run);
}
