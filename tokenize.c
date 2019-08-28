#include "holberton.h"

/**
 * tokenize - tokenizes string.
 * @line: string to be tokenized.
 * @env: struct of env var.
 * Return: double pointer to tokenized string.
 */
char **tokenize(char *line, env_t *env)
{
	char *cmd, **tmp;
	int i;

	tmp = malloc(sizeof(*tmp) * 1024);
	if (!tmp)
		env->status = -1;
	cmd = strtok(line, " \t\n");
	for (i = 0; cmd; i++)
	{
		tmp[i] = cmd;
		cmd = strtok(NULL, " \t\n");
	}
	tmp[i] = NULL;
	return (tmp);
}

/**
 * tokenize_hash - tokenizes according to hash.
 * @line: line to be tokenized.
 * Return: pointer to tokenized string.
 */
char *tokenize_hash(char *line)
{
	char *cmd;

	cmd = strtok(line, "#");
	return (cmd);
}

/**
 * tokenize_env - tokenize env var.
 * @line: string to be tokenized.
 * @env: struct of shell var.
 * Return: double pointer to tokeized string.
 */
char **tokenize_env(char *line, env_t *env)
{
	char **tmp;
	int i;

	tmp = malloc(sizeof(*tmp) * 2);
	if (!tmp)
		env->status = -1;
	for (i = 0; line[i] != '='; i++)
		;
	line[i] = '\0';
	tmp[0] = &line[0];
	tmp[1] = &line[i + 1];
	return (tmp);
}
