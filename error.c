#include "holberton.h"



void invalidarg(char *errmsg)
{
	write(STDOUT_FILENO, "Invalid argument", 15);

}
