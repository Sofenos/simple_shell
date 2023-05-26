#include "main.h"

/**
 *error - affiche les messages d'erreur
 *@lines: le numéro de ligne où une erreur s'est produite.
 *@split: un pointeur représentant la commande qui n'a pas été trouvée.
 *@av: un pointeur contenant les arguments de la ligne de commande.
*/
void error(int lines, char *split, char **av)
{
	char *strlines = _numtostr(lines);

	write(2, av[0], _strlen(av[0]));
	write(2, ": ", 2);
	write(2, strlines, _strlen(strlines));
	write(2, ": ", 2);
	write(2, split, _strlen(split));
	write(2, ": not found\n", 12);
	free(strlines);
}


/**
 *liner - création de variable d'entrée.
 *@size: la taille du bloc mémoire à allouer.
 *Return: un pointeur vers le bloc mémoire alloué.
*/
char *liner(size_t size)
{
	char *input;

	input = (malloc(sizeof(char) * size));
	if (!input)
		write(2, "Unable to allocate memory", 25);

	return (input);
}


/**
 *clean - efface un tableau de caractères.
 *@str: pointeur à nettoyer.
 *Return: 1
*/
int clean(char **str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		free(str[i]);
	}
	free(str);

	return (1);
}
