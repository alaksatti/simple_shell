#include "holberton.h"

/**
 * _putchar - prints one character at a time to the stdout
 * @c: character to be printed
 * Return:character.
 */
int _putchar(char c)
{
        return (write(STDOUT_FILENO, &c, 1));
}
