#include "shell.h"


/**
 * is_a_number - if a string is a number return True else false
 * @buffer: the string
 * Return: if a string is a number return True else false
 */

int is_a_number(char *buffer)
{
int i = 0, count = 0;

if (buffer == NULL)
return (FALSE);
count = _strlen(buffer);
for (i = 0; i < count; i++)
{
if (buffer[i] >= 48 && buffer[i] <= 57)
continue;
else
break;
}
if (i != count)
return (FALSE);
else
return (TRUE);
}

/**
 * string_to_int - convert a string number in int
 * @buffer: the string number
 * Return: the number
 */

int string_to_int(char *buffer)
{
int i = 0, count = 0, pow = 1, tot = 0;

count = _strlen(buffer);
for (i = 0; i < count - 1; i++)
pow *= 10;
while (*buffer != '\0')
{
tot += (buffer[0] - 48) * pow;
buffer++;
pow /= 10;
}
return (tot);
}
