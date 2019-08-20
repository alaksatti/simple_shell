#include "holberton.h"

char *search_path(char *command)
{
	char *dir, *value = _getenv("PATH");
	char *command_path;
	int i, j;
	struct stat st;

	dir = strtok(value, ":\n");
	while (dir != NULL)
	{
		printf("%s\n", dir);
		/* /bin / ls '\0' */
		command_path = malloc(strlen(dir) + strlen(command) + 2);
		for (i = 0; dir[i]; i++)
			command_path[i] = dir[i];
		dir[i] = '/';
		i++;
		for (j = 0; command[j]; j++)
			command_path[i + j] = command[j];
		command_path[i + j] = '\0';
		if (stat(command_path, &st) == 0)
			return (command_path);
		free(command_path);
		dir = strtok(NULL, ":\n");
	}
	return (NULL);
}
