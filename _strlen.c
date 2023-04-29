#include "shell.h"

/**
* my_strchr - returns length of a string
*
* @string: string
*
* Return: length of string involved
*/

char *my_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return ((char *) s);
		}
		s++;
	}
	return (NULL);
}

