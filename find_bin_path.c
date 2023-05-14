#include "shell.h"

/**
 * find_bin_path -
 *
 * Return: NULL
 */


char *find_bin_path(char *bin_name)
{
char *path = getenv("PATH");
char *token = strtok(path, ":");
struct stat sb;

while (token != NULL)
{
char bin_path[BUFFER_SIZE];
snprintf(bin_path, BUFFER_SIZE, "%s/%s", token, bin_name);

if (stat(bin_path, &sb) == 0 && sb.st_mode & S_IXUSR)
return strdup(bin_path);
token = strtok(NULL, ":");
}
return NULL;
}
