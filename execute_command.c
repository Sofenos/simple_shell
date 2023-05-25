#include "shell.h"
static int execute_builtin_command(char **args);

/**
 * cd_command - Change directory command
 * @args: The command arguments
 *
 * Return: void
 */
void cd_command(char **args)
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

/**
 * exit_command - Exit command
 *
 * Return: void
 */
void exit_command(void)
{
	exit(EXIT_SUCCESS);
}

/**
 * env_command - Environment command
 *
 * Return: void
 */
void env_command(void)
{
char **env_var = environ;
	while (*env_var != NULL)
	{
	  if (strncmp(*env_var, "_=", 2) != 0)
	    printf("%s\n", *env_var);
	  env_var++;
	}
}

/**
 * execute_command - Execute a command
 * @args: The command arguments
 *
 * Return: void
 */
void execute_command(char *command)
{
  pid_t pid;
  char *args[MAX_ARGS];
  parse_command(command, args);

  if (execute_builtin_command(args))
    return;
  pid = fork();
  if (pid == 0)
    {
      execvp(args[0], args);
      fprintf(stderr, "%s: Command not found\n", args[0]);
      exit(EXIT_FAILURE);
    }
  else if (pid < 0)
    {
      fprintf(stderr, "Fork error\n");
    }
  else
    {
      int status;
      waitpid(pid, &status, 0);
    }
}

/**
 * execute_builtin_command - Execute a built-in command
 * @args: The command arguments
 *
 * Return: 1 if the command was a built-in command, 0 otherwise
 */
static int execute_builtin_command(char **args)
{
    if (strcmp(args[0], "cd") == 0)
    {
        cd_command(args);
        return (1);
    }
    else if (strcmp(args[0], "exit") == 0)
    {
        exit_command();
        return (1);
    }
    else if (strcmp(args[0], "env") == 0)
    {
        env_command();
        return (1);
    }

    return (0);
}
