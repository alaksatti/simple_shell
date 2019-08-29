#include "holberton.h"
#include <stdio.h>

/**
* sig_handle -  voids signal and prints new line.
* @signal: signle to be handled.
* Return: 0 on success.
*/

int sig_handle(int signal)
{

        (void)signal;
        write(STDOUT_FILENO, "\n$ ", 3);
        return (0);
}

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

		signal(SIGINT, sig_handle);

		chars_read = getline(&line, &len, stdin);
		if (chars_read == -1)
		{
			if (interactive)
				_putchar('\n');
			free_chars(line, &env);
			exit(env.status);
		}
		if (is_all_delims(line, " \n"))
			continue;
		afterhash = tokenize_hash(line);
		if (!afterhash)
		{	free_chars(line, &env);
			exit(EXIT_SUCCESS);
		}
		args = tokenize(afterhash, &env);
		fail_check = is_builtin(args, &env, line);
		if (fail_check == -1)
		{
			pid = fork();
			if (pid == 0)
				processing(&env, args);

			else
				env.status = wait_exit(&env, args[0]);
		}

		free(args);
	}
	exit(env.status);
}
