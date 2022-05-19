#include "shell.h"


/**
 * main - entry point
 * Return: 1 or 0 if is succesfull or failed
 */

int main(void)
{
char *buffer = NULL, **command = NULL, *path = NULL;
int fd = 0, tty = FALSE, exit_code = 0, flag, status = 1;
int *exit_status = &exit_code;
struct stat st;

signal(SIGINT, sig_handler);
while (status)
{
if (isatty(fd) == TRUE)
write(STDIN_FILENO, "$ ", 2);
buffer = read_command();
if (buffer == NULL || buffer[0] == '\n')
continue;
command = split_command(buffer);
if (command[0] == NULL)
{
free(buffer);
free(command);
continue;
}
if (is_builtin(command[0]) == FALSE)
{
if (stat(command[0], &st) == 0)
flag = TRUE;
else
{
path = split_path(command[0]);
flag = FALSE;
}
status = exc_argument(command, path, buffer, tty, flag);
}
else
{
status = exec_builtin(command, path, buffer, exit_status);
clean_memory(command, path, buffer, TRUE);
if (status == -2)
break;
}
}
return (exit_code);
}

/**
 * sig_handler - catch the ctrl + c
 * @sig: the number of the signal
 */

void sig_handler(int sig)
{
(void)sig;
signal(SIGINT, sig_handler);
write(STDIN_FILENO, "\n$ ", 3);
}
