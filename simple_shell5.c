#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;
// External variable to access the environment

int main() {
char prompt[] = "> ";
// Defining the shell prompt
char command[256];
//Store the entered command
char error_message[] = "Invalid command:";
// Error message to display for invalid commands
char exit_message[] = "Goodbye till we meet again!";
// Exit message to display when terminating the shell
char env_message[] = "Environment variables:";
// Message to display for the `env` command

while (1) {
// Display the shell prompt
write(STDOUT_FILENO, prompt, sizeof(prompt)-1);

if (fgets(command, sizeof(command), stdin) == NULL) {
// Check for "end of file" condition (Ctrl+D) and exit the shell
write(STDOUT_FILENO, "\n", 1);
write(STDOUT_FILENO, exit_message, sizeof(exit_message)-1);
exit(0);
}

command[strcspn(command, "\n")] = '\0';
// Remove trailing newline character from the entered command

if (command[0] == '\0') {
continue;
// Ignore empty commands and prompt for the next command
}

if (strcmp(command, "env") == 0) {
// Handle the `env` command to print the environment variables
write(STDOUT_FILENO, env_message, sizeof(env_message)-1);
write(STDOUT_FILENO, "\n", 1);

// Iterate through the environment variables and print them
for (char **env = environ; *env != NULL; env++) {
write(STDOUT_FILENO, *env, strlen(*env));
write(STDOUT_FILENO, "\n", 1);
}

continue;
// Prompt for the next command
}

pid_t pid = fork();
// Fork a new process

if (pid == 0) {  // Child process
// Execute the command using the `execlp` function
execlp(command, command, NULL);

// If the command doesn't exist, display an error message and exit
char error_command[256];
snprintf(error_command, sizeof(error_command), "%s %s\n", error_message, command);
write(STDOUT_FILENO, error_command, strlen(error_command));
exit(1);
} else {
wait(NULL);
// Wait for the child process to finish
}
}

return 0;
}
