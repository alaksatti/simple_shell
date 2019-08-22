#include "holberton.h"

/**
 * exit-check - checks if the argument is asking to exit shell.
 * @cmd: command
 * @env: struct with env variables.
 * Return: nothing.
 */

void exit_check(char **cmd, env_t *env)
{

        if ((_strcmp(cmd[0], "exit") == 0))
            is_builtin(cmd, env);

	    env->status = 0;
}

/**
 * exit_shell - exits the shell.
 * @cmd: command.
 * @env: struct with env varibales.
 * Return: Nothing:
 */

void exit_shell(char **cmd, env_t *env)
{
	int i;
	char *stat = cmd[1], exit_value = 0;

	if (!stat)
	{
		env->status = 0;
		env->in_shell = 0;
		return;
	}

	for (i = 0; stat[i]; i++)

		if (stat[i] < '0' || stat[i] > '9' || stat[i] == '-')
		{
			env->status = 2;
			env->in_shell = 1;
			return;
		}

	exit_value = atoi(stat);
	env->exit_sig = exit_value;
	env->status = 0;
	env->in_shell = 0;
}
/**
 * echo_exit_status - prints to stdout exit status of last command.
 * @cmd: command
 * @env: struct of env variables.
 * Return: Nothing.
 */

void echo_exit_status(char **cmd, env_t *env)
{
	int digit = env->status, i, j;
	char *buffer, *stat;

	for (i = 0; digit; i++)
		digit /= 10;


	buffer = malloc(sizeof(char) * i + 1);

	if (buffer)
	{

		stat = itoa(env->status, buffer, env);

		for (j = 0; stat[j]; j++)
			_putchar(stat[j]);

		_putchar('\n');
	}

	free(buffer);
}


void echo_parser(char **cmd, env_t *env)
{
	char *parser = cmd[1];


	if (_strcmp("$?", parser) == 0)
		echo_exit_status(cmd, env);

	else if (_strcmp("$$", parser) == 0)
		 echo_ppid(cmd, env);

	env->status = 0;

}

void echo_ppid(char **cmd, env_t *env)
{


	getppid();
	printf("%i", getppid());




}
