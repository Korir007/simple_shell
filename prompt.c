#include "shell.h"

/**
* print_prompt - prints $
*
* @fd: file descriptor that will written into
*
* Return: void
*/

void print_prompt(int fd)
{
	char *prompt;

	prompt = "$ ";

	write(fd, prompt, COMMAND_LENGTH);
}

