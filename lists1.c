#include "shell.h"

/**
 * list_len - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		h = h->next;
		count++;
	}
	return (count);
}

/**
<<<<<<< HEAD
 * list_to_strings - returns an array of strings of the list->str
 * @head: pointer to first node
 *
 * Return: array of strings
=======
 * list_to_strings - Converts a linked list of strings to an array of strings
 * @head_p: Pointer to the head of the list
 * Return: Pointer to the array of strings, or NULL on failure
>>>>>>> b4f67ad8ff710598fef74eb3f125ad24982b3ec7
 */
char **list_to_strings(list_t *head_p)
{
<<<<<<< HEAD
	list_t *node = head;
	size_t count = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !count)
=======
	list_t *node = head_p;
	size_t i = list_len(head_p), j;
	char **strs;
	char *str;

	if (!head_p || !i)
>>>>>>> b4f67ad8ff710598fef74eb3f125ad24982b3ec7
		return (NULL);
	strs = malloc(sizeof(char *) * (count + 1));
	if (!strs)
		return (NULL);
	for (count = 0; node; node = node->next, count++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < count; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[count] = str;
	}
	strs[count] = NULL;
	return (strs);
}


/**
 * print_list - prints all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		_puts(convert_number(h->number, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		count++;
	}
	return (count);
}

/**
 * node_starts_with - returns string starts on prefix
 * @node: list head
 * @prefix: string match
 * @c: the next character after prefix to match
 * Return: null
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
<<<<<<< HEAD
 * get_node_index - gets the index node
 * @head: pointer for list head
 * @node: pointer node
 * Return: index node or -1
=======
 * get_node_index - Gets the index of a node in a linked list
 * @head_p: Pointer to the head of the list
 * @node: Pointer to the node
 * Return: Index of the node, or -1 if not found
>>>>>>> b4f67ad8ff710598fef74eb3f125ad24982b3ec7
 */
ssize_t get_node_index(list_t *head_p, list_t *node)
{
	size_t count = 0;

	while (head_p)
	{
<<<<<<< HEAD
		if (head == node)
			return (count);
		head = head->next;
		count++;
=======
		if (head_p == node)
			return (i);
		head_p = head_p->next;
		i++;
>>>>>>> b4f67ad8ff710598fef74eb3f125ad24982b3ec7
	}
	return (-1);
}
