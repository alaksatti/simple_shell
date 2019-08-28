#include "holberton.h"


/**
 * exit_shell - exits the shell.
 * @cmd: command.
 * @env: struct with env varibales.
 * Return: Nothing:
 */

int exit_shell(char **cmd, env_t *env)
{
	unsigned long i, exit_value = 0;
	char *stat = cmd[1];

	if (!stat)
	{
		env->in_shell = 0;
		return (0);
	}

	for (i = 0; stat[i]; i++)
	{


		if (stat[i] < '0' || stat[i] > '9' || stat[i] == '-')
		{
			env->status = 2;
			error_msg(env, cmd[0]);
			env->count++;
			return (0);
		}



		exit_value = (exit_value * 10) + stat[i] - '0';
		if (exit_value > 2147483647)
		{
			env->status = 2;
			return (0);
		}
	}

	env->status = 0;
	env->in_shell = 0;
	exit(exit_value);
	return (0);
}



/**
 * echo_exit_status - prints to stdout exit status of last command.
 * @cmd: command
 * @env: struct of env variables.
 * Return: Nothing.
 */

int echo_exit_status(char **cmd __attribute__((unused)), env_t *env)
{
	int digit = env->status, i = 0, j;
	char *buffer, *stat;

	if (digit < 0)
	{
		i++;
		digit = -digit;
	}

	for (; digit; i++)
		digit /= 10;


	buffer = malloc(sizeof(char) * i + 1);

	if (buffer)
	{
		stat = itoa(env->status, buffer, env);

		for (j = 0; stat[j]; j++)
			_putchar(stat[j]);

		_putchar('\n');
	}

	env->status = 0;

	free(buffer);

	return (0);
}
/**
 * echo_parser - parses echo command.
 * @cmd: command.
 * @env: struct of shell variables.
 * Return: 0 on success.
 */

int echo_parser(char **cmd, env_t *env)
{
	char *parser = cmd[1];


	if (_strcmp("$?", parser) == 0 && cmd[1])
		return (echo_exit_status(cmd, env));

	else if (_strcmp("$$", parser) == 0 && cmd[1])
		return (echo_pid(cmd, env));

	else
	{
		env->status = -1;
		error_msg(env, cmd[0]);
		env->count++;
		return (0);
	}

	return (0);
}
/**
 * echo_pid - prints pid.
 * @cmd: command.
 * @env: struct of shell var.
 * Return: 0 on success.
 */

int echo_pid(char **cmd, env_t *env)
{
	int mypid, i, j;
	char *buffer, *pid;

	mypid = env->pid;


	for (i = 0; mypid; i++)
		mypid /= 10;


	buffer = malloc(sizeof(char) * i + 1);

	if (buffer)
	{
		mypid = env->pid;

		pid = itoa(mypid, buffer, env);

		for (j = 0; pid[j]; j++)
			_putchar(pid[j]);

		_putchar('\n');
		env->status = 0;

	}

	else
	{
		env->status = -1;
		error_msg(env, cmd[0]);
		env->count++;
	}

	free(buffer);

	return (0);
}
