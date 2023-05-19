#include "shell.h"

/**
 * read_args_stream - read args from stream
 * Return: pointer to input
 */
char *read_args_stream(void)
{
	char *input_line = NULL;
	size_t bufsize = 0;
	ssize_t bytes_read = 0;

	bytes_read = getline(&input_line, &bufsize, stdin);
	if (bytes_read == -1)
	{
		_puts("getline error in read_stream\n");
		free(input_line);
		exit(EXIT_FAILURE);
	}
	else if (bytes_read > 0 && input_line[bytes_read - 1] == '\n')
	{
		input_line[bytes_read - 1] = '\0';
	}

	return (input_line);
}
