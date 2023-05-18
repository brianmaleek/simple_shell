#include "shell.h"

/*interactive terminal*/

/**
 * terminal_interg
*/

void terminal_interative(void)
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





