#include "holberton.h"


/**
 * itoa - converts integer to character.
 * @num: int argument passed.
 * @s: pointer to buffer.
 * @env: struct of shell var.
 * Return: pointer to string.
 */
char *_itoa(int num, char *s, env_t *env)
{
	int i = 0, neg = 0, r, n = num;

	if (n == 0)
	{
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	while (n > 0)
	{
		r = n % 10;
		s[i] = r + '0';
		n = n / 10;
		i++;

	}
	if (neg == 1)
	{
		s[i] = '-';
		i++;
	}

	s[i] = '\0';

	if (s)
		reverse(s, env);
	if (num == -1)
	{
		s[0] = '-';
		s[1] = '1';
		s[2] = '\0';
	}
	return (s);
}
/**
 * reverse - reverses a string.
 * @s: string to be reversed.
 * @env: struct of shell var.
 * Return: pointer to string.
 */
char *reverse(char *s, env_t *env)
{
	char tmp;
	int i, l;

	if (!s)
		env->status = -1;

	for (l = 0; s[l] != '\0'; l++)
		;

	l = l - 1;

	for (i = 0; i < l; i++, l--)
	{
		tmp = s[i];
		s[i] = s[l];
		s[l] = tmp;
	}
	return (s);
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
 * _strdup - creates a copy of a string
 * @string: string to copy
 * Return: copy of the string
 */
char *_strdup(char *string)
{
	int i, len = _strlen(string);
	char *copy;

	if (len <= 0)
		return (NULL);
	copy = malloc(len + 1);
	if (copy == NULL)
		return (NULL);
	copy[len] = '\0';
	for (i = 0; i < len; i++)
		copy[i] = string[i];
	return (copy);
}
