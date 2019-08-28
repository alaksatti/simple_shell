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
	int fail_check = 0;

	init_program(av[0], &env);
	interactive = is_interactive();
	while (env.in_shell && chars_read != -1)
	{
		if (interactive)
			inter = interactive_mode(&env);
		if (inter == -1)
			return (1);
/**
		signal(SIGINT, sig_handle);
**/
		chars_read = getline(&line, &len, stdin);
		if (is_all_delims(line, " \n"))
			continue;
		if (chars_read == -1)
		{
			free_chars(line, &env);
			exit(EXIT_FAILURE);
		}
		afterhash = tokenize_hash(line);
		if (!afterhash)
			exit(EXIT_SUCCESS);
		args = tokenize(afterhash, &env);
		fail_check = is_builtin(args, &env);
		if (fail_check == -1)
		{
			pid = fork();
			if (pid == 0)
				processing(&env, args);

			else
				wait_exit(&env, args[0]);
		}

		free(args);
	}
	return (env.status);
}
