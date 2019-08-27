#include "holberton.h"

env_t *init_env(env_t *env, char *progname)
{

	env->in_shell = 1;
	env->status = 0;
	env->exit_sig = 0;
	env->env_var = NULL;
	env->pid = getpid();
	env->count = 0;
	env->progname = progname;
	return (env);




}
