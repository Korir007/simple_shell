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

#define MAX_CMD_LENGTH 1024
#define MAX_PATHS 64
#define PATH_DELIM ":"
#define MAX_ARGS 64
#define MAX_LINE_LENGTH 1024
#define MAX_ARGS 64

/* Function prototypes */

char *search_path(char *cmd, char *paths[], int npaths);
int my_strcmp(char *s1, const char *s2);
char get_input(char **cmd, size_t *n, FILE *ptr);
char *my_strtok(char *str, const char *delim);
char *_strchr(const char *s, int c);
void exit_shell(char *args[]);

/* environ prototype */

extern char **environ;

#endif /* SHELL_H */

