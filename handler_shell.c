#include "main.h"

/**
 * execute - execute a command with the specified arg
 * in a child process
 * @command: pointer to a constant character
 * @arguments: pointer to an array of const character string
 * @av: name of the program
 * Return: integer value
*/

int execute(char *command, char **arguments, char *av)
{
	int status;

	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(command, arguments, NULL) == -1)
		{
			fprintf(stderr, "%s: ", av);
			perror(command);
			exit(errno);
		}
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("wait");
			return (-1);
		}
		if (WIFEXITED(status))
		{
			return (WEXITSTATUS(status));
		}
		else
		{
			return (-1);
		}
	}
	return (0);
}

/**
 * main - Entry pointe of C program that implements a basic shell
 * The main() function in the program takes three parameters.
 * @ac: An integer represents the number of arguments passed to the program.
 * @av: representing the command-line arguments passed to the program.
 * @env: representing the environment variables passed to the program.
 * Return: exit status of the shell.
*/

int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *line, **spl;
	size_t size = 32;
	int *errval = malloc(sizeof(int)), read, error, lines = 1;

	*errval = 0;
	line = lineer(size);
	if (!line)
		exit(-1);
	while (1)
	{
		if (isatty(0) == 1)
			write(1, "simple_shell:~$", 15);
		read = getline(&line, &size, stdin);
		if (read == -1)
			break;
		if (read == 1)
			continue;
		line[read - 1] = ' ';
		spl = _splitox(line, " ");
		if (!*spl)
		{
			free(spl);
			continue;
		}
		switch (shand(line, spl, lines, env, av, errval))
		{
			case 0:
				error = *errval;
				free(errval);
				exit(error);
			case 1:
				continue;
		}
		lines++;
	}
	free(line);
	error = *errval;
	free(errval);
	return (error);
}

/**
 * shand - function that executes a command
 * based on the input line passed to it
 * @line: pointer to char that contains input
 * @split: individual words of the input
 * @lines: line number of the input
 * @env: environment variables for the current process
 * @av: command-line arguments passed to the program
 * @err: exit status
 * Return: integer value
*/

int shand(char *line, char **split, int lines, char **env, char **av, int *err)
{
	char *cmd;
	int x;
	struct stat st;

	if (_strcmp(split[0], "exit"))
	{
		free(split);
		free(line);
		return (0);
	}
	if (_strcmp(split[0], "env"))
	{
		for (x = 0; env[x]; x++)
		{
			write(1, env[x], _strlen(env[x]));
			write(1, "\n", 1);
		}
		return (cleanup(split));
	}
	if (stat(split[0], &st) == 0)
	{
		*err = execute(split[0], split, av[0]);
		return (cleanup(split));
	}
	cmd = pathox(env, split[0]);
	if (!cmd)
	{
		*err = 127;
		printerr(lines, split[0], av);
	}
	else if (execute(cmd, split, av[0]) == -1)
	{
		perror(": ");
		*err = errno;
		return (0);
	}
	cleanup(split);
	free(cmd);
	return (10);
}
