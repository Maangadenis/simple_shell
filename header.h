#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

/* -------- Prototypes -------- */

/* simple_shell.c */
int execute(char *command, char **arguments, char *av);
int shell(char *, char **, int, char **, char **, int *);
void not_found(int lines, char *split, char **av);
char *line_maker(size_t size);

/* str_handlers */
int _strlen(char *str);
char *_strdup(char *str);
char **split_line(char *str, char *delim);
int _strcmp(char *origin, char *comp);
char *numbertostring(int n);

/* path_handler.c */
char *getenviroment(char *name, char **environ);
char *getpath(char **environ, char *input);

/* memory_handler.c */
int arraycleaner(char **str);


#endif /* ifndef NARITA_H */
