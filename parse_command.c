#include "shell.h"

/**
 * parse_command -
 *
 * Return: Void
 */

void parse_command(char* command, char** args)
{
    char* token = strtok(command, " ");
    int i = 0;
    while (token != NULL)
      {
        args[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    args[i] = NULL;
}
