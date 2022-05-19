#include "shell.h"

/**
 *check1 - checking
 *@command: command
 *@path: path
 *@buffer: buffer
 *@tty: tty
 *@flag: flag
 */
void check1(char **command, char *path, char *buffer, int tty, int flag)
{
(void) tty;

if (command[0][0] == '/')
{
print_string("-hsh: /: is a directory\n");
clean_memory(command, path, buffer, flag);
exit(126);
}
else
{
print_string(command[0]);
print_string(": command not found\n");
clean_memory(command, path, buffer, flag);
exit(127);
}
}

/**
 *check2 - checking
 *@command: command
 *@path: path
 *@buffer: buffer
 *@tty: tty
 *@flag: flag
 */
void check2(char **command, char *path, char *buffer, int tty, int flag)
{
(void) tty;

if (command[0][0] == '/')
{
print_string("-hsh: /: is a directory\n");
clean_memory(command, path, buffer, flag);
exit(126);
}
else
{
print_string(command[0]);
print_string(": command not found\n");
clean_memory(command, path, buffer, flag);
exit(127);
}
}
