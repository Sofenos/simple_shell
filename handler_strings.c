#include "main.h"

/**
 * _strlen - function counts length of string
 * @str: string to count
 * Return: the amount of string
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
 * _strdup - function that returns a pointer
 * to a newly allocated space
 * @str: string
 * Return: pointer to duplicated string
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
 * _splitox - devid string into arrays based on delim
 * @str: string
 * @delim: delimiter
 * Return: pointer of characters
 */



char **_splitox(char *str, char *delim)
{
	int a, b, characters, lignes = 1;
	char **split, *token, *strup;
	/* allocating memory to create a copy of string  */
	strup = _strdup(str);
	for (a = 0; strup[a]; a++)
	{
		if (strup[a] == delim[0] || strup[a] == delim[1])
			lignes++;
	}
	/* checking if the memory allocate was successfulor not */
	split = malloc((lignes + 1) * sizeof(char *));
	if (!split)
	{
		write(2, "cannt allocate", 14);
		exit(1);
	}
	token = strtok(strup, delim);
	/*tokenize a string into substring o stores it in dynam allocated mem*/
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
 * _strcmp - compare 2 string
 * @s1: string
 * @s2: string
 * Return: less 0 if string is less than other & the opposite
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
 * _numtostr - count the number of digits
 * @n: number to evaluate
 * Return: The number of digits
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
