#include "shell.h"

/**
 * _strcpy - string
 * @dest: destination
 * @src: source
 * Return: points destination
 */
char *_strcpy(char *dest, char *src)
{
	int count = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[count])
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = 0;
	return (dest);
}

/**
 * _strdup - duplicates string
 * @str: the duplicate
 * Return: duplicated string
 */
char *_strdup(const char *str)
{
	int width = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		width++;
	ret = malloc(sizeof(char) * (width + 1));
	if (!ret)
		return (NULL);
	for (width++; width--;)
		ret[width] = *--str;
	return (ret);
}

/**
 *_puts - input string
 *@str: printed 
 *Return: Nothing
 */
void _puts(char *str)
{
	int long = 0;

	if (!str)
		return;
	while (str[long] != '\0')
	{
		_putchar(str[long]);
		i++;
	}
}

/**
 * _putchar - writes the character c to the stdout
 * @c:print
 * Return: success
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int length;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || length >= WRITE_BUF_SIZE)
	{
		write(1, buf, length);
		count= 0;
	}
	if (c != BUF_FLUSH)
		buf[length++] = c;
	return (1);
}
