#include "holberton.h"


void handle_signal(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n$ ", 3);

}
