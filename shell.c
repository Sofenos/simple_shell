#include "main.h"

/**
 *execute - exécute une commande avec les arguments spécifiés
 *dans un processus enfant
 *@command: pointeur vers une chaîne de caractères constante
 *@arguments: pointeur vers un tableau de chaînes de caractères constantes
 *@av: nom du programme
 *Return: une valeur entière
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
 *main - Point d'entrée du programme C qui implémente un shell basique
 *La fonction main() du programme prend trois paramètres.
 *@ac: Un entier représentant le nombre d'arguments passés au programme.
 *@av: Représente les arguments de ligne de commande passés au programme.
 *@env: Représente les variables d'environnement passées au programme.
 *Return: le statut de sortie du shell.
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
			write(1, "simple_shell:#", 15);
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
 *shand - fonction qui exécute une commande
 *basée sur la ligne d'entrée qui lui est passée
 *@line: pointeur vers une chaîne de caractères contenant l'entrée
 *@split: mots individuels de l'entrée
 *@lines: numéro de ligne de l'entrée
 *@env: variables d'environnement pour le processus en cours
 *@av: arguments de ligne de commande passés au programme
 *@err: statut de sortie
 *Return: une valeur entière
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
		error(lines, split[0], av);
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
