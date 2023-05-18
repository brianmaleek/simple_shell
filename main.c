#include "shell.h"

/*interactive terminal*/

/**
 * terminal_interg
*/

void terminal_Interactive(void)
{
	char *input;
	char **line_args;
	int check = -1;
	_puts("$: ");
	while(check == -1)
	{
		input = read_args();
		line_args = split_to_tokens();
		check = builtin_exec(line_args);
		/*manage memory*/
		free(input);
		free(line_args);

		if (check >= 0)
			exit(check);
	}
	_puts("$: ");
}

/**
 * terminal_non_interactive : non interactive mode
*/
void terminal_non_interactive(void)
{
	char *input;
	char **line_args;
	int check = -1;
	while(check == -1)
	{
		input = read_args_stream();
		line_args = split_to_tokens();
		check = builtin_exec(line_args);
		/*manage memory*/
		free(input);
		free(line_args);

		if (check >= 0)
			exit(check);

}

int main(void)
{
	if (isatty(STDIN_FILENO))
		terminal_Interactive();
	else
		terminal_non_interactive();
	return (0);
}