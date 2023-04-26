#include "shell.h"

/**
* get_input - reads user input
*
* @void: no arguments
*
* Return: command input by user
*/

char *get_input(void)
{
	char *command;
	size_t length;
	ssize_t input;

	command = NULL;
	length = 0;
	input = getline(&command, &length, stdin);

	if (input == -1)
	{
		if (input == EOF)
		{
			write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		else
		{
			/* easier to trace where error occured */
			perror("input error");
			exit(EXIT_FAILURE);
		}
	}

	/* checks if user presses ENTER after input */

	if (command[input - 1] == '\n')
	{
		command[input - 1] = '\0';
	}

	return (command);
}

