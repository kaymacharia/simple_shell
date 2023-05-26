#include "shell.h"

/**
<<<<<<< HEAD
 * main - entry of point
 * @ac: argument count
 * @av: argument vector
 * Return: 0 success, 1 error
=======
 * main - Entry point of the shell program
 * @ab: Number of command-line arguments
 * @cd: Array of command-line arguments
 * Return: EXIT_SUCCESS on success,
 * or EXIT_FAILURE on failure
>>>>>>> b4f67ad8ff710598fef74eb3f125ad24982b3ec7
 */
int main(int ab, char **cd)
{
<<<<<<< HEAD
	info_t info[] = { INFO_INIT };
	int fd = 2;
=======
	info_t inf[] = {INFO_INIT};
	int f_d = 2;
>>>>>>> b4f67ad8ff710598fef74eb3f125ad24982b3ec7

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
<<<<<<< HEAD
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
=======

	populate_env_list(inf);
	read_history(inf);
	hsh(inf, cd);

>>>>>>> b4f67ad8ff710598fef74eb3f125ad24982b3ec7
	return (EXIT_SUCCESS);
}
