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
	int status;

	if (args == NULL)
		return;
	child = fork();

	if (child == -1)
	{
		perror("Error forking");
		return;
	}
	if (child == 0)
	{
		cmd = args[0];
		if (execve(cmd, args, NULL) == -1)
		{
			perror("Error:");
			return;
		}
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("Failure wait");
			return;
		}
		if (!WIFEXITED(status))
		{
			write(STDOUT_FILENO, args[0], 1);
			return;
		}
	}
}

