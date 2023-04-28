#include "shell.h"

/**
* execute_command - execute commands input by user
*
* @command: command string involved
*
* @argv: array of character commands
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
		if (execve(command, argv, NULL) == -1)
		{
			snprintf(error_return, BUFFER, "%s: No such file or directory\n",
			argv[0]);
			write(STDOUT_FILENO, error_return, my_strlen(error_return));
			exit(EXIT_FAILURE);
		}
		else
		{
			execve(command, argv, environ);
			perror("execve failed");
			exit(EXIT_SUCCESS);
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
			waitpid(child_pid, &status, 0);
		}
	}
	free(error_return);
}

