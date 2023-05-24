#include "main.h"

/**
 * _split - splits a string.
 * @str: the string to be splited
 * @del: delimeter/seperator for the string
 *
 * Description: Function splits the words passed in str
 * Return: an array of each word
 */
char **_split(char *str, char *del)
{
	size_t nwords, j = 0;
	char *copy, *word, **words;

	if (str == NULL || *str == '\0')
		return (NULL);
	copy = _strdup(str);
	nwords = word_count(str, del);
	words = malloc((nwords + 1) * sizeof(char *));
	word = strtok(copy, del);

	if (words == NULL)
	{
		free(copy);
		return (NULL);
	}
	while (word != NULL && j < nwords)
	{
		words[j] = _strdup(word);
		word = strtok(NULL, del);
		j++;
	}
	words[nwords] = NULL;

	free(copy);
	return (words);
}
