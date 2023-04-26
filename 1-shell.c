#include "shell.h"

/**
* main - entry point
*
* Description: simple shell interpreter
*
* @void: zero arguments
*
* Return: 0 if successful
*/

int main(void)
{
	char *command = NULL, *arg[] = {NULL}, error_returned[BUFFER];
	pid_t child_pid;
	int status;

	while (true)
	{
		print_prompt();
		command = get_input();
		if (access(command, X_OK) != -1)
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("fork() failed!");
				exit(EXIT_FAILURE);
			}
			else if (child_pid == 0)
			{
				if (execve(command, arg, NULL) == -1)
				{
					perror("error in execve");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				if (waitpid(child_pid, &status, 0) == -1)
				{
					perror("waitpid failure");
					exit(EXIT_FAILURE);
				}
			}
		}
		else
		{
			snprintf(error_returned, BUFFER, "%s: command not found\n", command);
			write(STDOUT_FILENO, error_returned, my_strlen(error_returned));
		}
	}
	free(command);
	return (0);
}
