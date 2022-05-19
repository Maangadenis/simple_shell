#include "shell.h"


/**
 * obtain_home - obtain home from the enviroment variables
 * Return: the home var
 */

char *obtain_home(void)
{
int i = 0, j = 0;
char buffer[5] = "INIT\0";

while (environ[i] != NULL)
{
for (j = 0; j < 4; j++)
{
buffer[j] = environ[i][j];
}
if (_strcmp(buffer, "HOME") == 0)
return (full_path(environ[i]));
i++;
}
return (NULL);
}

/**
 * full_home - Return the home var without the test "HOME="
 * @home: home var
 * Return: Return the home var without the test "HOME="
 */

char *full_home(char *home)
{
char *copy = NULL;
int i = 0, j = 0;

copy = (char *)malloc(sizeof(char) * _strlen(home));
if (copy == NULL)
exit(1);
for (i = 5, j = 0; home[i] != '\0'; i++, j++)
copy[j] = home[i];
return (copy);
}
