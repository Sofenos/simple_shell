#include "main.h"

/**
 * envi - searches for an environment variable with
 * a given name in a null-terminated arrays of str
 * @name: name of env variable
 * @environ: environment
 * Return: search for a specifi env
 */

char *envi(char *name, char **environ)
{
	int x, nameLength = strlen(name);
	char *var = NULL;

	for (x = 0; environ[x] != NULL; x++)
	{
		if (strncmp(environ[x], name, nameLength) == 0
				&& environ[x][nameLength] == '=')
		{
			var = environ[x];
			break;
		}
	}
	return (var);
}

/**
 * pathox - search for a specified input file
 * in the directories listed in the "PATH" env
 * @environ: pointer to an array of strings
 * @input: paramter is a pointer to a string
 * Return: the full path if found or 'NULL' otherwise
 */

char *pathox(char **environ, char *input)
{
	char *token, *delim, *cpy, *pathEnv, *command;
	struct stat st;

	pathEnv = envi("PATH", environ);
	if (pathEnv == NULL)
		return (NULL);

	delim = "=:";
	cpy = _strdup(pathEnv);
	if (cpy == NULL)
	{
		write(2, "Unable to allocate memory", 25);
		exit(1);
	}
	token = strtok(cpy, delim);
	while (token != NULL)
	{
		size_t path_len = _strlen(token);
		size_t command_len = path_len + 1 + _strlen(input);

		command = malloc(command_len + 1);

		if (command == NULL)
		{
			write(2, "Unable to allocate memory", 25);
			exit(1);
		}
		strcpy(command, token);
		strcat(command, "/");
		strcat(command, input);
		if (stat(command, &st) == 0)
		{
			free(cpy);
			return (command);
		}
		free(command);
		token = strtok(NULL, delim);
	}
	free(cpy);
	return (NULL);
}
