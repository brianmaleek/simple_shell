/* to execute built in functions*/
#include "shell.h"
/**
 * builtin_args_exec - function to execute builtin args
 * @args: arguments
 *
 * Return: 1 or 0
*/

int builtin_args_exec(char **args)
{
	char *argument_list[] = {
		"cd",
		"env",
		"exit",
		"help"
	};

	int (*argument_funcs[])(char **) = {
		&exec_cd,
		&exec_env,
		&exec_exit,
		&exec_help
	};

	unsigned long int position = 0;

	/*check if there is a command*/
	if (args[0] == NULL)
	{
		return (1);
	}
	for (; position < sizeof(argument_list) / sizeof(char *); position++)
	{
		if (_strcmp(args[0], argument_list[position]) == 0)
		{
			return ((*argument_funcs[position])(args));
		}
	}
	return (execute(args));
}
