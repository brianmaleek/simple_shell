#include "shell.h"
/**
 * _putchar - 
 * @c:character to output
 *
 * Return: On success 1/ on error 0
 *
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - function to print string
 * @str : string to print
*/

void _puts(char *str)
{
	int c = 0;
	while (str[c])
	{
		_putchar(str[c]);
		c++;
	}
}
