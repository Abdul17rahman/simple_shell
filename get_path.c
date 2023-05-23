#include "main.h"
/**
 * _get_path - This function gets the value of the  PATH variable
 * @env: The environment variable
 * Return: The value of the PATH Variable
 */

char *_get_path(char **env)
{
	size_t index = 0, var = 0, counter = 0;
	char *path = NULL;
	while (env[index] != NULL)
	{
		if (strncmp(env[index], "PATH=", 5) == 0)
			break;
		index++;
	}
	if (env[index] == NULL)
		return (NULL);
	counter = _strlen(env[index]) - 5;
	path = malloc(sizeof(char) * (counter + 1));

	if (path == NULL)
		return (NULL);

	for (var = 5; env[index][var] != '\0'; var++, counter++)
		path[counter] = env[index][var];

	path[counter] = '\0';
	return (path);
}
