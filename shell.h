#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define MAX_ARGS 64

extern char **environ;

void read_command(char *command);
int parse_command(char *command, char **args);
void execute_command(char *command);
void cd_command(char **args);
void exit_command(void);
void env_command(void);
char *find_bin_path(const char *command);
void print_error(const char *program, const char *message);
int main(void);

#endif /* SHELL_H */
