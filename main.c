#include "shell.h"

/**
 * main - Entry point of the program
 *
 * Return: Always 0.
 */
int main(void)
{
    char command[BUFFER_SIZE];
    char *args[MAX_ARGS];
 
    while (1)
    {
        read_command(command);
	parse_command(command, args);
	execute_command(command);
	if (feof(stdin))
	  break;
    }

    return (0);
}
