#include "shell.h"

/**
* execute_command - execute commands input by user
*
* @argv: command string involved
*
* Return: void
*
*/

void execute_command(char *command)
{
	char *arg[COMMAND_LENGTH] = {NULL};
	char error_return[BUFFER];
	int status;
	pid_t child_pid;

	child_pid = fork();

	if (my_strlen(command) == 0)
		return;

	if (child_pid == -1)
	{
		perror("fork() failed");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(command, arg, NULL) == -1)
		{
			snprintf(error_return, BUFFER, "%s: %d: %s: not found\n", NAME,
			errno, command);
			write(STDOUT_FILENO, error_return, my_strlen(error_return));
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(child_pid, &status, 0) == -1)
		{
			perror("waitpid error");
			exit(EXIT_FAILURE);
		}
	}
}

