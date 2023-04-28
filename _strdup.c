#include "shell.h"

/**
 * *my_strdup - duplicates a string
 *
 * @string: pointer to string involved
 *
 * Return: pointer to the new duplicated string
 *
 * or NULL if memory is not available
 */

char *my_strdup(char *string)
{
	char *new_string;
	int length;

	if (string == NULL)
	{
		return (NULL);
	}

	length = my_strlen(string) + 1;

	new_string = malloc(length * sizeof(char));

	if (new_string == NULL)
	{
		return (NULL);
	}
	strcpy(new_string, string);

	return (new_string);
}

