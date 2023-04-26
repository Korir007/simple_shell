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
	char *command = NULL;

	while (true)
	{
		print_prompt();
		command = get_input();
		execute_command(command);
		free(command);
	}

	return (0);
}

