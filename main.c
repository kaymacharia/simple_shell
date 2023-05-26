#include "shell.h"

/**
 * main - Entry point of the shell program
 * @ab: Number of command-line arguments
 * @cd: Array of command-line arguments
 * Return: EXIT_SUCCESS on success,
 * or EXIT_FAILURE on failure
 */
int main(int ab, char **cd)
{
	info_t inf[] = {INFO_INIT};
	int f_d = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (f_d)
		: "r" (f_d));

	if (ab == 2)
	{
		f_d = open(cd[1], O_RDONLY);
		if (f_d == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(cd[0]);
				_eputs(": 0: Can't open ");
				_eputs(cd[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		inf->readfd = f_d;
	}

	populate_env_list(inf);
	read_history(inf);
	hsh(inf, cd);

	return (EXIT_SUCCESS);
}
