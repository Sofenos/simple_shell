#include "shell.h"

/**
 * main - Entry point of the program
 *
 * Return: Always 0.
 */
int main(void)
{
char command[BUFFER_SIZE];
char *args[BUFFER_SIZE];
while (1)
{
read_command(command);
parse_command(command, args);
if (args[0] != NULL)
{
execute_command(args);
}
}
return (0);
}
