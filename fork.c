#include "main.h"
#include <sys/wait.h>
/**
 * execute_cmd - function that creates a fork
 *@args: command and values PATH
 *
 *Return: Return 0 on suceess of the function
 */

void execute_cmd(char **args)
{
	pid_t child;
	char *cmd = NULL;

	if (args == NULL)
	{
		_puts("No commands\n");
		exit(EXIT_FAILURE);
	}
	child = fork();

	if (child == -1)
	{
		_puts("Error forking");
		exit(EXIT_FAILURE);
	}
	if (child == 0)
	{
		cmd = args[0];
		if (execve(cmd, args, NULL) == -1)
		{
			perror("Error:");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}

