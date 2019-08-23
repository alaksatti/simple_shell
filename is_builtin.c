#include "holberton.h"


int is_builtin(char **cmd, env_t *env)
{
	int i = 0;

	b_t built_in_list[] = {

		{"env", print_env},
		{"exit", exit_shell},
		{"echo", echo_parser},
		{"setenv", set_env},
		{"unsetenv", unset_env}, 
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
			built_in_list[i].func(cmd, env);
			return;
		}
		++i;
	}


	write(STDERR_FILENO, "Invalid built-in command\n", 25);


	return (-1);
}
