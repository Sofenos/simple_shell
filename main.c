#include "shell.h"

/**
 * main -
 *
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
const char *program = argv[0];
char command[BUFFER_SIZE];
char *args[BUFFER_SIZE];

while (1)
{
read_command(command);
parse_command(command, args);
if (args[0] != NULL)
{
execute_command(args, program);
}
}
return (0);
}
