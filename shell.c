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
	int fail_check = 0, fail_check2 = 0;

	init_program(av[0], &env);
	interactive = is_interactive();
	while (env.in_shell && chars_read != -1)
	{
		fail_check2 = 0;
		if (interactive)
			inter = interactive_mode(&env);
		if (inter == -1)
			return (1);
		chars_read = getline(&line, &len, stdin);
		if (chars_read == 1)
                        continue;
		if (chars_read == -1)
		{
			free_chars(line, &env);
			return (0);
		}
		afterhash = tokenize_hash(line, &env);
		args = tokenize(afterhash, &env);
		fail_check = is_builtin(args, &env);
		if (fail_check == -1)
		{

			processing(args, &env);





			pid = fork();
			if (pid == 0)
			{
				fail_check2 = pathfinder(args, &env);
				if (fail_check2 == -1)
					return (1);
				return (0);
			}
			else
				wait_exit(&env, args[0]);

		}
		free(args);
	}
	return (0);
}
