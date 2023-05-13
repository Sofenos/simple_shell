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

void read_command(char *command);
void parse_command(char *command, char **args);
void execute_command(char **args);
char *find_bin_path(const char *bin_name);
void print_error(const char *program, const char *message);
int main(int argc, char *argv[]);

#endif
