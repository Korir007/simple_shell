#include "shell.h"

/**
* get_input - reads user input
*
* @command: command input by user
*
* Return: input
*/

ssize_t get_input(char *command)
{
	size_t length;
	ssize_t input;

	command = NULL;
	length = 0;
	input = getline(&command, &length, stdin);

	if (input == -1)
		exit(EXIT_FAILURE);

	return (input);
}

