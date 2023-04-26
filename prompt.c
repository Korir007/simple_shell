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

	prompt = "#cisfun$ ";

	if (prompt != NULL)
	{
		write(STDOUT_FILENO, prompt, 10);
	}
}

