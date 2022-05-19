#include "header.h"
/**
 * getenviroment - gets the env variable needed
 * @name: name of the env variable
 * @environ: env variables
 *
 * Return: the line with the env variable
*/

char *getenviroment(char *name, char **environ)
{
	int i, j, k;

	k = _strlen(name);
	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j] == name[j]; j++)
		{
		}
		if (j == k && environ[i][j] == '=')
			return (environ[i]);

	}
	return (NULL);
}

/**
 * getpath - Gets the PATH variable
 * @environ: enviroment variable
 * @input: command pass by user
 *
 * Return: the splitted PATH variable
*/

char *getpath(char **environ, char *input)
{
	char **path = NULL, *command;
	unsigned int input_len, path_len, i, j, k;
	struct stat st;

	path = split_line(getenviroment("PATH", environ), "=:");
	input_len = _strlen(input);

	for (i = 1; path[i]; i++)
	{
		path_len = _strlen(path[i]);
		command = malloc(sizeof(char) * (path_len + input_len + 2));
		if (!command)
		{
			write(2, "Unable to allocate memory", 25);
			exit(1);
		}

		for (j = 0; path[i][j]; j++)
			command[j] = path[i][j];

		command[j++] = '/';

		for (k = 0; input[k]; k++)
			command[j + k] = input[k];

		command[j + k] = '\0';

		if (stat(command, &st) == 0)
		{
			arraycleaner(path);
			return (command);
		}
		free(command);
	}
	arraycleaner(path);

	return (NULL);
}
