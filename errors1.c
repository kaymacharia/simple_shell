#include "shell.h"

/**
 * _erratoi - converts the string to an integer
 * @s: the string to be converted
 * Return: 0 which is if no numbers in the string or converted number 
 *       otherwise -1 on error
 */
int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - outputs an error message
 * @info: the parameter and the return info structure
 * @estr: string has specified error types
 * Return: 0 if no numbers in string and also converted number otherwise
 *        -1 on the error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
<<<<<<< HEAD
 * print_d - the functions prints (integer) number which is (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
=======
 * print_d - Prints an integer to a file descriptor
 * @input: The integer to print
 * @f_d: The file descriptor to write to
>>>>>>> b4f67ad8ff710598fef74eb3f125ad24982b3ec7
 *
 * Return: number of characters printed
 */
int print_d(int input, int f_d)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (f_d == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
<<<<<<< HEAD
 * convert_number - converter function, a clone of its own number
 * @num: number
 * @base: base
 * @flags: argument flags
=======
 * convert_number - Converts a number to a string representation
 * @number: The number to convert
 * @base: The base to use for conversion
 * @flags: Conversion flags
>>>>>>> b4f67ad8ff710598fef74eb3f125ad24982b3ec7
 *
 * Return: string
 */
char *convert_number(long int number, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = number;

	if (!(flags & CONVERT_UNSIGNED) && number < 0)
	{
		n = -number;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - the function gets the first instance of '#' with '\0'
 * @buf: talks to the string being modified
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
