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

/* Function prototypes */

void print_prompt(void);
ssize_t get_input(void);

#endif /* SHELL_H */

