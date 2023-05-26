#include "main.h"

/**
 *_strlen - fonction qui compte la longueur d'une chaîne de caractères
 *@str: chaîne de caractères à compter
 *Return: la longueur de la chaîne
*/
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
	}

	return (i);
}

/**
 *_strdup - fonction qui renvoie un pointeur
 *vers un nouvel espace alloué
 *@str: chaîne de caractères
 *Return: un pointeur vers la chaîne dupliquée
*/
char *_strdup(char *str)
{
	char *dup;
	int i;

	for (i = 0; str[i]; i++)
	{
	}

	dup = malloc((sizeof(char) * i) + 1);
	if (!dup)
	{
		write(2, "Unable to allocate memory", 25);
		exit(1);
	}

	for (i = 0; str[i]; i++)
	{
		dup[i] = str[i];
	}
	dup[i] = '\0';

	return (dup);
}

/**
 *_splitox - divise une chaîne en tableaux en fonction du délimiteur
 *@str: chaîne de caractères
 *@delim: délimiteur
 *Return: un pointeur vers des caractères
*/
char **_splitox(char *str, char *delim)
{
	int a, b, characters, lignes = 1;
	char **split, *token, *strup;

	strup = _strdup(str);
	for (a = 0; strup[a]; a++)
	{
		if (strup[a] == delim[0] || strup[a] == delim[1])
			lignes++;
	}
	split = malloc((lignes + 1) * sizeof(char *));
	if (!split)
	{
		write(2, "cannt allocate", 14);
		exit(1);
	}
	token = strtok(strup, delim);
	b = 0;
	while (token)
	{
		characters = _strlen(token);
		split[b] = malloc((characters + 1) * sizeof(char));
		if (!split)
		{
			write(2, "unbale to allocate", 18);
			for (; b != 0; b--)
				free(split[b - 1]);
			free(split);
			exit(1);
		}
		for (a = 0; a < characters; a++)
			split[b][a] = token[a];
		split[b][a] = '\0';
		b++;
		token = strtok(0, delim);
	}
	split[b] = NULL;
	free(strup);
	return (split);
}

/**
 *_strcmp - compare deux chaînes de caractères
 *@s1: chaîne de caractères
 *@s2: chaîne de caractères
 *Retourne: une valeur inférieure à 0 si la première chaîne est inférieure à la deuxième
*/
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] && s2[i]; i++)
	{
		if (s1[i] != s2[i])
			break;
	}
	if (i == _strlen(s1) && i == _strlen(s2))
		return (1);
	else
		return (0);
}

/**
 *_numtostr - compte le nombre de chiffres
 *@n: nombre à évaluer
 *Retourne: le nombre de chiffres
*/
char *_numtostr(int n)
{
	int i = 0, j, number = n;
	char *strnumber;

	for (i = 0; n != 0; i++)
	{
		n = n / 10;
	}

	strnumber = malloc(sizeof(char) * (i + 1));

	for (j = 1; j <= i; j++)
	{
		strnumber[i - j] = (number % 10) + '0';
		number = number / 10;
	}
	strnumber[i] = '\0';
	return (strnumber);
}
