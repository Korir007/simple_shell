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
	int interactive_mode;
	(void) argc;

	while (true)
	{
		char *command = NULL;
		interactive_mode = isatty(STDIN_FILENO);

		if (interactive_mode)
		{
			print_prompt();
			command = get_input();
			execute_command(command, argv);
			free(command);
		}
	}

	return (0);
}

