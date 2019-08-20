#include "holberton.h"
extern char **environ;

char *_getenv(const char *name)
{
	char *value = NULL;
	int i, j, len;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; name[j] && environ[i][j] == name[j]; j++)
			;
		if (environ[i][j] == '=')
			break;
	}
	j++;
	for (len = 0; environ[i][len + j]; len++)
		;
	value = malloc(len + 1);
	if (!value)
		exit(1);
	for (len = 0; environ[i][len + j]; len++)
		value[len] = environ[i][len + j];
	return (value);
}
