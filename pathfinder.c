#include "shell.h"

/**
* pathfinder - checks if path chosen is executable
*
* @command: command input by user
*
* @pathway: array of possible paths
*
* @num: number of paths chosen
*
* Return: Null if it fails or pointer to pathway
*
*/

char *pathfinder(char *command, char *pathway[], int num)
{
	int i = 0;

	if (access(command, X_OK) == 0)
	{
		return (my_strdup(command));
	}

	else
	{
		for (i = 0; i < num; i++)
		{
			char path[COMMAND_LENGTH];

			snprintf(path, COMMAND_LENGTH, "%s/%s", pathway[i], command);
			if (access(path, X_OK) == 0)
			{
				return (my_strdup(path));
			}
		}
		return (NULL);
	}
}

