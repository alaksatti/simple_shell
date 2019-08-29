#include "holberton.h"

/**
 * is_builtin - matches command with builtin function.
 * @cmd: command.
 * @env: struct of shell vars.
 * @line: line string for exit to free
 * Return: 0 if found, -1 if not.
 */
int is_builtin(char **cmd, env_t *env, char *line)
{
	int i = 0;

	b_t built_in_list[] = {

		{"env", print_env},
		{"echo", echo_parser},
		{"setenv", set_env},
		{"unsetenv", unset_env},
		{"exit", echo_parser},
		{NULL, NULL},
	};
	while (built_in_list[i].cmd)
	{
		if (!_strcmp(built_in_list[i].cmd, cmd[0]) && i != 4)
			return (built_in_list[i].func(cmd, env));

		if (!_strcmp(built_in_list[i].cmd, cmd[0]))
			return (exit_shell(cmd, env, line));
		++i;
	}
	if (i > 4)
	{
		env->status = -1;
		return (env->status);
	}
	return (0);
}
