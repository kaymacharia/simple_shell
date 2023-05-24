#include "shell.h"

#define MAX_COMMAND_LENGTH 100

/**
 * main - Entry point for the shell program
 *
 * Description: Displays a prompt and waits for the user to enter a command.
 *              The command is executed, and the prompt is displayed again.
 *              Supports exiting the shell and handles errors.
 *
 * Return: Always returns 0
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	int status;

	while (1)
	{
		printf("simple_shell$ ");
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
				printf("Child process exited with status %d\n", exit_status);
			}
		}
	}

	return (0);
}
