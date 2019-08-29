#include "holberton.h"

/**
 * handle_eof - handles EOF input
 * @interactive: bool determining interactive mode
 * @line: line to free
 * @env: linked list to free
 */
void handle_eof(bool interactive, char *line, env_t *env)
{
	if (interactive)
		_putchar('\n');
	free_chars(line, env);
	exit(env->status);
}
