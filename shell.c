#include "holberton.h"
#include <stdio.h>


/**
 * main - main file for shell.
 * @ac: number of arguments.
 * @av: argument strings.
 * Return: 0 on success.
 */
int main(int ac __attribute__((unused)), char *av[])
{
	env_t env;
	bool interactive;
	char *line = NULL, **args, *afterhash;
	ssize_t chars_read = 0, inter;
	size_t len;
	pid_t pid;
	int fail_check = 0, fail_check2 = 0, status;

	init_program(av[0], &env);
	interactive = is_interactive();
	while (env.in_shell && chars_read != -1)
	{
		if (interactive)
			inter = interactive_mode(&env);
		if (inter == -1)
			return (1);
		chars_read = getline(&line, &len, stdin);
		if (chars_read == -1)
		{
			free_chars(line, &env);
			return (0);
		}
		if (chars_read == 1)
			continue;
		afterhash = tokenize_hash(line);
		args = tokenize(afterhash, &env);
		fail_check = is_builtin(args, &env);
		if (fail_check == -1)
		{
			pid = fork();
			if (pid == 0)
			{
				fail_check2 = pathfinder(args, &env);
				if (fail_check2 == -1)
					return (1);
				return (0);
			}
			else
			{
				wait(&status);
				if (WEXITSTATUS(status))
				{
					error_msg(&env, args[0]);
					env.count++;
				}
				env.status = status;
			}
		}
		free(args);
	}
	return (0);
}
