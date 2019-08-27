#include "holberton.h"


void free_listint2(est_env **head)
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
