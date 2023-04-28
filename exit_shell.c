#include "shell.h"

/**
 * exit_shell - exit/quit the shell.
 * @args: pointer to a character array containing command line arguments
 *
 *
 * Return: this function returns void
 */

void exit_shell(char *args[])
{
    int exit_msg = 0; /* Initialize the exit status to 0 */

    /* If an exit status is provided as an argument, convert it to an integer using atoi */
    if (args[1] != NULL)
    {
        exit_msg = atoi(args[1]);
    }

    /* Exit the shell with the specified exit status */
    exit(exit_msg);
}

