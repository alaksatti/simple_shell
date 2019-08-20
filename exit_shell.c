#include "holberton.h"


void exit_shell(char **cmd)
{
	int i;

	for (i = 0; cmd[i]; i++)
		free(cmd[i]);

	if (cmd[i] == NULL)
		free(cmd[i]);

	free(cmd);

	exit(EXIT_SUCCESS);

}
