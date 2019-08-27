#include "holberton.h"
#include <stdio.h>

int main(void)
{
	env_t env;
	bool interactive;
	char *line = NULL, **args, **pargs, **pargs2;
	size_t len = 0;
	ssize_t chars_read = 0, chars_write;
	pid_t pid;
	int fail_check = 0, status;
	char *command_path = NULL;

	init_env(&env);
	store_env(&env);
	interactive = is_interactive();
	while (env.in_shell && chars_read != -1)
	{
		if (interactive)
		{
			chars_write = write(STDOUT_FILENO, "$ ", 2);
			env.in_shell = 1;
			if (chars_write == -1)
				return (1);
		}
		chars_read = getline(&line, &len, stdin);
		if (chars_read == -1)
			return (1);
		args = tokenize(line);
		pid = fork();
		if (pid == 0)
		{
			fail_check = 0;
			command_path = search_path(args[0], &env);
/*			if (command_path == NULL)
			  command_path = search_builtins(args[0]);
			 if (command_path == NULL)
				return (1);
*/
			if (command_path != NULL)
				args[0] = command_path;
			fail_check = execve(args[0], args, NULL);
			if (command_path)
				free(command_path);
		}
		else
                {
                        wait(&status);
                        env.status = status;
		}

		if (fail_check == -1)
			fail_check = is_builtin(args, &env);

		if (fail_check == -1)
			write(STDERR_FILENO, "INVALID COMMAND\n", 16);

	}
	return (0);
}
