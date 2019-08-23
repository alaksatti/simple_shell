#include "holberton.h"

env_t *init_env(env_t *env)
{
	env->in_shell = 1;
	env->status = 0;
	env->exit_sig = 0;
	env->env_var = NULL;

	return (env);
}
