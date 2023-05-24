#include "shell.h"

/**
 * _eputs - Writes a string to standard error
 * @str: Pointer to the string to be written
 *
 * Description: This function writes the string,
* @str to standard error.
 * If @str is NULL, the function does nothing.
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
 * _eputchar - Writes a character to standard error
 * @c: The character to be written
 *
 * Return: Always 1 (success)
 *
 * Description: This function writes the character ,
*@c to standard error.
 * If @c is BUF_FLUSH or if the internal buffer is full,
* (reached WRITE_BUF_SIZE),
 * the buffer contents are written to standard,
* error using the write system call.
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
* @c: The character to be written
* @fd: The file descriptor
* Return: Always 1 (success)
* Description: This function writes the character,
* @c to the file descriptor @fd.
* If @c is BUF_FLUSH or if the internal buffer is full,
* (reached WRITE_BUF_SIZE),
* the buffer contents are written to the file descriptor,
* using the write system call.
*/
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - Writes a string to a file descriptor
 * @str: Pointer to the string to be written
 * @fd: The file descriptor
 * Return: The number of characters written
 * Description: This function writes the string,
 * @str to the file descriptor @fd.
 * If @str is NULL, the function returns 0. Otherwise,
 *it iterates through the string
 *and calls _putfd for each character,
 *accumulating the number of characters written.
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}

