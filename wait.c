#include "holberton.h"


/**
 * wait_exit - wait and exit.
 * @env: struct of shell vars
 * @args: argument.
 * Return: 0 on sucess.
 */
int wait_exit(env_t *env, char *args)
{
	int status;

	wait(&status);
	if (WEXITSTATUS(status))
	{
		error_msg(env, args);
		env->count++;
	}
	env->status = status;

	return (0);
}
