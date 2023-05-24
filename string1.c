#include "shell.h"

/**
 * _strcpy - Copies a string.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: Pointer to the destination string.
 *
 * Description: This function copies the string from source to destination.
 * It returns a pointer to the destination string.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == NULL)
		return (dest);

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - Duplicates a string.
 * @str: The string to duplicate.
 *
 * Return: Pointer to the duplicated string.
 *
 * Description: This function duplicates a string by allocating memory
 * and copying the contents of the original string. It returns a pointer
 * to the duplicated string. If memory allocation fails or if the input
 * string is NULL, it returns NULL.
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);

	while (*str++)
		length++;

	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);

	for (length++; length--;)
		ret[length] = *--str;

	return (ret);
}

/**
 * _puts - Prints a string to stdout.
 * @str: The string to be printed.
 *
 * Return: Nothing.
 *
 * Description: This function prints the given string to the standard output.
 * If the input string is NULL, it does nothing.
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}
/**
 * _putchar - Writes a character to stdout.
 * @c: The character to print.
 *
 * Return: On success, 1.
 * On error, -1 is returned, and errno is set appropriately.
 *
 * Description: This function writes a character to the standard output.
 * If the input character is BUF_FLUSH or if the buffer is full,
 * it flushes the buffer by writing its contents to stdout.
 * It returns 1 on success.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}

	if (c != BUF_FLUSH)
		buf[i++] = c;

	return (1);
}
