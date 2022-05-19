#include "shell.h"


#define TOKEN_BUFFSIZE 256
#define TOKEN_DELIM " \t\r\n\a"

/**
 * read_command - read the command enter
 * Return: the command
 */

char *read_command(void)
{
char *buffer;
size_t buffsize = BUFFSIZE;
int c;

buffer = (char *)malloc(buffsize * sizeof(char));
if (buffer == NULL)
{
perror("Unable to allocate buffer");
exit(EXIT_FAILURE);
}
c = getline(&buffer, &buffsize, stdin);
if (c == -1)
{
if (c == EOF)
{
free(buffer);
exit(0);
}
perror("An error ocurred");
}
return (buffer);
}

/**
 * split_command - split the command with the differents arguments
 * @buffer: the command
 * Return: an array with the command and parameters
 */

char **split_command(char *buffer)
{
int position = 0, buffsize = TOKEN_BUFFSIZE;
char **tokens, *token;

tokens = malloc(buffsize * sizeof(char *));
if (tokens == NULL)
{
perror("Unable to allocate\n");
exit(EXIT_FAILURE);
}
while (buffer[0] == 32)
{
buffer++;
}
if (buffer[0] == '\0')
{
free(buffer);
return (NULL);
}
token = strtok(buffer, TOKEN_DELIM);
while (token != NULL)
{
tokens[position++] = token;
token = strtok(NULL, TOKEN_DELIM);
}
tokens[position] = NULL;
return (tokens);
}

/**
 * exc_argument - excecute a command
 * @command: the command with parameters
 * @path: the path of the command
 * @buffer: the string of the command with the parameters
 * @tty: flag if is tty or not
 * @flag: flag
 * Return: 1 or 0 if the command fail or is succesfull
 */

int exc_argument(char **command, char *path, char *buffer, int tty, int flag)
{
pid_t pid;
int status, outstatus = 0;

(void)outstatus;
pid = fork();
if (pid < 0)
perror("Error");
if (pid == 0)
{
if (flag == TRUE)
{
if (execve(command[0], command, environ) == -1)
{
check1(command, path, buffer, tty, flag);
}
}
else
{
if (execve(path, command, environ) == -1)
{
check2(command, path, buffer, tty, flag);
}
}
}
else
{
wait(&status);
if (WIFEXITED(status))
outstatus = WEXITSTATUS(status);
}
if (tty == TRUE)
return (0);
clean_memory(command, path, buffer, flag);
return (1);
}

/**
 * is_builtin - function that compare if the command is a builtin command
 * @token: the command
 * Return: True(1) or false(0)
 */

int is_builtin(char *token)
{
int i = 0;
op_t options[] = {
{"exit", exit_func}, {"env", env_func}, {"cd", cd_func}, {NULL, NULL}
};

while (options[i].cmd != NULL)
{
if ((_strcmp(token, options[i].cmd)) == 0)
{
return (TRUE);
}
i++;
}
return (FALSE);
}
