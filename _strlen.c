#include "shell.h"

/**
* my_strlen - returns length of a string
*
* @string: string
*
* Return: length of string involved
*/

int my_strlen(char *string)
{
	int length;

	length = 0;

	while (*string != '\0')
	{
		length++;
		string++;
	}

	return (length);
}

