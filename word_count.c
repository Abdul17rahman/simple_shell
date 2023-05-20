#include "main.h"

/**
 * word_count - Counts the words in a string
 * @s: s is the string to count
 * @del: seperator/delimeter
 *
 * Description: Uses a loop to calculate the words
 * Return: Number of words
 */

size_t word_count(char *s, char *del)
{
	size_t count = 0;
	char *word, *copy;

	if (s == NULL)
		return (0);
	copy = _strdup(s);
	word = strtok(copy, del);

	while (word != NULL)
	{
		count++;
		word = strtok(NULL, del);
	}
	free(copy);
	return (count);
}
