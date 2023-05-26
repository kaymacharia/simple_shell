#include "shell.h"

/**
 * add_node - Adds a new node at the beginning of the list
 * @head_p: Pointer to the head of the list
 * @str: String to be added as a new node
 * @number: Line number of the node
 * Return: Pointer to the newly added node, or NULL on failure
 */
list_t *add_node(list_t **head_p, const char *str, int number)
{
	list_t *new_head;

	if (!head_p)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->number = number;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head_p;
	*head_p = new_head;
	return (new_head);
}

/**
 * add_node_end - Adds a new node at the end of the list
 * @head_p: Pointer to the head of the list
 * @str: String to be added as a new node
 * @number: Line number of the node
 * Return: Pointer to the newly added node, or NULL on failure
 */
list_t *add_node_end(list_t **head_p, const char *str, int number)
{
	list_t *new_node, *node;

	if (!head_p)
		return (NULL);

	node = *head_p;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->number = number;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head_p = new_node;
	return (new_node);
}

/**
 * print_list_str - Prints the strings in the list
 * @h: Pointer to the head of the list
 * Return: Number of nodes in the list
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
 * delete_node_at_index - Deletes a node at a given index
 * @head_p: Pointer to the head of the list
 * @index: Index of the node to be deleted
 * Return: 1 if successful, 0 if index is out of range or list is empty
 */
int delete_node_at_index(list_t **head_p, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!head_p || !*head_p)
		return (0);

	if (!index)
	{
		node = *head_p;
		*head_p = (*head_p)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head_p;
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
 * free_list - Frees the memory allocated for the list
 * @head_p_ptr: Pointer to the head of the list
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head_p;

	if (!head_ptr || !*head_ptr)
		return;
	head_p = *head_ptr;
	node = head_p;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}
