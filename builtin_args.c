#include "shell.h"

/**
 * exec_cd - change directory
 * @args: arguments
 *
 * Return: 1 on success, 0 on failure
 */

int exec_cd(char **args)
{
	if (args[1] == NULL)
	{
		perror("hsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("error in exec_cd.c: change directory failed\n");
		}
	}
	return (-1);
}

/**
 * exec_env - display environment variables
 * @args: arguments
 *
 * Return: 1 on success, 0 on failure
 */

int exec_env(char **args)
{
	int position = 0;

	(void) (**args);

	while (environ[position])
	{
		write(STDOUT_FILENO, environ[position], _strlen(environ[position]));
		write(STDOUT_FILENO, "\n", 1);
		position++;
	}
	return (-1);
}

/**
 * exec_exit - exit shell
 * @args: arguments
 *
 * Return: 1 on success, 0 on failure
 */

int exec_exit(char **args)
{
	(void) (**args);
	if (args[1] == NULL)
	{
		return (0);
	}
	else
	{
		return (_atoi(args[1]));
	}
}

/**
 * exec_help - display help
 * @args: arguments
 *
 * Return: 1 on success, 0 on failure
 */

int exec_help(char **args)
{
	char *argument_str[] = {
		"cd",
		"help",
		"exit",
		"env"
	};
	unsigned long int i;
	(void) (**args);

	_puts("help: \n");

	for (i = 0; i < sizeof(argument_str) / sizeof(char *); i++)
	{
		_puts(argument_str[i]);
		_puts("\n");
	}
	return (-1);
}

