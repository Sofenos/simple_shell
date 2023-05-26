#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

int execute(char *command, char **arguments, char *av);
int hand(char *, char **, int, char **, char **, int *);
void error(int lines, char *split, char **av);
char *liner(size_t size);
int clean(char **str);
int _strlen(char *str);
char *_strdup(char *str);
char **_splitx(char *str, char *delim);
int _strcmp(char *origin, char *comp);
char *_numtostr(int n);
char *envi(char *name, char **environ);
char *pathx(char **environ, char *input);


#endif
