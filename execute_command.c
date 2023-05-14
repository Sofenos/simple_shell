#include "shell.h"

/**
 * execute_command -
 *
 * Return: void
 */


void execute_command(char **args)
{
if (strcmp(args[0], "cd") == 0)
{

if (args[1] == NULL)
{

chdir(getenv("HOME"));
}
else
{
if (chdir(args[1]) != 0)
{
printf("Error navigating to specified directory\n");
}
}
}
else if (strcmp(args[0], "exit") == 0)
{
exit(EXIT_SUCCESS);
}
else if (strcmp(args[0], "env") == 0)
{
char **env_var = environ;
while (*env_var)
{
printf("%s\n", *env_var);
env_var++;
}
}
else
{
char *bin_path = find_bin_path(args[0]);
if (bin_path != NULL)
{
pid_t pid = fork();
if (pid == 0)
{
execvp(args[0], args);
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
printf("Error creating child process\n");
}
else
{
wait(NULL);
}
free(bin_path);
}
else
{
printf("Command not found: %s\n", args[0]);
}
}
}
