#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * exit_shell - exit/quit the shell.
 * @args: pointer to a character array containing command line arguments
 * 
 * This function takes a pointer to a character array named `args` and exits the shell
 * with the specified exit status. If no exit status is provided, the default value is 0.
 * 
 * Return: this function returns void
 */
void exit_shell(char *args[])
{
    int exit_status = 0; // Initialize the exit status to 0
    
    // If an exit status is provided as an argument, convert it to an integer using atoi
    if (args[1] != NULL)
    {
        exit_status = atoi(args[1]);
    }
    
    // Exit the shell with the specified exit status
    exit(exit_status);
}


