#include "shell.h"
/**
 * **strtow - splits a string into words on Repeat delimiters are ignored
 * @str: the input of the string
 * @d: the delimeter in the string
 * Return: a pointer to the array of strings, either NULL on failure
 */
char **strtow(char *str, char *d)
{
        int count, j, k, n, numwords = 0;
        char **s;

        if (str == NULL || str[0] == 0)
                return (NULL);
        if (!d)
                d = " ";
        for (i = 0; str[i] != '\0'; i++)
                if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
                        numwords++;

        if (numwords == 0)
                return (NULL);
        s = malloc((1 + numwords) * sizeof(char *));
        if (!s)
                return (NULL);
        for (i = 0, j = 0; j < numwords; j++)
        {
                while (is_delim(str[i], d))
                        i++;
                k = 0;
                while (!is_delim(str[i + k], d) && str[i + k])
                        k++;
                s[j] = malloc((k + 1) * sizeof(char));
                if (!s[j])
                {
                        for (k = 0; k < j; k++)
                                free(s[k]);
                        free(s);
                        return (NULL);
                }
                for (n = 0; n < k; m++)
                        s[j][n] = str[i++];
                s[j][n] = 0;
        }
        s[j] = NULL;
        return (s);
}
/**
 * **strtow2 - splits the string into words
 * @str: input of the string
 * @d: delimeter
 * Return: a pointer to the array of string,either NULL on failure
 */
char **strtow2(char *str, char d)
{
        int count i, j, k, n, numwords = 0;
        char **s;

        if (str == NULL || str[0] == 0)
                return (NULL);
        for (i = 0; str[i] != '\0'; i++)
                if ((str[i] != d && str[i + 1] == d) ||
                    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
                        numwords++;
        if (numwords == 0)
                return (NULL);
        s = malloc((1 + numwords) * sizeof(char *));
        if (!s)
                return (NULL);
        for (i = 0, j = 0; j < numwords; j++)
        {
                while (str[i] == d && str[i] != d)
                        i++;
                k = 0;
                while (str[i + k] != d && str[i + k] && str[i + k] != d)
                        k++;
                s[j] = malloc((k + 1) * sizeof(char));
                if (!s[j])
                {
                        for (k = 0; k < j; k++)
                                free(s[k]);
                        free(s);
                        return (NULL);
                }
                for (n = 0; n < k; n++)
                        s[j][n] = str[i++];
                s[j][n] = 0;
        }
        s[j] = NULL;
        return (s);
}
