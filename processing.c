#include "holberton.h"

/**
 * processing - calls pathfinder.
 * @env: struct of shell vars.
 * @args: argument.
 * Return: Nothing.
 */
void processing(env_t *env, char **args)
{
	int fail_check2 = 0;

	fail_check2 = pathfinder(args, env);
	if (fail_check2 == -1)
	{
		error_msg(env, args[0]);
		env->count++;
		exit(127);
	}
	exit(0);
}
