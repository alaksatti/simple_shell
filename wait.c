#include "holberton.h"

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
