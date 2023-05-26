#include "shell.h"

/**
<<<<<<< HEAD
 * add_node - adds node to the start
 * @head: address the pointer of the head node
 * @str: string field of node
 * @num: node index used in by the history
 * Return: size to the list
=======
 * add_node - Adds a new node at the beginning of the list
 * @head_p: Pointer to the head of the list
 * @str: String to be added as a new node
 * @number: Line number of the node
 * Return: Pointer to the newly added node, or NULL on failure
>>>>>>> b4f67ad8ff710598fef74eb3f125ad24982b3ec7
 */
list_t *add_node(list_t **head_p, const char *str, int number)
{
	list_t *kay_head;

<<<<<<< HEAD
	if (!kay)
=======
	if (!head_p)
>>>>>>> b4f67ad8ff710598fef74eb3f125ad24982b3ec7
		return (NULL);
	kay_head = malloc(sizeof(list_t));
	if (!kay_head)
		return (NULL);
<<<<<<< HEAD
	_memset((void *)kay_head, 0, sizeof(list_t));
	kay_head->num = num;
=======
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->number = number;
>>>>>>> b4f67ad8ff710598fef74eb3f125ad24982b3ec7
	if (str)
	{
		kay_head->str = _strdup(str);
		if (!kay_head->str)
		{
			free(kay_head);
			return (NULL);
		}
	}
<<<<<<< HEAD
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
=======
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
>>>>>>> b4f67ad8ff710598fef74eb3f125ad24982b3ec7
 */
list_t *add_node_end(list_t **head_p, const char *str, int number)
{
	list_t *kay_node, *node;

	if (!head_p)
		return (NULL);

<<<<<<< HEAD
	node = *head;
	kay_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)kay_node, 0, sizeof(list_t));
	kay_node->num = num;
=======
	node = *head_p;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->number = number;
>>>>>>> b4f67ad8ff710598fef74eb3f125ad24982b3ec7
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
<<<<<<< HEAD
		*head = kay_node;
	return (kay_node);
=======
		*head_p = new_node;
	return (new_node);
>>>>>>> b4f67ad8ff710598fef74eb3f125ad24982b3ec7
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
<<<<<<< HEAD
 * delete_node_at_index - deletes index
 * @head: first node
 * @index: index node to delete
 * Return: 1 success, 0 failure
=======
 * delete_node_at_index - Deletes a node at a given index
 * @head_p: Pointer to the head of the list
 * @index: Index of the node to be deleted
 * Return: 1 if successful, 0 if index is out of range or list is empty
>>>>>>> b4f67ad8ff710598fef74eb3f125ad24982b3ec7
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
<<<<<<< HEAD
 * free_list - frees all nodes in a list
 * @head_ptr: address pointer head node
 * Return: mark it as void
=======
 * free_list - Frees the memory allocated for the list
 * @head_p_ptr: Pointer to the head of the list
>>>>>>> b4f67ad8ff710598fef74eb3f125ad24982b3ec7
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
