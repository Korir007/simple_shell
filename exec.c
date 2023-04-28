#include "shell.h"

/**
* execute_command - execute commands input by user
*
* @argv: pointer to pointer of command character array
*
* Return: 0 if sucessful and -1 if it fails
*
*/

int execute_command(char **argv)
{
	char error_return[BUFFER];
	int status;
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork() failed");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			snprintf(error_return, BUFFER, "%s: %d: %s: not found\n", NAME,
			errno, argv[0]);
			write(STDOUT_FILENO, error_return, my_strlen(error_return));
			exit(EXIT_FAILURE);
			return (-1);
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
	return (0);
}

