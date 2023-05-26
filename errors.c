#include "shell.h"

/**
 * _eputs - Writes a string to the standard error
 * @str: The string to write
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - Writes a character to the standard error
 * @c: The character to write
 *
 * Return: 1 on success
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - Writes a character to a file descriptor
 * @c: The character to write
 * @f_d: The file descriptor to write to
 *
 * Return: 1 on success
 */
int _putfd(char c, int f_d)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(f_d, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - Writes a string to a file descriptor
 * @str: The string to write
 * @f_d: The file descriptor to write to
 *
 * Return: The number of characters written
 */
int _putsfd(char *str, int f_d)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, f_d);
	}
	return (i);
}
