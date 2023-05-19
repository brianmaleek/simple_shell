#include "shell.h"
/**
 * _putchar - function to print character
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
 * _puts - function that prints a string, followed by a new line, to stdout
 * @str: string to print
 * Return: length of string
 */

void _puts(char *str)
{
	while (*str != '\0')
		_putchar(*str++);

	_putchar('\n');
}

/**
 * _strlen - function to print length of string
 * @str : string to print
 * Return: length of string
*/
size_t _strlen(char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}

/**
 * _atoi - converts a string to integer
 * @s: string to be converted
 * Return: returns integer value of the converted string.
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int num = 0;

	do {
		if (*s == '-')
			sign *= -1;

		else if (*s >= '0' && *s <= '9')
			num = (num * 10) + (*s - '0');

		else if (num > 0)
			break;

	} while (*s++);

	return (num * sign);
}
