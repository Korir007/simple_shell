#include "shell.h"

/**
* *search_path - checks if path chosen is executable
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

char *search_path(char *cmd, char *paths[], int npaths)
{
	int i = 0;

	if (access(cmd, X_OK) == 0)
	{
		return (strdup(cmd));
	}
	else
	{
		for (i = 0; i < npaths; i++)
		{
			char path[MAX_CMD_LENGTH];

			snprintf(path, MAX_CMD_LENGTH, "%s/%s", paths[i], cmd);
			if (access(path, X_OK) == 0)
			{
				return (strdup(path));
			}
		}
		return (NULL);
	}
}

