#include "shell.h"

/**
 * print_error - Print an error message
 * @program: The program name
 * @message: The error message
 *
 * Return: void
 */
void print_error(const char *program, const char *message)
{
	fprintf(stderr, "%s: %s\n", program, message);
}

