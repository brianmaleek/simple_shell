/*read args*/

#include "shell.h"

/**
 * read_args - read args from stream
 * Return: input line
*/

char *read_args(void)
{
	char *input_line = NULL;
	size_t bufsize = 0;
	if (getline(&input_line, &bufsize, stdin))
	{
		if(feof(stdin))
		{
			free(input_line);
			exit(EXIT_SUCCESS);
		}
		else{
			free(input_line);
			perror("error reading stdin");
			exit(EXIT_FAILURE);
		}
	}
	return(input_line);
}