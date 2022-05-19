#include "shell.h"


/**
 * clean_memory - function that clean the memory
 * @command: the command with parameters
 * @path: the path of the command
 * @buffer: the full string of the command
 * @flag: flag if is executing an builtin command(TRUE) or not (FALSE)
 * Return: Nothing
 */

void clean_memory(char **command, char *path, char *buffer, int flag)
{
free(command);
if (flag == FALSE)
free(path);
free(buffer);
}
