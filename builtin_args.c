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
	int position, j;
	(void) (**args);

	for (position = 0; environ[position] != NULL; position++)
	{
		char *env_var = environ[position];

		for (j = 0; env_var[j] != '\0'; j++)
		{
			write(STDOUT_FILENO, &env_var[j], 1);
		}
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
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

