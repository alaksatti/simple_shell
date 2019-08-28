#include "holberton.h"

/**
 * free_env_list - frees a linked list of env variables.
 *@head: double pointer to beginning of linked list.
 *Return: nothing.
 */
void free_env_list(est_env **head)
{
	est_env *thisnode;

	if (!head || !*head)
		return;
	while (*head && head)
	{
		thisnode = *head;
		*head = (*head)->next;
		free(thisnode->envar);
		free(thisnode->value);
		free(thisnode);

	}
	*head = NULL;
}
/**
 * free_chars - free chars if getline returns -1;
 * @line: malloced string.
 * @env: struct of shell vars.
 * Return: 1 on success
 */

int free_chars(char *line, env_t *env)
{

	free(line);
	free_env_list(&(env->env_var));
	return (1);
}
