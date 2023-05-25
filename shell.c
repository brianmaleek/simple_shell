#include "shell.h"
/**
 * terminal_Interactive - interactive mode
 * @Description -  function to run the shell in interactive mode
 * return: void
*/

void terminal_Interactive(void)
{
	char *input, *com;
	char **line_args;
	int check = -1;


	do {
		_puts("$: ");
		input = read_args();
		line_args = split_to_tokens(input);
		check = builtin_args_exec(line_args);
		/*manage memory*/
		free(input);
		free(line_args);

		if (check >= 0)
			exit(check);
	} while (check == -1);

}

/**
 * terminal_non_interactive - non interactive mode
 * @description - function to run the shell in non interactive mode
 * return: void
*/
void terminal_non_interactive(void)
{
	char *input;
	char **line_args;
	int check = -1;

	while (check == -1)
	{
		input = read_args_stream();
		line_args = split_to_tokens(input);
		check = builtin_args_exec(line_args);
		/*manage memory*/
		free(input);
		free(line_args);

		if (check >= 0)
			exit(check);
	}
}

/**
 * main - entry point
 * Return: 0 on success
*/
int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
		terminal_Interactive();
	else
		terminal_non_interactive();
	return (0);
}
