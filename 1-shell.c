#include "shell.h"

/**
* main - entry point
*
* Description: simple shell interpreter
*
* @argc: command line argument count
*
* @argv: pointer of command character array
*
* Return: 0 if successful
*/

int main(int argc, char *argv[ARGUMENTS])
{
	int interactive_mode, arg_count = 0, num = 0;
	char *path = getenv("PATH");
	char *pathway[PATH];
	char *path_chosen;
	char *token, *delimiter;
	(void) argc;

	delimiter = " \t\n";
	path_chosen = strtok(path, delimiter);

	while (path_chosen != NULL && num < PATH)
	{
		pathway[arg_count] = path_chosen;
		path_chosen = strtok(NULL, delimiter);
		arg_count++;
	}

	while (true)
	{
		char *command = NULL;

		interactive_mode = isatty(STDIN_FILENO);

		if (interactive_mode)
		{
			print_prompt();
			command = get_input();
			path = pathfinder(argv[0], pathway, num);
			if (path == NULL)
			{
				char error_return[MINI_BUFFER];

				sprintf(error_return, "%s: command not found\n", argv[0]);
				write(STDERR_FILENO, error_return, my_strlen(error_return));
			}
			token = my_strtok(command, delimiter);
			while (token != NULL && arg_count < ARGUMENTS)
			{
				argv[arg_count] = token;
				token = my_strtok(NULL, delimiter);
				arg_count++;
			}
			argv[arg_count] = NULL;
			if (arg_count == 0)
			{
				free(command);
				exit(EXIT_FAILURE);
			}
			arg_count = 0;
			if (my_strcmp(argv[0], "exit") == 0)
			{
				exit_shell(argv);
			}
			execute_command(command, argv);
			free(command);
		}
	}
	return (0);
}

