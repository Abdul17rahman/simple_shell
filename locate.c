#include "main.h"
/**
 * _get_path_loc - This function gets the value of the  PATH variable
 * @com: command passed in
 * Return: The value of the PATH Variable
 */

char *_get_path_loc(char *com)
{
	size_t cmd_len, path_len;
	char *path, *absol_path, *cpy, *path_dir;
	struct stat buf_stat;

	cmd_len = _strlen(com);
	path = getenv("PATH");

	if (path)
	{
		cpy = _strdup(path);
		path_dir = strtok(cpy, ":");

		while (path_dir != NULL)
		{
			path_len = _strlen(path_dir);
			absol_path = (char *)malloc(cmd_len + path_len + 2);
			strcpy(absol_path, path_dir);
			_strcat(absol_path, "/");
			_strcat(absol_path, com);

			if (stat(absol_path, &buf_stat) == 0)
			{
				free(cpy);
				return (absol_path);
			}
			else
			{
				free(absol_path);
				path_dir = strtok(NULL, ":");
			}
		}
		free(cpy);

		if (stat(com, &buf_stat) == 0)
			return (com);
		return (NULL);
	}
	return (NULL);
}
