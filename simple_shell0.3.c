#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
char prompt[] = "> ";

char command[256];

char error_message[] = "Invalid command:";

char exit_message[] = "Goodbye till we meet again!";

while (1)
{
write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);

if (fgets(command, sizeof(command), stdin) == NULL)
{
write(STDOUT_FILENO, "\n", 1);
write(STDOUT_FILENO, exit_message, sizeof(exit_message) - 1);
exit(0);
}
command[strcspn(command, "\n")] = '\0';


if (command[0] == '\0')
{
continue;

}
pid_t pid = fork();

if (pid == 0)
{
execlp(command, command, NULL);

char error_command[256];
snprintf(error_command, sizeof(error_command)
		, "%s %s\n", error_message, command);
{
	write(STDOUT_FILENO, error_command, strlen(error_command));
exit(1);
}
else
{
wait(NULL);
}
}
return (0);
}
