#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * exit_shell - exit/quit the shell.
 * @args: pointer to a character array containing command line arguments
 * 
 * 
 * Return: this function returns void
 */
void exit_shell(char *args[])
{
    int exit_msg = 0;
    
    if (args[1] != NULL)
    {
        exit_msg = atoi(args[1]);
    }
    
    /* Exit the shell with the specified exit status */
    exit(exit_msg);
}

