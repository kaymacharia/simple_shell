#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

/**
 * Exits the shell
 *
 * This function is for exiting the shell program.
 * It can be called when the user enters the "exit" command.
 * It takes zero arguments and returns an exit status of zero.
 * Return: Always returns 0
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	int status;

	while (1)
	{
		printf("simple_shell$");
		fflush(stdout);

		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			printf("\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		pid_t pid = fork();

		if (pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execlp(command, command, NULL) < 0)
			{
				perror("execlp");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
			{
				int exit_status = WEXITSTATUS(status);
				printf
					("Child process exited with status %d\n", exit_status);
			}
		}
	}

	return (0);
}
