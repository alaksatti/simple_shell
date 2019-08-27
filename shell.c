#include "holberton.h"
#include <stdio.h>

int main(int ac, char *av[])
{
	env_t env;
	bool interactive;
	char *line = NULL, **args, **pargs, **pargs2;
	size_t len = 0;
	ssize_t chars_read = 0, chars_write;
	pid_t pid;
	int fail_check = 0, fail_check2 = 0, status;
	char *command_path = NULL;

	(void)ac;
	init_env(&env, av[0]);
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
		{
			free(line);
			return (1);
		}

		args = tokenize(line);



		fail_check = is_builtin(args, &env);

		if (fail_check == -1)
		{
			pid = fork();

			if (pid == 0)
			{
				command_path = search_path(args[0], &env);
				if (command_path != NULL)
					args[0] = command_path;
				fail_check2 = execve(_strdup(args[0]), args, NULL);
/*				if (command_path)
				{
					free(command_path);
					command_path = NULL;
				}
*/			}
			else
			{
				wait(&status);
				env.status = status;
			}

			if (fail_check2 == -1)
			{		
				error_msg(&env, args[0]);
				env.count++;
			}
		}

	}

	return (0);
}
