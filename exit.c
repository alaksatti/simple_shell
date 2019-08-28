#include "holberton.h"


/**
 * exit_shell - exits the shell.
 * @cmd: command.
 * @env: struct with env varibales.
 * Return: Nothing:
 */

int exit_shell(char **cmd, env_t *env)
{
	int i;
	char *stat = cmd[1], exit_value = 0;

	if (!stat)
	{
		env->in_shell = 0;
		return(0);
	}

	for (i = 0; stat[i]; i++)

		if (stat[i] < '0' || stat[i] > '9' || stat[i] == '-')
		{
			env->status = 2;
			error_msg(env, cmd[0]);
			env->count++;
			return (0);
		}

	exit_value = atoi(stat);

	printf("%i\n", exit_value);
	env->status = exit_value;
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

int echo_exit_status(char **cmd, env_t *env)
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

	return (0);
}


int echo_parser(char **cmd, env_t *env)
{
	char *parser = cmd[1];

	if (!cmd[1])
	{
		env->status = -1;
		error_msg(env, parser);
		return (0);

	}

	else if (_strcmp("$?", parser) == 0 && cmd[1])
		return(echo_exit_status(cmd, env));

	else if (_strcmp("$$", parser) == 0 && cmd[1])
		return(echo_pid(cmd, env));

	else
	{
		env->status = -1;
		error_msg(env, cmd[0]);
		env->count++;
		return (0);
	}

	return (0);
}

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
