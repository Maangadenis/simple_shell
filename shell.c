#include "header.h"


/**
 * execute - Runs a given program
 * @command: command to run
 * @arguments: arguments to pass to execve
 * @av: name of the program
 *
 * Return: -1 if it breaks, 0 if it doesn't
*/

int execute(char *command, char **arguments, char *av)
{
	int child;

	child = fork();

	if (child != 0)
		wait(NULL);

	if (child == 0 && execve(command, arguments, NULL) == -1)
	{
		write(2, av, _strlen(av));
		perror(": ");
		return (errno);
	}

	return (0);
}

/**
 * main - Entry function
 * @ac: Ammount of arguments passed
 * @av: Arguments passed
 * @env: Enviroment variables
 *
 * Return: 0 if success
*/

int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *line, **splitt;
	size_t size = 32;
	int *error_value = malloc(sizeof(int)), read, error, lines = 1;

	*error_value = 0;
	line = line_maker(size);
	if (!line)
		exit(-1);
	while (1)
	{
		if (isatty(0) == 1)
			write(1, "(mcpshell) ", 11);
		read = getline(&line, &size, stdin);
		if (read == -1)
			break;
		if (read == 1)
			continue;
		line[read - 1] = ' ';
		splitt = split_line(line, " ");
		if (!*splitt)
		{
			free(splitt);
			continue;
		}
		switch (shell(line, splitt, lines, env, av, error_value))
		{
			case 0:
				error = *error_value;
				free(error_value);
				exit(error);
			case 1:
				continue;
		}
		lines++;
	}
	free(line);
	error = *error_value;
	free(error_value);
	return (error);
}


/**
 * shell - our shell
 * @line: the imput of the user
 * @split: proccessed input
 * @lines: ammount of lines
 * @env: enviroment variable
 * @av: arguments
 * @err: error pointer
 *
 * Return: 10 if success, 0 if exit, 1 if continue, -1 if return-1
*/

int shell(char *line, char **split, int lines, char **env, char **av, int *err)
{
	char *command;
	int i;
	struct stat st;

	if (_strcmp(split[0], "exit"))
	{
		arraycleaner(split);
		free(line);
		return (0);
	}
	if (_strcmp(split[0], "env"))
	{
		for (i = 0; env[i]; i++)
		{
			write(1, env[i], _strlen(env[i]));
			write(1, "\n", 1);
		}
		return (arraycleaner(split));
	}
	if (stat(split[0], &st) == 0)
	{
		*err = execute(split[0], split, av[0]);
		return (arraycleaner(split));
	}
	command = getpath(env, split[0]);
	if (!command)
	{
		*err = 127;
		not_found(lines, split[0], av);
	}
	else if (execute(command, split, av[0]) == -1)
	{
		perror(": ");
		*err = errno;
		return (0);
	}
	arraycleaner(split);
	free(command);
	return (10);
}

/**
 * not_found - Prints the error message
 * @lines: Ammount of lines so far
 * @split: proccessed input
 * @av: ammount of lines
*/

void not_found(int lines, char *split, char **av)
{
	char *strlines = numbertostring(lines);

	write(2, av[0], _strlen(av[0]));
	write(2, ": ", 2);
	write(2, strlines, _strlen(strlines));
	write(2, ": ", 2);
	write(2, split, _strlen(split));
	write(2, ": not found\n", 12);
	free(strlines);
}

/**
 * line_maker - Creates the input variable
 * @size: Size of the malloc
 *
 * Return: input
 */

char *line_maker(size_t size)
{
	char *input;

	input = (malloc(sizeof(char) * size));
	if (!input)
		write(2, "Unable to allocate memory", 25);

	return (input);
}
