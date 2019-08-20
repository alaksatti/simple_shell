#include "holberton.h"

int main(void)
{
	bool interactive;
	char *line = NULL, **args;
	size_t len = 0;
	ssize_t chars_read = 0, chars_write;
	pid_t pid;
	int exec_fail;
	char *command_path = NULL;

	interactive = is_interactive();
	while (chars_read != -1)
	{
		if (interactive)
		{
			chars_write = write(STDOUT_FILENO, "$ ", 2);
			if (chars_write == -1)
				return (1);
		}
		chars_read = getline(&line, &len, stdin);
		if (chars_read == -1)
			return (1);
		args = tokenize(line);
		
		pid = fork();
		
		if (pid == 0)
		{
			/* search user typed ls*/
			command_path = search_path(args[0]);
/*			if (command_path == NULL)
			  command_path = search_builtins(args[0]);
*/			 if (command_path == NULL)
				return (1);
			args[0] = command_path;
			exec_fail = execve(args[0], args, NULL);
			if (exec_fail == -1)
				return(1);
		}
		else
			wait(NULL);
	}
	return (0);
}
