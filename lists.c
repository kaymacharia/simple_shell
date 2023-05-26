#include "shell.h"

/**
 * add_node - adds node to the start
 * @head: address the pointer of the head node
 * @str: string field of node
 * @num: node index used in by the history
 * Return: size to the list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *kay_head;

	if (!kay)
		return (NULL);
	kay_head = malloc(sizeof(list_t));
	if (!kay_head)
		return (NULL);
	_memset((void *)kay_head, 0, sizeof(list_t));
	kay_head->num = num;
	if (str)
	{
		kay_head->str = _strdup(str);
		if (!kay_head->str)
		{
			free(kay_head);
			return (NULL);
		}
	}
	kay_head->next = *head;
	*head = kay_head;
	return (kay_head);
}

/**
 * add_node_end - adds a node of end of the list
 * @head: the address of the pointer to head node
 * @str: string field of node
 * @num: index used in history
 * Return: size list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *kay_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	kay_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)kay_node, 0, sizeof(list_t));
	kay_node->num = num;
	if (str)
	{
		kay_node->str = _strdup(str);
		if (!kay_node->str)
		{
			free(kay_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = kay_node;
	}
	else
		*head = kay_node;
	return (kay_node);
}

/**
 * print_list_str - writes string on the element of a list_t linked list
 * @h: pointer to the first node
 * Return: size of the list
 */
size_t print_list_str(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * delete_node_at_index - deletes index
 * @head: first node
 * @index: index node to delete
 * Return: 1 success, 0 failure
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - frees all nodes in a list
 * @head_ptr: address pointer head node
 * Return: mark it as void
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}
