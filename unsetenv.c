#include "holberton.h"

/**
 * unset_env - unsets an env varable.
 * @cmd: command.
 * @env: struc of env variables.
 * Return: 0 on success.
 */

int unset_env(char **cmd, env_t *env)
{
	char *var;

	var = cmd[1];

	if (env && var && !cmd[2])
	{
		return (deletenode(&env->env_var, var, env));
	}

	else if (!cmd[1])
	{
		error_msg(env, cmd[0]);
		env->count++;
		env->status = 2;
	}

	else
	{
		env->status = 2;
		error_msg(env, cmd[0]);
		env->count++;
	}

	return (env->status);

}
/**
 * sortlist - srots through a linked list.
 * @list: double pointer to head of list.
 * @cmd: command.
 * @env: struct of shell vars.
 *Return: index of env var.
 */


unsigned int sortlist(est_env **list, char *cmd, env_t *env)
{
	unsigned int index = 0;

	est_env *currentnode = *list, *next = *list;

	while (next && _strcmp(cmd, currentnode->envar))
	{
		currentnode = next;
		next = next->next;
		index++;
	}

	if (!next && _strcmp(cmd, currentnode->envar))
	{
		error_msg(env, cmd);
		env->count++;
		env->status = 2;
	}

	return (index);
}



/**
 * deletenode - adds node at end of linked list.
 * @head: env variables linked list.
 * @var: variable to be set.
 * @env: struct carrying shell var.
 * Return: nothing.
 */


int deletenode(est_env **head, char *var, env_t *env)
{
	unsigned int index, idx = 0;
	est_env *nodescanner = *head, *prevnode = *head, *targetnode;

	index = sortlist(head, var, env);

	if (!*head)
		return (0);

	if (index == 0)
	{

		*head = nodescanner->next;
		free(nodescanner);
		return (env->status = 2);
	}
	while (nodescanner)
	{
		if ((idx + 1) == index)
			break;

		idx++;
		prevnode = nodescanner;
		nodescanner = nodescanner->next;

	}


	if ((idx + 1) == index)
	{

		targetnode = nodescanner;
		prevnode->next = targetnode->next;
		free(targetnode);
		env->status = 0;

		return (env->status);
	}

	return (env->status);
}
