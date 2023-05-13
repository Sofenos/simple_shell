#include "shell.h"

/**
 * print_error - 
 *
 * Return: void.
 */

void print_error(const char *program, const char *message)
{
    fprintf(stderr, "%s: %s\n", program, message);
}
