#include "holberton.h"


void print_env(char **cmd, env_t *env)
{
	extern char **environ;
	unsigned int i, length;


	for (i = 0; environ[i]; i++)
	{
		length = strlen(environ[i]);
                write(STDOUT_FILENO, environ[i], length);
                write(STDOUT_FILENO, "\n", 1);

	}
}
