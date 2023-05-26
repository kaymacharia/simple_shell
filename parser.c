#include "shell.h"

/**
 * is_cmd - determines executable command
 * @info: info struct
 * @path: path of file
 * Return: 1 or, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - duplicates char
 * @pathstr: PATH string
 * @start: start index
 * @stop: stop index
 * Return: show new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int count = 0, k = 0;

	for (k = 0, count = start; count < stop; count++)
		if (pathstr[count] != ':')
			buf[k++] = pathstr[count];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - finds this cmd in the PATH string
 * @info: information struct
 * @pathstr: the path string
 * @cmd: cmd find
 * Return: NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int count = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[count] || pathstr[count] == ':')
		{
			path = dup_chars(pathstr, curr_pos, count);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[count])
				break;
			curr_pos = count;
		}
		count++;
	}
	return (NULL);
}
