#include "shell.h"

/**
 * list_len - Calculates the length of a linked list
 * @h: Pointer to the head of the list
 * Return: Length of the list
 */
size_t list_len(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - Converts a linked list of strings to an array of strings
 * @head_p: Pointer to the head of the list
 * Return: Pointer to the array of strings, or NULL on failure
 */
char **list_to_strings(list_t *head_p)
{
	list_t *node = head_p;
	size_t i = list_len(head_p), j;
	char **strs;
	char *str;

	if (!head_p || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}
		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * print_list - Prints the contents of a linked list
 * @h: Pointer to the head of the list
 * Return: Number of nodes in the list
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->number, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - Finds a node with a string,
 * that starts with a given prefix
 * @node: Pointer to the head of the list
 * @prefix: Prefix to match
 * @c: Character to match (-1 to match any character)
 * Return: Pointer to the found node, or NULL if not found
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - Gets the index of a node in a linked list
 * @head_p: Pointer to the head of the list
 * @node: Pointer to the node
 * Return: Index of the node, or -1 if not found
 */
ssize_t get_node_index(list_t *head_p, list_t *node)
{
	size_t i = 0;

	while (head_p)
	{
		if (head_p == node)
			return (i);
		head_p = head_p->next;
		i++;
	}
	return (-1);
}
