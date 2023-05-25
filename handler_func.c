#include "main.h"

/**
 * printerr - displays the error messages indicating that a specified
 * split string was not found.
 * @lines: the line number where an error occurred.
 * @split: a pointer representing the command that was not found.
 * @av: A pointer contains command-line arguments.
 */
void printerr(int lines, char *split, char **av)
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
 * lineer - input variable creating.
 * @size: The size of the memory block to be allocated.
 * Return: A pointer to the allocated memory block.
 */
char *lineer(size_t size)
{
	char *input;

	input = (malloc(sizeof(char) * size));
	if (!input)
		write(2, "Unable to allocate memory", 25);

	return (input);
}



/**
 * cleanup - clears an array of characters.
 * @str: pointer to clean up.
 * Return: 1
 */
int cleanup(char **str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		free(str[i]);
	}
	free(str);

	return (1);
}
