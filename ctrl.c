#include "holberton.h"

/**
 * sig_handle: voids signal and prints new line.
 * @signal: signle to be handled.
 * Return: 0 on success.
 */
/**
int sig_handle(int signal)
{

        (void)signal;
        write(STDOUT_FILENO, "\n$ ", 3);
	return (0);
}

int sigs(void)
{
	signal(SIGINT, sig_handle);
	return (0);
}
**/
