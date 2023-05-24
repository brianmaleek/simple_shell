#include "shell.h"

/**
 * read_input - read input from stdin
 * @buffer: buffer to store input
 * @size: size of buffer
 * Return: number of bytes read
*/
ssize_t read_input(char *buffer, size_t size)
{
	return (read(STDIN_FILENO, buffer, size));
}

/**
 * _strcpy - copies string pointed to by src
 * @dest: destination string
 * @src: source string
 * Return: pointer to destination string
*/
char *_strcpy(char *dest, const char *src)
{
	char *ptr = dest;

	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (dest);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination input value
 * @src: source input value
 * Return: pointer to the resulting string dest
*/
char *_strcat(char *dest, const char *src)
{
char *ptr = dest;

	while (*ptr)
	{
		ptr++;
	}
	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (dest);
}


/**
 * _getenv- get environment variables
 * @name: the variable
 *
 * Return: Env
*/

char *_getenv(char *name)
{
	size_t name_len = _strlen(name);
	char **env = __environ;
	for(; *env != NULL; env++)
	{
		if(_strcmp(*env, name) == 0
			&& (*env[name_len] == '='))
		{
			return &(*env)[name_len + 1];
		}
	}
	return (NULL);
	
}