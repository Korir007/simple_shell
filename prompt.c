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

	if (prompt != NULL)
	{
		write(STDOUT_FILENO, prompt, 2);
	}
}

