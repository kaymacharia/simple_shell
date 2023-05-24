#include "shell.h"

/**
 * _strlen - Returns the length of a string.
 * @s: The string whose length to check.
 *
 * Return: Integer length of the string.
 *
 * Description: This function calculates the length of the input string.
 * If the input string is NULL, it returns 0.
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;

	return (i);
}

/**
 * _strcmp - Performs lexicographic comparison of two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: Negative if s1 < s2, positive if s1 > s2, zero if s1 == s2.
 *
 * Description: This function compares,
 * the two input strings character by character.
 * If the characters at any position are different, it returns the difference
 * between their ASCII values. If the strings are equal, it returns 0.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}

	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - Checks if needle starts with haystack.
 * @haystack: The string to search.
 * @needle: The substring to find.
 *
 * Return: Address of the next character of haystack or NULL.
 *
 * Description: This function checks if the input string needle starts
 * with the string haystack. It returns a pointer to the next character
 * of haystack if needle starts with haystack, otherwise it returns NULL.
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
	{
		if (*needle++ != *haystack++)
			return (NULL);
	}

	return ((char *)haystack);
}

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination buffer.
 * @src: The source buffer.
 *
 * Return: Pointer to the destination buffer.
 *
 * Description: This function concatenates,
 * the string in src to the string in dest.
 * It returns a pointer to the destination buffer. The original content of dest
 * is modified and the resulting string is null-terminated.
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;

	while (*src)
		*dest++ = *src++;

	*dest = *src;
	return (ret);
}
