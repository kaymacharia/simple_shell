#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char prompt[] = "> ";  // Define the shell prompt
	char command[256];  // Buffer to store the entered command
	char error_message[] = "Invalid command:";  // Error message to display for invalid commands
	char exit_message[] = "Goodbye till we meet again!";  // Exit message to display when terminating the shell

	while (1) {
		// Display the shell prompt
		write(STDOUT_FILENO, prompt, sizeof(prompt)-1);

		if (fgets(command, sizeof(command), stdin) == NULL) {
			// Check for "end of file" condition (Ctrl+D) and exit the shell
			write(STDOUT_FILENO, "\n", 1);
			write(STDOUT_FILENO, exit_message, sizeof(exit_message)-1);
			exit(0);
		}

		// Remove trailing newline character from the entered command
		command[strcspn(command, "\n")] = '\0';

		if (command[0] == '\0') {
			continue;  // Ignore empty commands and prompt for the next command
		}

		char *arg = command;  // Pointer to track the argument in the command

		// Find the end of the command, marking the start of the argument
		while (*arg != ' ' && *arg != '\t' && *arg != '\0') {
			arg++;
		}

		if (*arg != '\0') {
			*arg = '\0';  // Null-terminate the command to separate it from the argument
			arg++;  // Move to the start of the argument
		}

		pid_t pid = fork();  // Fork a new process

		if (pid == 0) {  // Child process
			// Execute the command using the `execlp` function
			execlp(command, command, arg, NULL);

			// If the command doesn't exist, display an error message and exit the child process
			char error_command[256];
			snprintf(error_command, sizeof(error_command), "%s %s\n", error_message, command);
			write(STDOUT_FILENO, error_command, strlen(error_command));
			exit(1);
		} else {
			wait(NULL);  // Wait for the child process to finish executing the command
		}
	}

	return 0;
}
