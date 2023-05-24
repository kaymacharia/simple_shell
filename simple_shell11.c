#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ARGS 5

int execute_command(char* command) {
	char* trimmed_command = command;
	while(*trimmed_command == ' ' || *trimmed_command == '\t') {
		trimmed_command++;
	}

	size_t command_length = strlen(trimmed_command);
	if(command_length > 0 && trimmed_command[command_length - 1] == '\n') {
		trimmed_command[command_length - 1] = '\0';
	}

	if(*trimmed_command == '\0') {
		return 0;
	}

	char* args[MAX_ARGS];
	int num_args = 0;

	char* token = strtok(trimmed_command, " \t");

	while(token != NULL && num_args < MAX_ARGS - 1) {
		args[num_args++] = token;
		token = strtok(NULL, " \t");
	}

	args[num_args] = NULL;

	if(strcmp(args[0], "setenv") == 0) {
		if(num_args < 3) {
			fprintf(stderr, "Invalid command syntax: setenv VARIABLE VALUE\n");
			return 0;
		}

		if(setenv(args[1], args[2], 1) == -1) {
			fprintf(stderr, "Failed to set environment variable\n");
		}
	}
	else if(strcmp(args[0], "unsetenv") == 0) {
		if(num_args < 2) {
			fprintf(stderr, "Invalid command syntax: unsetenv VARIABLE\n");
			return 0;
		}

		if(unsetenv(args[1]) == -1) {
			fprintf(stderr, "Failed to unset environment variable\n");
		}
	}
	else {
		pid_t pid = fork();

		if(pid == 0) {
			execvp(args[0], args);
			char error_command[256];
			snprintf(error_command, sizeof(error_command), "Invalid command: %s\n", args[0]);
			write(STDOUT_FILENO, error_command, strlen(error_command));
			exit(1);
		}
		else {
			wait(NULL);
		}
	}

	return 1;
}

int main() {
	char prompt[] = "> ";
	char command[256];
	char error_message[] = "Invalid command:";
	char exit_message[] = "Goodbye till we meet again!";

	while(1) {
		write(STDOUT_FILENO, prompt, sizeof(prompt)-1);

		if(fgets(command, sizeof(command), stdin) == NULL) {
			write(STDOUT_FILENO, "\n", 1);
			write(STDOUT_FILENO, exit_message, sizeof(exit_message)-1);
			exit(0);
		}

		char* trimmed_command = command;
		while(*trimmed_command == ' ' || *trimmed_command == '\t') {
			trimmed_command++;
		}

		char* command_token = strtok(trimmed_command, ";");
		while(command_token != NULL) {
			if(!execute_command(command_token)) {
				char error_command[256];
				snprintf(error_command, sizeof(error_command), "%s %s\n", error_message, command_token);
				write(STDOUT_FILENO, error_command, strlen(error_command));
			}
			command_token = strtok(NULL, ";");
		}
	}

	return 0;
}
