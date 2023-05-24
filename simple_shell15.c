#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 5
#define MAX_ALIASES 10
#define MAX_ALIAS_NAME 20
#define MAX_ALIAS_VALUE 100

typedef struct {
	char name[MAX_ALIAS_NAME];
	char value[MAX_ALIAS_VALUE];
} Alias;

Alias aliases[MAX_ALIASES];
int num_aliases = 0;

int execute_command(char* command) {
	char* trimmed_command = command;
	while (*trimmed_command == '\t') {
		trimmed_command++;
	}

	size_t command_length = strlen(trimmed_command);
	if (command_length > 0 && trimmed_command[command_length - 1] == '\n') {
		trimmed_command[command_length - 1] = '\0';
	}

	if (*trimmed_command == '\0' || *trimmed_command == '#') {
		return 1; // Ignore empty lines and comments
	}

	char* args[MAX_ARGS];
	int num_args = 0;

	char* token = strtok(trimmed_command, "\t");

	while (token != NULL && num_args < MAX_ARGS - 1) {
		args[num_args++] = token;
		token = strtok(NULL, "\t");
	}

	args[num_args] = NULL;

	// Rest of the code remains the same
	// ...

	return 1;
}

int main() {
	char prompt[] = ">";
	char command[256];
	char error_message[] = "Invalid command:";
	char exit_message[] = "Goodbye till we meet again!";

	while (1) {
		write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);

		if (fgets(command, sizeof(command), stdin) == NULL) {
			write(STDOUT_FILENO, "\n", 1);
			write(STDOUT_FILENO, exit_message, sizeof(exit_message) - 1);
			exit(0);
		}

		char* trimmed_command = command;
		while (*trimmed_command == '\t') {
			trimmed_command++;
		}

		char* command_token = strtok(trimmed_command, ";");
		while (command_token != NULL) {
			if (!execute_command(command_token)) {
				fprintf(stderr, "%s %s\n", error_message, command_token);
			}
			command_token = strtok(NULL, ";");
		}
	}

	return 0;
}
