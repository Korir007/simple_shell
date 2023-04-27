#include "shell.h"

/**
* print_prompt - prints $
*
* @void: no arguments
*
* Return: void
*/

void print_prompt(void)
{
	char prompt[2] = "$ ";

	if (prompt != NULL)
	{
		write(STDOUT_FILENO, prompt, sizeof(prompt));
	}
}

/**
 * _iswhich - locates a command
 *
 * @prompt: command name
 *
 * @_environ: environment variable
 *
 * Return: Exec of command
 */

char *_iswhich(char *cmd, char **_environ)
{
	char *path, *ptr_path, *token_path, *dir;
	int len_dir, len_cmd, i;
	struct stat st;

	path = _getenv("PATH", _environ);
	if (path)
	{
		ptr_path = _strdup(path);
		len_cmd = _strlen(cmd);
		token_path = _strtok(ptr_path, ":");
		i = 0;
		while (token_path != NULL)
		{
			if (is_cdir(path, &i))
				if (stat(cmd, &st) == 0)
					return (cmd);
			len_dir = _strlen(token_path);
			dir = malloc(len_dir + len_cmd + 2);
			_strcpy(dir, token_path);
			_strcat(dir, "/");
			_strcat(dir, cmd);
			_strcat(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(ptr_path);
				return (dir);
			}
			free(dir);
			token_path = _strtok(NULL, ":");
		}
		free(ptr_path);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &st) == 0)
			return (cmd);
	return (NULL);
}


/**
 * _isexecutable - determines if is an executable
 *
 * @datash: data structure
 *
 * Return: 0 if is not an executable, other number if it does
 */
int _isexecutable(data_shell *datash)
{
	int i;
	char *get_input;

	get_input = datash->args[0];
	for (i = 0; get_input[i]; i++)
	{
		if (get_input[i] == '.')
		{
			if (get_input[i + 1] == '.')
				return (0);
			if (get_input[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (get_input[i] == '/' && i != 0)
		{
			if (get_input[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
	}
}

/*
 *cmd_exec - runs command lines
 *
 *@datash: data relevant
 *
 *Return: 1 on Success
 */

int cmd_exec(data_shell *datash)
{
	pid_t pd;
	pid_t wpd;
	int state;
	int exec;
	char *dir;
	(void) wpd;

	exec = is_executable(datash);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		dir = _which(datash->args[0], datash->_environ);
	
	}

	pd = fork();
	if (pd == 0)
	{
		if (exec == 0)
			dir = _which(datash->args[0], datash->_environ);
		else
			dir = datash->args[0];
		execve(dir + exec, datash->args, datash->_environ);
	}
	else if (pd < 0)
	{
		perror(datash->av[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	datash->status = state / 256;
	return (1);
}

