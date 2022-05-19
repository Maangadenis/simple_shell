#include "shell.h"


/**
 * find_path - find the path in the enviroment variables
 * Return: the path
 */

char *find_path(void)
{
int i = 0, j = 0;
char buffer[5] = "INIT\0";

while (environ[i] != NULL)
{
for (j = 0; j < 4; j++)
{
buffer[j] = environ[i][j];
}
if (_strcmp(buffer, "PATH") == 0)
return (full_path(environ[i]));
i++;
}
return (NULL);
}

/**
 * full_path - return the path without(PATH=)
 * @path: the path
 * Return: the path without(PATH=)
 */

char *full_path(char *path)
{
char *copy = NULL;
int i = 0, j = 0;

copy = (char *)malloc(sizeof(char) * _strlen(path));
if (copy == NULL)
exit(1);
for (i = 5, j = 0; path[i] != '\0'; i++, j++)
copy[j] = path[i];
return (copy);
}

/**
 * split_path - split the path in differents folders
 * @command: the command to concatenate with the folders of the path
 * Return: the folder where is the executable or NULL if is not found
 */

char *split_path(char *command)
{
char *token = NULL, *fpath = NULL, *path = NULL;
struct stat fileStat;

path = find_path();
if (path == NULL)
return (NULL);
token = strtok(path, ":");
fpath = malloc(sizeof(char) * BUFFSIZE);
if (fpath == NULL)
{
return (NULL);
}
while (token != NULL)
{
fpath[0] = '\0';
fpath = _strcat(fpath, token);
fpath = _strcat(fpath, "/");
fpath = _strcat(fpath, command);
if (stat(fpath, &fileStat) == 0)
{
free(path);
return (fpath);
}
token = strtok(NULL, ":");
}
free(path);
free(fpath);
return (NULL);
}
