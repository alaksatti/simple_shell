#include "holberton.h"

/**
 * _getenv - returns a copy of the environmental variable value
 * @name: string name of the environmental variable to retrieve
 * @env: linked list containing environmental variables
 * Return: copy of the value of the environmental variable
 */
char *_getenv(char *name, env_t *env)
{
	est_env *env_var = env->env_var;
	int i;

	while (env_var)
	{
		if (_strcmp(name, env_var->envar) == 0)
			return (_strdup(env_var->value));
		env_var = env_var->next;
	}
	return (NULL);
}
