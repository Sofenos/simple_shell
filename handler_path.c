#include "main.h"

/**
 *envi - recherche une variable d'environnement avec
 *un nom donné dans un tableau de chaînes de caractères
 *terminé par un pointeur NULL
 *@name: nom de la variable d'environnement
 *@environ: environnement
 *Return: la valeur de la variable d'environnement recherchée
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
 *pathox - recherche un fichier d'entrée spécifié
 *dans les répertoires répertoriés dans la variable d'environnement "PATH"
 *@environ: pointeur vers un tableau de chaînes de caractères
 *@input: paramètre pointant vers une chaîne de caractères
 *Return: le chemin complet du fichier s'il est trouvé, sinon 'NULL'
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
