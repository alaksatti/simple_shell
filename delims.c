#include "holberton.h"

/**
 * is_delim - checks if a character is a delimiter
 * @c: character to check
 * @delims: string containing delimiters to match
 * Return: true if delimiter, false if not
 */
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

/**
 * is_all_delims - checks if all chars in a string are delimiters
 * @line: string to check
 * @delims: delimiters to match
 * Return: true if all are delims, false if not
 */
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
