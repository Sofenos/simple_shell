#include "shell.h"

/**
 * read_command - Read user input
 * @command: Buffer to store the user input
 *
 * Return: void
 */
void read_command(char *command)
{
	printf("$> ");
	if (fgets(command, BUFFER_SIZE, stdin) == NULL)
	{
		printf("\n");
		exit(EXIT_SUCCESS);
	}
	command[strcspn(command, "\n")] = '\0';
}

