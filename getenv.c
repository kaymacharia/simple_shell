#include "shell.h"

/**
 * get_environ - Retrieves the environment variables as an array of strings
 * @info: Pointer to the info_t struct
 *
 * Return: The array of environment variables
 */
char **get_environ(info_t *info)
{
	if (!info->environ_environ || info->env_changed)
	{
		info->environ_environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ_environ);
}

/**
 * _unsetenv - Removes an environment variable from the list
 * @info: Pointer to the info_t struct
 * @var: The environment variable to remove
 *
 * Return: 1 if the environment was changed, 0 otherwise
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * _setenv - Sets or modifies an environment variable
 * @info: Pointer to the info_t struct
 * @var: The environment variable to set or modify
 * @value: The value to assign to the environment variable
 *
 * Return: 0 on success, 1 on failure
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
