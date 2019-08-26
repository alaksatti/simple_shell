#include "holberton.h"


int is_builtin(char **cmd, env_t *env)
{
	int i = 0;

	b_t built_in_list[] = {

		{"env", print_env},
		{"echo", echo_parser},
		{"setenv", set_env},
		{"unsetenv", unset_env},
		{"exit", exit_shell},
/**
		{"help", help},
		{"history", history},
		{"cd", change_dir},
		{"alias", alias},
**/
		{"", NULL},
		{NULL, NULL},
	};


	while (built_in_list[i].cmd)
	{
		if(!_strcmp(built_in_list[i].cmd, cmd[0]))
		{
			return (built_in_list[i].func(cmd, env));
		}
		++i;
	}
	if (i > 5)
	{
		env->status = -1;
		return (-1);
	}

}
