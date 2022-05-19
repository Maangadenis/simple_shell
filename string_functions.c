#include "header.h"

/**
 * _strlen - Counts the length of a string
 * @str: string to count
 *
 * Return: the ammount of chars of the string
*/

int _strlen(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
	}

	return (i);
}

/**
 * _strdup - duplicates a given string
 * @str: string to duplicae
 *
 * Return: A pointer to a duplicate of the string given
*/

char *_strdup(char *str)
{
	char *dup;
	int i;

	for (i = 0; str[i]; i++)
	{
	}

	dup = malloc((sizeof(char) * i) + 1);
	if (!dup)
	{
		write(2, "Unable to allocate memory", 25);
		exit(1);
	}

	for (i = 0; str[i]; i++)
	{
		dup[i] = str[i];
	}
	dup[i] = '\0';

	return (dup);
}

/**
 * split_line - splits a string into a 2d array based on delim
 * @str: string to split
 * @delim: delimiter to take into account to split the string
 *
 * Return: A double pointer of chars with the string splitted
*/

char **split_line(char *str, char *delim)
{
	int i, j, chars, lines = 1;
	char **splitted, *token, *strdup;

	strdup = _strdup(str);

	for (i = 0; strdup[i]; i++)
		if (strdup[i] == delim[0] || strdup[i] == delim[1])
			lines++;

	splitted = malloc((lines + 1) * sizeof(char *));
	if (!splitted)
	{
		write(2, "Unable to allocate memory", 25);
		exit(1);
	}
	token = strtok(strdup, delim);
	j = 0;
	while (token)
	{
		chars = _strlen(token);
		splitted[j] = malloc((chars + 1) * sizeof(char));
		if (!splitted)
		{
			write(2, "Unable to allocate memory", 25);
			for (; j != 0 ; j--)
				free(splitted[j - 1]);
			free(splitted);
			exit(1);
			}
		for (i = 0; i < chars; i++)
		{
			splitted[j][i] = token[i];
		}
		splitted[j][i] = '\0';
		j++;
		token = strtok(0, delim);
	}
	splitted[j] = NULL;
	free(strdup);
	return (splitted);
}

/**
 * _strcmp - Compares two arrays
 * @origin: 1st array
 * @comp: 2nd array
 *
 * Return: 1 if same, 0 if different
*/

int _strcmp(char *origin, char *comp)
{
	int i;

	for (i = 0; origin[i] && comp[i]; i++)
	{
		if (origin[i] != comp[i])
			break;
	}

	if (i == _strlen(origin) && i == _strlen(comp))
		return (1);
	else
		return (0);
}

/**
 * numbertostring - Calculates the ammount of digits
 * @n: number to evaluate
 *
 * Return: The ammount of digits
*/

char *numbertostring(int n)
{
	int i = 0, j, number = n;
	char *strnumber;

	for (i = 0; n != 0; i++)
	{
		n = n / 10;
	}

	strnumber = malloc(sizeof(char) * (i + 1));

	for (j = 1; j <= i; j++)
	{
		strnumber[i - j] = (number % 10) + '0';
		number = number / 10;
	}
	strnumber[i] = '\0';
	return (strnumber);
}
