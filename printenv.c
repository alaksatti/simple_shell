#include "holberton.h"

/**
 * print_env - prints env variables.
 * @cmd: command.
 * @env: struct of shell variables.
 * Return: 0 on sucess.
 */
int print_env(char **cmd __attribute__((unused)), env_t *env)
{

	est_env *nodescanner = env->env_var;
	char *var, *value;

	if (nodescanner)
	{

		while (nodescanner && nodescanner->envar)
		{
			var = nodescanner->envar;
			value = nodescanner->value;

			write(STDOUT_FILENO, var, _strlen(var));
			_putchar('=');
			write(STDOUT_FILENO, value, _strlen(value));
			_putchar('\n');

			nodescanner = nodescanner->next;
		}

	}


	return (0);
}

/**
 * store_env - stores env var in linked list.
 * @env: struct of shell vars.
 * Return: nothing.
 */
void store_env(env_t *env)
{
	int i;
	char **cmd, **var = environ;


	for (i = 0; var[i]; i++)
	{
		cmd = tokenize_env(var[i], env);

		addnode(&(env->env_var), cmd[0], cmd[1]);

		free(cmd);

	}

	return;

}
