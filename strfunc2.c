#include "holberton.h"

/**
 * _strlen - returns the length of a string.
 * @s: pointer to char string to be evaluated.
 * Return: string length.
 */

int _strlen(char *s)
{
        int i, count = 0;

        for (i = 0; s[i] != '\0'; i++)
                count++;
        return (count);
}

/**
 * _strcmp - compares two strings.
 * @s1: first string to be evaluated.
 * @s2: Second string to be evaluated.
 * Return: Comparison.
 */



int _strcmp(char *s1, char *s2)
{
        int i = 0;

        while (s1[i] != '\0' && s2[i] != '\0')
        {
                if (s1[i] - s2[i] != 0)
                        break;
                ++i;
        }




        return (s1[i] - s2[i]);

}
