#include "main.h"

/**
 * _strdup - Creates space for a string
 * @str: string to copy
 *
 * Description: This function creates a space for the duplicate
 * Return: a pointer to the created array.
 */

char *_strdup(char *str)
{
	int i, len = _strlen(str);

	char *dup;

	dup = malloc(sizeof(char) * (len + 1));

	if (str == NULL)
		return (NULL);
	if (dup == NULL || dup < str)
		return (NULL);
	for (i = 0; i < len; i++)
	{
		dup[i] = str[i];
	}
	dup[i] = '\0';

	return (dup);


}
