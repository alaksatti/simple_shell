#include "holberton.h"

char *search_path(char *command, env_t *env)
{
	char *dir, *value = _getenv("PATH", env);
	char *command_path;
	int i, j;
	struct stat st;

	dir = strtok(value, ":\n");
	while (dir != NULL)
	{
		printf("%s\n", dir);
		command_path = malloc(_strlen(dir) + _strlen(command) + 2);
		if (command_path == NULL)
			exit(1);
		for (i = 0; dir[i]; i++)
			command_path[i] = dir[i];
		dir[i] = '/';
		printf("full path: %s\n", command_path);
		i++;
		for (j = 0; command[j]; j++)
		{ 
			printf("copy: %c into %d\n", command[j], i + j);
			command_path[i + j] = command[j];
		}
		command_path[i + j] = '\0';
		printf("full path: %s\n", command_path);
		if (stat(command_path, &st) == 0)
			return (command_path);
		free(command_path);
		dir = strtok(NULL, ":\n");
	}
	return (NULL);
}
