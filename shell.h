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

/* Function prototypes */

void print_prompt(void);
char *get_input(void);
int my_strlen(char *string);
int my_strcmp(const char *first_string, const char *second_string);
void tokenizer(char *command);
void execute_command(char *command, char **argv);
char *my_strdup(char *string);
char *pathfinder(char *command, char *path[], int num);

/* environ prototype */

extern char **environ;

#endif /* SHELL_H */

