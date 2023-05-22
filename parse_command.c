#include "shell.h"

/**
 * parse_command - Parse a command into arguments
 * @command: The command string
 * @args: An array of arguments
 *
 * Return: void
 */
void parse_command(char *command, char **args)
{
	char *token = strtok(command, " ");
	int i = 0;

	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}

	args[i] = NULL;
}

