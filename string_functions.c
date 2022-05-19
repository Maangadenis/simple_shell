#include "shell.h"


/**
 * _strlen - count the leng of s
 * @s: pointer received
 * Return: the lenght of the character received
 */

int _strlen(char *s)
{
int i = 0;

while (*(s + i) != 0)
i++;
return (i);
}

/**
 * _strcmp - compair 2 strings
 * @s1: the first string
 * @s2: second string
 * Return: a number
 */

int _strcmp(char *s1, char *s2)
{
if (s1 == NULL || s2 == NULL)
return (-1);
while ((*s1 == *s2)  && (*s1 != '\0'))
{
s1++;
s2++;
}
return (*s1 - *s2);
}
/**
 * print_string - print a string
 * @string: the string
 * Return: nothing
 */

void print_string(char *string)
{
int i = 0, count = 0;
char *buffer;

count = _strlen(string);
buffer = (char *)malloc(sizeof(char) * count + 2);
while (i < count)
{
buffer[i] = string[i];
i++;
}
buffer[i] = '\0';
write(1, buffer, count);
free(buffer);
}

/**
 * _strcat - function that append the contain in src in the buffer of dest
 * @dest: the destination to append
 * @src: the text to copy
 * Return: a char pointer
 */

char *_strcat(char *dest, char *src)
{
int i = 0;
int x = 0;

while (dest[i] != '\0')
{
i++;
}
while (src[x] != '\0')
{
dest[i] = src[x];
x++;
i++;
}
dest[i] = '\0';
return (dest);
}
