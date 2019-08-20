#ifndef HOLBERTON_H
#define HOLBERTON_H


#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node.
 *
 * Description: singly linked list node structure.
 */


typedef struct b_t
{
	char *cmd;
	void(*func)(char *);
}

/**
 * struct b_t - struct for built in functions.
 * @cmd: command.
 * @func: function associated with command.
 *
 * Description: Builtin function command and corresponding function.
 */

typedef struct hist_t
{

        char *cmd;
        struct hist_t *next;
} hist_t;

/**
 * struct help_list - struct for help files of specific commands.
 * @cmd: command.
 * @file: help file for command.
 *
 * Description: commands and their corresponding help files.
 */

typedef struct help_list
{
	char *cmd;
	char *helpfile;
}help_list;







int _putchar(char c);
void print_env(char **environ);
void exit_shell(char **cmd);
int is_builtin(char **cmd);

#endif
