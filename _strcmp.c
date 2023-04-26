#include "shell.h"

/**
* my_strcmp - compares two strings
*
* @first_string: pointer to first string
*
* @second_string: pointer to second string
*
* Return: 0 if strings are identical
*
* or difference between the 2 strings
*
*/

int my_strcmp(const char *first_string, const char *second_string)
{
	int index;

	index = 0;

	while (first_string[index] == second_string[index])
	{
		if (first_string[index] == '\0')
		{
			return (0);
		}
		index++;
	}

	return (first_string[index] - second_string[index]);
}

