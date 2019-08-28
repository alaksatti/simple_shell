#include "holberton.h"

bool is_delim(char c, char *delims)
{
	int i;

	for (i = 0; delims[i]; i++)
	{
		if (c == delims[i])
			return (true);
	}
	return (false);
}

bool is_all_delims(char *line, char *delims)
{
	int i;

	for (i = 0; line[i]; i++)
	{
		if (!is_delim(line[i], delims))
			return (false);
	}
	return (true);
}
