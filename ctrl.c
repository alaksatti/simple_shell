#include "holberton.h"

/**
 * handle_signal - voids a signal and prints prompt.
 * @signal: signal to be ignored.
 * Return: nothing.
 */

void handle_signal(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n$ ", 3);

}
