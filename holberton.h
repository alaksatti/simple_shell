#ifndef HOLBERTON_H
#define HOLBERTON_H


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>


extern char **environ;


/**
 * struct est_env - singly linked list.
 * @envar: env var to be evaluated.
 * @value: value of env var.
 * @next:next node in the list.
 *
 * Description: singly linked list that establishes env var.
 */

typedef struct est_env
{
	char  *envar;
	char *value;
	struct est_env *next;


} est_env;
/**
 * struct hist_t - singly linked list
 * @cmd: string - (malloc string)
 * @next: points to the next node.
 *
 * Description: singly linked list node structure.
 */


typedef struct hist_t
{

	char *cmd;
	struct hist_t *next;
} hist_t;


/**
 * struct env_t - structure of specific shell environment variables.
 * @exit_sig: holds the exit signal.
 * @in_shell: in shell or not.
 * @status: status of last command.
 * @env_var: linked list of env var.
 * @pid: process id.
 * @count: number of errors.
 * @progname: program name.
 * @history: linked list of commands entered.
 *Description: shell variable.s
 */

typedef struct env_t
{
	int in_shell;
	int status;
	int exit_sig;
	struct est_env *env_var;
	pid_t pid;
	hist_t history;
	int count;
	char *progname;
} env_t;


/**
 * struct b_t - struct for built in functions.
 * @cmd: command.
 * @func: function associated with command.
 *
 * Description: Builtin function command and corresponding function.
 */

typedef struct b_t
{
	char *cmd;
	int (*func)(char **, env_t *);
} b_t;


/**
 * struct help_list - struct for help files of specific commands.
 * @cmd: command.
 * @helpfile: help file for command.
 *
 * Description: commands and their corresponding help files.
 */

typedef struct help_list
{
	char *cmd;
	char *helpfile;
} help_list;

char *_strdup(char *string);
int _strlen(char *s);
bool is_interactive(void);
char *_getenv(char *name, env_t *env);
char *search_path(char *command, env_t *env);
int _putchar(char c);
int print_env(char **environ, env_t *env);
void exit_check(char **cmd, env_t *env);
int exit_shell(char **cmd, env_t *env);
int is_builtin(char **cmd, env_t *env);
int wordcount(char *s, char *d);
char *eachword(char *s);
char **_strtok(char *str, char *d);
int _strcmp(char *s1, char *s2);
env_t *init_env(env_t *env, char *progname);
int exit_status(char **cmd, env_t *env);
char *reverse(char *s, env_t *env);
char *itoa(int num, char *s, env_t *env);
int echo_parser(char **cmd, env_t *env);
int echo_pid(char **cmd, env_t *env);
int echo_exit_status(char **cmd, env_t *env);
void addnode(est_env **head, char *var, char *value);
int set_env(char **cmd, env_t *env);
void reverse_list(est_env **head);
int print_list(env_t **env);
int unset_env(char **cmd, env_t *env);
unsigned int sortlist(est_env **list, char *cmd, env_t *env);
int deletenode(est_env **head, char *var, env_t *env);
char **tokenize_env(char *line, env_t *env);
char *tokenize_hash(char *line, env_t *env);
void store_env(env_t *env);
char **tokenize(char *line, env_t *env);
void free_listint2(est_env **head);
char *_strdup(char *str);
void error_msg(env_t *env, char *command);
void rearrange(est_env **head, est_env *node);
int free_chars(char *line, env_t *env);
int interactive_mode(env_t *env);
int pathfinder(char **args, env_t *env);
void init_program(char *av, env_t *env);

#endif
