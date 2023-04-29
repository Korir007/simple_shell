#include "shell.h"

/**
 * exit_shell - exit/quit the shell.
 * @args: pointer to a character array containing command line arguments
 *
 *
 * Return: this function returns void
 */

void exit_shell(char **argv)
{
	int exit_msg = 0; /* Initialize the exit status to 0 */

	if (argv[0] != NULL)
	{
		exit_msg = atoi(argv[0]);
	}

    /* Exit the shell with the specified exit status */
	exit(exit_msg);
}

