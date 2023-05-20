#include "main.h"

/**
 * _strlen - Counts the length of a string
 * @s: s is the string to count
 *
 * Description: Uses a for loop to calculate the length
 * Return: the length as an int
 */

int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}
