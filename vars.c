#include "shell.h"

/**
 * is_chain - Test current chain
 * @kay: its parameter struct
 * @buff: the character buffer
 * @p: address of current position in the buffer
 *
 * Return: 1 if its chain delimeter, 0 otherwise
 */
int is_chain(kay_t *kay, char *buff, size_t *p)
{
        size_t j = *p;

        if (buff[j] == '|' && buff[j + 1] == '|')
        {
                buff[j] = 0;
                j++;
                kay->cmd_buff_type = CMD_OR;
        }
        else if (buff[j] == '&' && buff[j + 1] == '&')
        {
                buff[j] = 0;
                j++;
                kay->cmd_buff_type = CMD_AND;
        }
        else if (buff[j] == ';') 
        {
                buff[j] = 0; 
                kay->cmd_buff_type = CMD_CHAIN;
        }
        else
                return (0);
        *p = j;
        return (1);
}

/**
 * check_chain - checks that we should chain based on last statuses
 * @kay: the parameter struct
 * @buf: the char buffer
 * @b: address of current position in buf
 * @z: starting position in buf
 * @length: length of buf
 *
 * Return: Is Void
 */
void check_chain(kay_t *kay, char *buf, size_t *b, size_t z, size_t length)
{
        size_t j = *b;

        if (kay->cmd_buf_type == CMD_AND)
        {
                if (kay->status)
                {
                        buf[z] = 0;
                        j = len;
                }
        }
        if (kay->cmd_buf_type == CMD_OR)
        {
                if (!kay->status)
                {
                        buf[z] = 0;
                        j = length;
                }
        }

        *b = j;
}

/**
 * replace_alias - replaces the token string
 * @kay: the parameter of struct
 *
 * Return: 1 if its replaced, 0 otherwise
 */
int replace_alias(kay_t *kay)
{
        int i;
        list_t *node;
        char *p;

        for (i = 0; i < 10; i++)
        {
                node = node_starts_with(kay->alias, kay->argv[0], '=');
                if (!node)
                        return (0);
                free(kay->argv[0]);
                p = _strchr(node->str, '=');
                if (!p)
                        return (0);
                p = _strdup(p + 1);
                if (!p)
                        return (0);
                kay->argv[0] = p;
        }
        return (1);
}

/**
 * replace_vars - replaces all vars in the tokenized string presented
 * @kay: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(info_t *info)
{
        int i = 0;
        list_t *kay;

        for (i = 0; kay->argv[i]; i++)
        {
                if (kay->argv[i][0] != '$' || !kay->argv[i][1])
                        continue;

                if (!_strcmp(kay->argv[i], "$?"))
                {
                        replace_string(&(kay->argv[i]),
                                _strdup(convert_number(kay->status, 10, 0)));
                        continue;
                }
                if (!_strcmp(kay->argv[i], "$$"))
                {
                        replace_string(&(kay->argv[i]),
                                _strdup(convert_number(getpid(), 10, 0)));
                        continue;
                }
                node = node_starts_with(kay->env, &kay->argv[i][1], '=');
                if (node)
                {
                        replace_string(&(kay->argv[i]),
                                _strdup(_strchr(node->str, '=') + 1));
                        continue;
                }
                replace_string(&kay->argv[i], _strdup(""));

        }
        return (0);
}
/**
 * replace_string - replaces each string
 * @kay: address of old string
 * @edwin: is the new string
 *
 * Return: 1 if it will be replaced by, 0 otherwise do not
 */
int replace_string(char **kay, char *edwin)
{
        free(*kay);
        *kay = edwin;
        return (1);
}
