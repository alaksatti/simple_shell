#include "holberton.h"


/**
 * pathfinder - finds the command path and exeutes.
 * @args: command.
 * @env: struct of shell var.
 * Return: nothing.
 */

int pathfinder(char **args, env_t *env)
{
	char *command_path = NULL;
	int fail_check2;

	if (!(args[0][0] == '.' && args[0][1] == '/'))
		command_path = search_path(args[0], env);

	if (command_path != NULL)
		fail_check2 = execve(_strdup(command_path), args, NULL);
	else
		fail_check2 = execve(_strdup(args[0]), args, NULL);

	if (command_path)
	{
		free(command_path);
		command_path = NULL;
	}
	return (fail_check2);
}
