#include "main.h"

/**
 * _strcat - Concatenates a string
 * @dest: The destination variable
 * @src: Source pointer
 *
 * Description: Uses a for loop to concatenate the string
 * Return: a pointer to the string
 */

char *_strcat(char *dest, char *src)
{
	int i = strlen(dest);
	int n = strlen(src);
	int k, l;

	for (k = 0; k <= i; k++)
	{
		if (dest[k] == '\0')
		{
			for (l = 0; l <= n; l++)
			{
				dest[k] += src[l];
				k++;
			}
			dest[k] = '\0';
		}
	}
	return (dest);
}
