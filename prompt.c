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
	char prompt[2] = "$ ";

	if (prompt != NULL)
	{
		write(STDOUT_FILENO, prompt, sizeof(prompt));
	}
}

