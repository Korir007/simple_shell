#include "shell.h"

/**
* fork_func - forks a child process before execution
*
* @void: has no arguments
*
* Return: child_pid
*
*/

pid_t fork_func(void)
{
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork() failed!");
		return (-1);
	}

	return (child_pid);
}

