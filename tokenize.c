#include "holberton.h"

char **tokenize(char *line)
{
        char *cmd, **tmp;
        int i;

        tmp = malloc(sizeof(*tmp) * 1024);
        if (!tmp)
                exit(1);
        cmd = strtok(line, " \t\n");
        for (i = 0; cmd; i++)
        {
                tmp[i] = cmd;
                cmd = strtok(NULL, " \t\n");
        }
        return (tmp);
}
