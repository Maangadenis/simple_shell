#include "main.h"

/**
 * main - prints a simple shell
 * @ac: number of arguments
 * @argv: arrays of arguments
 *
 * Return: Always 0.
 */
int main(int ac, char **argv)
{
	char *prog_name = argv[0];
	char *command;
	size_t len = 100;
	size_t command_char;

	command = malloc(len * sizeof(char));

	if (command == NULL)
		exit(1);

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			char *prompt = "$ ";

			write(STDOUT_FILENO, prompt, strlen(prompt) + 1);
		}

		if (getline(&command, &len, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 2);

			free(command);
		}
	}

	return (0);
}
