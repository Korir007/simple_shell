#include "shell.h"

/**
* get_input - reads user input
*
* @void: no arguments
*
* Return: input
*/

ssize_t get_input(void)
{
	char *command;
	size_t length;
	ssize_t input;

	command = NULL;
	length = 0;
	input = getline(&command, length, stdin);

	if (input == -1)
		break;

	return (input);
}

