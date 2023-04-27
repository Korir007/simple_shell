#ifndef SHELL_H
#define SHELL_H

/* C libraries required */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <string.h>

/* Global variables */

#define COMMAND_LENGTH 75
#define BUFFER 1024

/* Struct data*/
typedef struct data
{
	char *get_input;
	char **args;
	char *command;
	char **_environ;

} data_shell;

/* Function prototypes */

void print_prompt(void);
char *get_input(void);
int my_strlen(char *string);
int my_strcmp(const char *first_string, const char *second_string);
void tokenizer(char *command);
void execute_command(char *command);
int exit_sh(datashell *data);
int _atoi(char *s);
int _isdigit(const char *s);
int _isexecutable(data_shell *datash);
char *_iswhich(char *cmd, char **_environ);
int cmd_exec(data_shell *datash);
int (*builtins(char *cmd))(data_shell *);

#endif /* SHELL_H */

