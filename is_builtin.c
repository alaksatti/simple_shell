#include "holberton.h"


int is_builtin(char **cmd)
{
	int i;

	b_t built_in_list[] = {

		{"env", print_env},
		{"exit", exit_shell},
		{"help", help},
		{"history", history},
		{"cd", change_dir},
		{"alias", alias},
		{"setenv", set_env},
		{"unsetenv", unset_env},
		{NULL, NULL},
	};

while (built_in_list)
{
	for (i = 0; built_in_list[i].cmd; i++)
	{
		if(!_strcmp(built_in_list[i].cmd, cmd))
		{
			built_in_list[i].func(cmd);
			return (0);
		}
	}
}

return (-1);

}
