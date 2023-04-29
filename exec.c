#include "shell.h"

/**
* execute_command - execute commands input by user
*
* @command: command string involved
*
* @argv: pointer to pointer of array of character commands
*
* Return: void
*
*/

void execute_command(char *command, char **argv)
{
	char *error_return;
	int status;
	pid_t child_pid;

	child_pid = fork();

	error_return = calloc(BUFFER, sizeof(char));

	if (my_strlen(command) == 0)
		return;

	if (error_return == NULL)
	{
		perror("error allocating memory");
		exit(EXIT_FAILURE);
	}

	if (child_pid == -1)
	{
		perror("fork() failed");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execve(command, argv, environ);
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
	free(error_return);
}

