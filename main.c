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
	char **buffer;
	size_t buf_size = 0, i;
	(void)argc;

	buffer = (char **)malloc(buf_size * sizeof(char));
	if (!buffer)
	{
		_puts("Couldnt allocate memory : main");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		_puts("($) ");
		getline(buffer, &buf_size, stdin);
		argv = _split(*buffer, " ");
		for (i = 0; argv[i] != NULL; i++)
		{
			_puts(argv[i]);
		}
	}
	free(buffer);
}
