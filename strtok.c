#include "shell.h"

/**
* tokenizer - breaks the command string into
* an array of strings
*
* @command: pointer to command string involved
*
* Return: void
*
*/

void tokenizer(char *command)
{
	char **tokens, *token, *delimiter;
	int count;

	tokens = NULL;
	token = NULL;
	delimiter = " \t\n";
	count = 0;

	token = strtok(command, delimiter);

	while (token != NULL && count < COMMAND_LENGTH - 1)
	{
		tokens[count] = token;
		token = strtok(NULL, delimiter);
		count++;
	}

	tokens[count] = NULL;
}

