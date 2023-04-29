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

char *search_path(char *cmd, char *paths[], int npaths);
int _strcmp (char *s1, const char *s2);
char *_getline(char **line, size_t *n, FILE *ptr);
char *_strtok(char *str, const char *delim);
char *_strchr(const char *s, int c);
void exit_shell(char *args[]);

/* environ prototype */

extern char **environ;

#endif /* SHELL_H */

