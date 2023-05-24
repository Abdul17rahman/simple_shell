#include "main.h"

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: Pointer to the resulting string.
 */
char *_strcat(char *dest, const char *src)
{
	char *dest_ptr = dest;
	const char *src_ptr = src;

	while (*dest_ptr != '\0')
		dest_ptr++;

	while (*src_ptr != '\0')
	{
		*dest_ptr = *src_ptr;
		dest_ptr++;
		src_ptr++;
	}

	*dest_ptr = '\0';

	return (dest);
}
/**
 * _strcmp - Compares the values of two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: An integer less than, equal to, or greater than zero if s1 is found
 *         to be less than, equal to, or greater than s2, respectively.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);

		s1++;
		s2++;
	}

	return (*s1 - *s2);
}
/**
 * _strlen - Calculates the length of a string.
 * @s: A pointer to the string.
 *
 * Return: The length of the string.
 */
int _strlen(const char *s)
{
	const char *ptr = s;
	int length = 0;

	while (*ptr != '\0')
	{
		length++;
		ptr++;
	}

	return (length);
}
/**
 * _strncmp - Compares two strings up to a given number of characters.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * @n: The maximum number of characters to compare.
 *
 * Return: The difference between the first differing characters.
 */
size_t _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n && s1[i] == s2[i] && s1[i] != '\0'; i++)
		;

	if (i == n)
		return (0);

	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/**
 * _strcpy - Copies the string pointed to by src into dest.
 * @dest: The destination of the copy.
 * @src: The source of the copy.
 *
 * Return: A pointer to dest.
 */
char *_strcpy(char *dest, const char *src)
{
	char *ptr = dest;

	while (*src != '\0')
	{
		*ptr++ = *src++;
	}

	*ptr = '\0';

	return (dest);
}
