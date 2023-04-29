#include "shell.h"

/**
* my_strtok - breaks command string into tokens
*
* @string: string involved
*
* @delimiter: delimiter parameters
*
* Return: null or pointer to token
*
*/

char *my_strtok(char *string, const char *delimiter)
{
	static char *token_end;
	char *token;

	token = NULL;

	if (string != NULL)
	{
		token_end = string;
	}

	while (*token_end != '\0' && strchr(delimiter, *token_end) != NULL)
	{
		token_end++;
	}

	if (*token_end == '\0')
	{
		return (NULL);
	}

	token = token_end;

	while (*token_end != '\0' && strchr(delimiter, *token_end) == NULL)
	{
		token_end++;
	}

	if (*token_end != '\0')
	{
		*token_end = '\0';
		token_end++;
	}
	return (token);
}

