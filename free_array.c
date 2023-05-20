#include "main.h"

/**
 * _free_words - Frees an array of strings
 * @arry: array of strings
 *
 * Description: Uses a for loop and free
 * Return: nothing
 */

void _free_words(char **arry)
{
	size_t i;

	if (arry != NULL)
	{
		for (i = 0; arry[i] != NULL; i++)
			free(arry[i]);
		free(arry);
	}
}
