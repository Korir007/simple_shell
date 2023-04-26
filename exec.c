#include "shell.h"

/**
* execute_command - execute commands input by user
*
* @command: command string involved
*
* Return: void
*
*/

void execute_command(char *command)
{
	char *arg[COMMAND_LENGTH] = {NULL};
	char error_returned[BUFFER];
	int status;
	pid_t child_pid;

	child_pid = fork();

	if (my_strlen(command) == 0)
	{
		return;
	}

	if (child_pid == -1)
	{
		perror("fork() failed");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(command, arg, NULL) == -1)
		{
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
		else
		{
			snprintf(error_returned, BUFFER, "%s: command not found\n", command);
			write(STDOUT_FILENO, error_returned, my_strlen(error_returned));
		}
	}
}

