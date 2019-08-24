#include "holberton.h"

/**
 * set_env - sets an env variable.
 * @cmd: command.
 * @env: struc of env variables.
 * Return: nothing.
 */


int set_env(char **cmd, env_t *env)
{

	est_env *nodescanner = env->env_var;
	char *var, *value, *node;


	var = cmd[1];
	value = cmd[2];


	if (env && value && !cmd[3])
	{
		if (!nodescanner)
		{
			addnode(&env->env_var, var, value);
			return;
		}

		while (nodescanner)
		{
			node = (nodescanner->envar);

			if (!_strcmp(var, node))
			{
				(nodescanner->value) = value;
				return;
			}

			nodescanner = (nodescanner->next);
		}

		if (!nodescanner && _strcmp(var, node))
		    addnode(&(env->env_var), var, value);
	}
	else
	{
		env->status = -1;
		write(STDERR_FILENO, "Invalid Argument\n", 17);
	}

/**
	reverse_list(&(env->env_var));
**/

	return (0);
}

/**
 * addnode - adds node at end of linked list.
 * @head: env variables linked list.
 * @var: variable to be set.
 * @value:  value of variable.
 * Return: nothing.
 */


void addnode(est_env **head, char *var, char *value)
{

        est_env  *node, *end;

        node = malloc(sizeof(est_env));


        if (node)

        {
                node->envar = NULL;
                node->value = NULL;
		node->next = NULL;

                if (var && value)
                {
                        node->envar = strdup(var);
                        if (!node->envar)
			{
                                free(node);
                                return;
                        }
			node->value = strdup(value);
			if (!node->envar)
                        {
				free(node->envar);
                                free(node);
                                return;
                        }
                }

                else
		{
                        node->envar = NULL;
			node->value = NULL;
		}

	}

     if (*head)
        {
                end = *head;
                while (end->next)
                        end = end->next;
                end->next = node;
        }
        else

                *head = node;
}

/**
 * print_list - prints linked list.
 * @h: pointer to linked list.
 * Return: nothing.
 */

int print_list(env_t *env)
{
	est_env *h = env->env_var;

	int i;

        while (h)
        {
                if (h->envar)
		{


			for (i = 0; h->envar[i] != '\0'; i++)
				_putchar(h->envar[i]);

			_putchar('=');

			for (i = 0; h->value[i] != '\0'; i++)
				_putchar(h->value[i]);

			_putchar('\n');
		}

                else
                        write(STDERR_FILENO, "CANNOT PRINT SETENV VAR\n", 25);

                h = h->next;

        }
	return (0);
}
/**
 * reverse_list - reverses linked list.
 * @head: pointer to end of list.
 * Return: Nothing.
 */
void reverse_list(est_env **head)
{
        est_env *next, *prevnode = NULL;



        while (*head)
        {


                next = (*head)->next;

                (*head)->next = prevnode;

                prevnode = *head;

                *head = next;

        }

        *head = prevnode;
}



unsigned int sortlist(est_env *list, char *cmd)
{
	unsigned int index = 0;

	est_env *currentnode = list, *next;

        while (list && _strcmp(cmd, currentnode->envar))
        {
		currentnode = list;
		list = list->next;
		index++;

	}

	if (!list)
	{
		write(STDERR_FILENO, "VARIABLE NOT PREV SET\n", 20);
		return;
	}

	return (index);
}


/**
 * unset_env - deletes an env variable.
 * @cmd: command.
 * @env: struc of variables.
 * Return: Nothing.
 */
int unset_env(char **cmd, env_t *env)
{

        est_env *nodescanner = env->env_var, *prevnode = env->env_var;
	est_env *targetnode;
        unsigned int idx = 0, index;


	if (!nodescanner)
	{
		write(STDERR_FILENO, "VARIABLE NOT PREV SET\n", 23);
		env->status = -1;
		return;
	}


	if (!cmd[1] && cmd[2])
	{
		write(STDERR_FILENO, "ARGUMENT ERROR\n", 15);
		env->status = -1;
		return;
	}


	index = sortlist(env->env_var, cmd[1]);

	printf("%i\n\n\n\n\n", index);
        if (index == 0)
        {

                env->env_var = env->env_var->next;
		free(nodescanner->envar);
		free(nodescanner->value);
                free(nodescanner);
                env->status = -1;
        }
        while (nodescanner && idx != index)
        {
                idx++;
                prevnode = nodescanner;
                nodescanner = nodescanner->next;


        }
        if (idx == index)
        {
		printf("/n/nright here");

		printf("%s\n\n %s", nodescanner->envar,  prevnode->next->envar );
                targetnode = nodescanner;

                prevnode->next = targetnode->next;

		free(targetnode->envar);
		free(targetnode->value);
                free(targetnode);

                env->status = 0;
        }

	else
		env->status = -1;
	return (0);
}
