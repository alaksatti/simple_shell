#include "holberton.h"

/**
 * free_env_list - frees a linked list of env variables
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

