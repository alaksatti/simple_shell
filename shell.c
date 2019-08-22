#include "holberton.h"
#include <stdio.h>

int main(void)
{
	env_t env;
	bool interactive;
	char *line = NULL, **args;
	size_t len = 0;
	ssize_t chars_read = 0, chars_write;
	pid_t pid;
	int fail_check = 0;
	char *command_path = NULL;


	interactive = is_interactive();
	while (env.in_shell && chars_read != -1)
	{
		init_env(&env);

		if (interactive)
		{
			chars_write = write(STDOUT_FILENO, "$ ", 2);
			if (chars_write == -1)
				return (1);
		}
		chars_read = getline(&line, &len, stdin);
		if (chars_read == -1)
			return (1);

		args = tokenize(line);

		exit_check(args, &env);

		pid = fork();

		if (pid == 0)
		{


			/* search user typed ls*/
/**
			command_path = search_path(args[0]);
			if (command_path == NULL)
			  command_path = search_builtins(args[0]);
			 if (command_path == NULL)
				return (1);

			args[0] = command_path;
**/
			fail_check = execve(args[0], args, NULL);

			if (fail_check == -1)
				fail_check = is_builtin(args, &env);

			if (fail_check == -1)
				printf("ERROR\n");

		}
		else
			wait(NULL);
	}
	return (0);
}
