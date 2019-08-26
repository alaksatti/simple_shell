#include "holberton.h"

/**
 * unset_env - unsets an env varable.
 * @cmd: command.
 * @env: struc of env variables.
 */

int unset_env(char **cmd, env_t *env)
{
	est_env *nodescanner = env->env_var;
	char *var, *node;

	var = cmd[1];



	printf("starts\n\n\n\n\n ");

	if (!nodescanner)
	{
      		write(STDERR_FILENO, "VARIABLE NOT PREV SET\n", 23);
       		env->status = -1;
		printf("finishes in empty list\n\n\n\n\n ");
		return (0);
	}

	printf("finished here");

	 if (env && var && !cmd[2])
	 {

	    while (nodescanner)
	    {
		    node = (nodescanner->envar);
		    if (!_strcmp(var, node))
		    {
			    printf("enters if\n\n\n\n\n ");
			    return (deletenode(&nodescanner, var));
			    printf("After");
		    }

		    nodescanner = (nodescanner->next);
		    printf("in while\n\n\n\n\n ");
	    }

	    printf("finished hereiuerfkjbef");
	 }


	else if(!cmd[1])
	{
		write(STDERR_FILENO, "ARGUMENT ERROR\n", 15);
		env->status = -1;
	}

	else
        {
                env->status = -1;
                write(STDERR_FILENO, "Invalid Argument\n", 17);
        }

	 return (0);


	 printf("finished here");
}



unsigned int sortlist(est_env **list, char *cmd)
{
        unsigned int index = 0;

        est_env *currentnode = *list, *next = *list;

        while (*list && _strcmp(cmd, currentnode->envar))
        {
                currentnode = *list;
                *list = next->next;
                index++;

        }

        if (!*list)
        {
                write(STDERR_FILENO, "VARIABLE NOT PREV SET\n", 20);
        }

        return (index);
}



/**
 * deletenode - adds node at end of linked list.
 * @head: env variables linked list.
 * @var: variable to be set.
 * @value:  value of variable.
 * Return: nothing.
 */


int deletenode(est_env **head, char *var)
{
	unsigned int index, idx = 0;
	est_env *nodescanner = *head, *prevnode = *head, *targetnode;

	index = sortlist(head, var);

	if (!*head)
                return (0);

        if (index == 0)
        {

                *head = nodescanner->next;
                free(nodescanner);
                return (1);
        }
        while (nodescanner && idx != index)
        {
                idx++;
                prevnode = nodescanner;
                nodescanner = nodescanner->next;


        }
        if (idx == index)
        {

                targetnode = nodescanner;

                prevnode->next = targetnode->next;

                free(targetnode);

                return (1);
        }

	return (0);
}
