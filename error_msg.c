#include "holberton.h"

/**
 * error_msg - prints error message to STDERR_FILENO.
 * @env: struct fo shell variables.
 * @command: command passed.
 * Return: nothing.
 */
int error_msg(env_t *env, char *command)
{
	char buffer[1024];

	itoa(env->count, buffer, env);

	write(STDERR_FILENO, env->progname, _strlen(env->progname));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, buffer, _strlen(buffer));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": not found\n", _strlen(": not found\n"));

	return (0);
}
