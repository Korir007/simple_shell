#include "shell.h"

/**
*
*
*
*
*
*
*
*/

int main(void)
{
	char command[COMMAND_LENGTH];
	pid_t process_id;

	while (true)
	{
		printf("#cisfun$ \n");

		process_id = fork();

		if (process_id < 0)
		{
			perror("Error.\n");
			exit(98);
		}
		else if (process_id == 0)
		{
			printf("Successful.\n");
		}
	}
	return (0);
}
