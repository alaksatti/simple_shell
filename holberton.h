#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

bool is_interactive(void);
char **tokenize(char *line);
char *_getenv(const char *name);
char *search_path(char *command);

#endif
