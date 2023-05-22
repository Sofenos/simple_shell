#include "shell.h"

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
void execute_command(char **args)
{
	if (strcmp(args[0], "cd") == 0)
	{
		cd_command(args);
	}
	else if (strcmp(args[0], "exit") == 0)
	{
		exit_command();
	}
	else if (strcmp(args[0], "env") == 0)
	{
		env_command();
	}
	else
	{
	pid_t pid = fork();
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
}

