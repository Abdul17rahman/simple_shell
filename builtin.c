#include "main.h"
/**
 * _exit_command - this function closes the simple_shell when
 * @arg: pointer with the direction argument.
 * @lineptr: standar input string
 * @_exit: value of exit
 * Return: None
 */
void _exit_command(char **arg, char *lineptr)
{
	int exit_status;

	if(strcmp(arg[0], "exit") == 0)
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
 *@env: enviroment
 *Return: 0
 */

void _getenv(char **env)
{
	size_t run = 0;

	while (env[run])
	{
		write(STDOUT_FILENO, env[run], _strlen(env[run]));
		write(STDOUT_FILENO, "\n", 1);
		run++;
	}
}
