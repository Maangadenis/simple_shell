#include "shell.h"


/**
 * exec_builtin - exit of the program and clean the memory
 * @command: the argument command
 * @exit_status: the status to return the functions
 * @path: the path of the command
 * @buffer: the string contain the command
 * Return: True or false
 */

int exec_builtin(char **command, char *path, char *buffer, int *exit_status)
{
int i = 0;
op_t options[] = {
{"exit", exit_func}, {"env", env_func}, {"cd", cd_func}, {NULL, NULL}
};

(void)path;
(void)buffer;
while (options[i].cmd != NULL)
{
if ((_strcmp(command[0], options[i].cmd)) == 0)
{
return (options[i].func(command, exit_status));
}
i++;
}
return (FALSE);
}

/**
 * exit_func - function to exit
 * @command: the argument command
 * @exit_status: the status to return the functions
 * Return: minus 2
 */

int exit_func(char **command, int *exit_status)
{
if (command[1] == NULL)
*exit_status = EXIT_SUCCESS;
if (is_a_number(command[1]) == TRUE)
*exit_status = string_to_int(command[1]);
return (-2);
}

/**
 * env_func - print the enviroment variables
 * @command: the argument command
 * @exit_status: the status to return the functions
 * Return: True or false
 */

int env_func(char **command, int *exit_status)
{
int i = 0;

(void)command;
while (environ[i] != NULL)
{
print_string(environ[i]);
write(1, "\n", 1);
i++;
}
*exit_status = 0;
return (TRUE);
}

/**
 * cd_func - change the actual directory
 * @command: the argument command
 * @exit_status: the status to return the functions
 * Return: True or false
 */

int cd_func(char **command, int *exit_status)
{
char *home = NULL;

if (command[1] == NULL)
{
home = obtain_home();
if (chdir(home) == -1)
{
*exit_status = 0;
perror("error");
}
free(home);
}
else if (chdir(command[1]) == -1)
perror("error");
return (TRUE);
}
