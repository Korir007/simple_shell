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

/* Function prototypes */

void print_prompt(void);
char *get_input(void);
int my_strlen(char *string);
<<<<<<< HEAD
int my_strcmp(const char *first_string, const char *second_string);
=======
int exit_sh(datashell *data);
>>>>>>> Daniel

#endif /* SHELL_H */

