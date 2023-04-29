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

int main(void)
{
	char *path = getenv("PATH");
	char *paths[MAX_PATHS];
	int npaths = 0;
	char *pathtok = strtok(path, PATH_DELIM);
	size_t n = 0;
	int status;
	char *args[MAX_ARGS];
	int nargs = 0;
	char *tok;
	pid_t pid;
	int interactive = isatty(STDIN_FILENO);

	while (pathtok != NULL && npaths < MAX_PATHS)
	{
		paths[npaths++] = pathtok;
		pathtok = strtok(NULL, PATH_DELIM);
	}
	while (1)
	{
		char *cmd = NULL;
		if(interactive)
		{
		printf("hsh ");
		fflush(stdout);
		}
		if (_getline(&cmd, &n, stdin) == NULL)
		{
			free(cmd);
			break;
		}


		tok = _strtok(cmd, " \t\n");
		while (tok != NULL && nargs < MAX_ARGS)
		{
			args[nargs++] = tok;
			tok = _strtok(NULL, " \t\n");
		}
		args[nargs] = NULL;
		if (nargs == 0)
		{
			free(cmd);
			continue;
		}
		nargs = 0;
		if (_strcmp(args[0], "exit") == 0)
		{
			exit_shell(args);
		}
		path = search_path(args[0], paths, npaths);

		if (path == NULL)
		{
			printf("Command not found: %s\n", args[0]);
			continue;
		}

		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(0);
		}

		else if (pid == 0)
		{
			execve(path, args, environ);
			perror("execve");
			free(cmd);
			exit(0);
		}

		else
		{
			free(cmd);
			waitpid(pid, &status, 0);
		}
		free(path);

	}
	return (0);
}

