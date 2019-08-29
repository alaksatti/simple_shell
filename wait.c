#include "holberton.h"

/**
 * wait_exit - wait and exit.
 * @env: struct of shell vars
 * Return: 0 on sucess.
 */
int wait_exit(env_t *env)
{
	int status;

	wait(&status);
	if (WEXITSTATUS(status) == 127)
		env->count++;
	env->status = WEXITSTATUS(status);
	return (env->status);
}
