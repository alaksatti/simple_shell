#include "holberton.h"

bool is_interactive(void)
{
	if (isatty(STDIN_FILENO))
	{
		return (true);
	}
	return (false);
}
