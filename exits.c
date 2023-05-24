#include "shell.h"

/**
 * _strncpy - Copies a string up to a certain number of characters
 * @dest: Destination buffer
 * @src: Source string
 * @n: Maximum number of characters to copy
 * Return: Pointer to the destination buffer
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * _strncat - Concatenates a string up to a certain number of characters
 * @dest: Destination buffer
 * @src: Source string
 * @n: Maximum number of characters to concatenate
 * Return: Pointer to the destination buffer
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 * _strchr - Locates the first occurrence of a character in a string
 * @s: Input string
 * @c: Character to search for
 * Return: Pointer to the first occurrence of the character,
 * or NULL if not found
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
