#include "holberton.h"

/**
 * is_interactive - determines if in interactive more or not.
 * Return: True if interactive, false if not..
 */

bool is_interactive(void)
{
	if (isatty(STDIN_FILENO))
	{
		return (true);
	}
	return (false);
}

/**
 * interactive_mode - sets up env for interactive mode.
 * @env: struct of shell vars.
 * Return: 1 if unable to print.
 */
int interactive_mode(env_t *env)
{
	ssize_t chars_write;

	chars_write = write(STDOUT_FILENO, "$ ", 2);

	env->in_shell = 1;

	return (chars_write);

}
