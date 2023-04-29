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

char *my_strtok(char *str, const char *delim)
{
	static char *endoftoken;
	char *token = NULL;

	if (str != NULL)
	{
		endoftoken = str;
	}

	while (*endoftoken != '\0' && _strchr(delim, *endoftoken) != NULL)
	{
		endoftoken++;
	}

	if (*endoftoken == '\0')
	{
		return (NULL);
	}

	token = endoftoken;

	while (*endoftoken != '\0' && _strchr(delim, *endoftoken) == NULL)
	{
		endoftoken++;
	}

	if (*endoftoken != '\0')
	{
		*endoftoken = '\0';
		endoftoken++;
	}
	return (token);
}

