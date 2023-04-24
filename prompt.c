#include "shell.h"

/**
* print_prompt - prints $
*
* @void: no arguments
*
* Return: void
*/

void print_prompt(void)
{
	char *prompt;

	prompt = "$ ";

	write(STDERR_FILENO, prompt, COMMAND_LENGTH);
}

