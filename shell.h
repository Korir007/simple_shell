#ifndef SHELL_H
#define SHELL_H

/* C libraries required */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

/* Global variables */

#define COMMAND_LENGTH 75
#define BUFFER 1024
#define NAME "hsh"
#define PATH 20
#define ARGUMENTS 30
#define MINI_BUFFER 256

/* Function prototypes */

void print_prompt(void);
char *get_input(void);
int my_strlen(char *string);
int my_strcmp(char *first_string, char *second_string);
void execute_command(char *command, char **argv);
char *my_strdup(char *string);
char *pathfinder(char *command, char *pathway[], int num);
void exit_shell(char **argv);
char *my_strtok(char *string, const char *delimiter);

/* environ prototype */

extern char **environ;

#endif /* SHELL_H */

