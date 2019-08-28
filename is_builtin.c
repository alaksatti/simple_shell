#include "holberton.h"

/**
 * is_builtin - matches command with builtin function.
 * @cmd: command.
 * @env: struct of shell vars.
 * Return: 0 if found, -1 if not.
 */
int is_builtin(char **cmd, env_t *env)
{
	int i = 0;

	b_t built_in_list[] = {

		{"env", print_env},
		{"echo", echo_parser},
		{"setenv", set_env},
		{"unsetenv", unset_env},
		{"exit", exit_shell},
		{"", NULL},
		{NULL, NULL},
	};


	while (built_in_list[i].cmd)
	{
		if (!_strcmp(built_in_list[i].cmd, cmd[0]))
		{
			return (built_in_list[i].func(cmd, env));
		}
		++i;
	}
	if (i > 4)
	{
		env->status = -1;
		return (-1);
	}
	return (0);
}
