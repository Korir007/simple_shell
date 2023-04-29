#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* exit_shell - quits/exits with an exit message
*
* @args: the pointer to character array
* 
* Return: Always (void)
*/

void exit_shell(char *args[])
{
	int exit_msg = 0;

	if (args[1] != NULL)
	{
		exit_msg = atoi(args[1]);
	}
	exit(exit_msg);
}

