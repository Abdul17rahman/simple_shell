#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * execmd - execute a command
 * @argv: char pointer to pointer - holds an array of commands
 *
 * Description: This function executes commands that are entered by the user,
 * supporting input/output redirection.
 * Return: void
 */
void execmd(char **argv)
{
	char *cmd = NULL;
	int excmd;
	int input_fd = STDIN_FILENO;  /* default to stdin */
	int output_fd = STDOUT_FILENO;  /* default to stdout */
	int i;

	if (argv)
	{
		cmd = argv[0];

		/* Check if input redirection symbol '<' is present */
		for (i = 0; argv[i] != NULL; i++)
		{
			if (strcmp(argv[i], "<") == 0)
			{
				/* Open the specified input file */
				input_fd = open(argv[i + 1], O_RDONLY);
				if (input_fd == -1)
				{
					perror("open");
					return;
				}

				/* Remove the input redirection symbols from the argument list */
				argv[i] = NULL;
				argv[i + 1] = NULL;
				break;
			}
		}

		/* Check if output redirection symbol '>' is present */
		for (i = 0; argv[i] != NULL; i++)
		{
			if (strcmp(argv[i], ">") == 0)
			{
				/* Open the specified output file */
				output_fd = open(argv[i + 1], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
				if (output_fd == -1)
				{
					perror("open");
					return;
				}

				/* Remove the output redirection symbols from the argument list */
				argv[i] = NULL;
				argv[i + 1] = NULL;
				break;
			}
		}

		/* Redirect input/output to the specified file descriptors */
		if (dup2(input_fd, STDIN_FILENO) == -1)
		{
			perror("dup2");
			return;
		}
		if (dup2(output_fd, STDOUT_FILENO) == -1)
		{
			perror("dup2");
			return;
		}

		excmd = execvp(cmd, argv);

		if (excmd == -1)
		{
			perror("./shell");
		}

		/* Close the input/output files if they were opened */
		if (input_fd != STDIN_FILENO)
			close(input_fd);
		if (output_fd != STDOUT_FILENO)
			close(output_fd);
	}
}

