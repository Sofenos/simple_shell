#include "shell.h"

/**
 * find_bin_path - Find binary path
 * @command: The command or binary name
 *
 * Return: The binary path or NULL
 */
char *find_bin_path(const char *command)
{
	const char *path = getenv("PATH");
	char *token = NULL;
	char *path_copy = strdup(path);
	struct stat sb;
	char bin_path[BUFFER_SIZE];

	if (path == NULL)
	{
		fprintf(stderr, "Error: PATH variable not found\n");
		return (NULL);
	}

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		snprintf(bin_path, sizeof(bin_path), "%s/%s", token, command);

		if (stat(bin_path, &sb) == 0 && sb.st_mode & S_IXUSR)
		{
			free(path_copy);
			return (strdup(bin_path));
		}

		token = strtok(NULL, ":");
	}

	free(path_copy);
	fprintf(stderr, "%s: Command not found\n", command);
	return (NULL);
}

