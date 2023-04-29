#include "shell.h"

/**
* my_strcmp - compares two strings
*
* @first_string: pointer to pointer to first string
*
* @second_string: pointer to pointer to second string
*
* Return: 0 if strings are identical
*
* or difference between the 2 strings
*
*/

int my_strcmp(char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}

