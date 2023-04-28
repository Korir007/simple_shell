#include "shell.h"

/**
* main - entry point
*
* Description: simple shell interpreter
*
* @argc: command line argument count
*
* @argv: pointer to pointer of command character array
*
* Return: 0 if successful
*/

int main(int argc, char **argv)
{
	char *command = NULL;
	(void) argc;

	while (true)
	{
		print_prompt();
		command = get_input();
		execute_command(argv);
		free(command);
	}

	return (0);
}

