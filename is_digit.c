#include "shell.h"

/**
 * _isdigit -checkss if string passed is a number
 *
 * @s: input string
 *
 * Return: 1 if string is a number.
 */
int _isdigit(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}

