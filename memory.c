#include "shell.h"
/**
 * bfree - points NULLs of the address
 * @ptr: address pointer for free
 * Return: 1 freed or otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
