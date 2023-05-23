#include "main.h"
#include <sys/wait.h>
/**
 * _fork_fun - function that creates a fork
 *@arg: command and values PATH
 *@av: name of our program
 *@env: environment
 *@lineptr: command line for the user
 *@np: id of proces
 *@c: Checker add new test
 *Return: Return 0 on suceess of the function
 */

int _fork_fun(char **arg, char **av, char **env, char *lineptr, int np, int c)
{
	pid_t child  = fork();

	if (child == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (child == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(stderr, "%s: %d: %s: not found\n", av[0], np, arg[0]);
			if (!c)
				free(arg[0]);
						free(lineptr);
						exit(EXIT_FAILURE);
		}
		else
		{
			int status;

			waitpid(child, &status, 0);
			if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
				return (WEXITSTATUS(status));
		}
	}
	return (0);
}

