#include "header.h"

/**
 * arraycleaner - Clears a double pointer
 * @str: Double pointer to clean
 *
 * Return: 1
 */

int arraycleaner(char **str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		free(str[i]);
	}
	free(str);

	return (1);
}
