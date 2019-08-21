#include "holberton.h"


int is_builtin(char **cmd)
{
	int i = 0;

	b_t built_in_list[] = {

		{"env", print_env},
		{"exit", exit_shell},
/**
		{"help", help},
		{"history", history},
		{"cd", change_dir},
		{"alias", alias},
		{"setenv", set_env},
		{"unsetenv", unset_env},
**/
		{"", NULL},
		{NULL, NULL},
	};


while (built_in_list[i].cmd)
{
	if(!_strcmp(built_in_list[i].cmd, cmd[0]))
	{
		built_in_list[i].func(cmd);
		return (0);
	}

	++i;
}
return (-1);

}
