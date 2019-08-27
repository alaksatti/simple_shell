#include "holberton.h"

char *_getenv(char *name, env_t *env)
{
	est_env *env_var = env->env_var;
	int i;

	while (env_var)
	{
		for (i = 0; env_var->envar[i]; i++)
		{
			if (env_var->envar[i] != name[i])
				break;
		}
		if (i == _strlen(name))
		{
			return (env_var->value);
		}
		env_var = env_var->next;
	}
	return (NULL);
}
