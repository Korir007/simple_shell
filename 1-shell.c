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
	char command[COMMAND_LENGTH];
	pid_t process_id;

	while (true)
	{
		print_prompt(STDERR_FILENO);
		get_input(command);

		command[strcspn(command, "\n")] = '\0';

		process_id = fork();

	}
	
	return (0);
}

