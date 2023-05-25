#include "shell.h"

/**
 * read_args_stream - read args from stream
 * Return: pointer to input line
 */
char *read_args_stream(void)
{
	char *input_line = malloc(sizeof(char) * BUFSIZE);
	ssize_t bytes_read = 0;
	int position = 0;
	int bufsize = BUFSIZE;

	if (input_line == NULL)
	{
		perror("error in read_args_stream.c: malloc failed\n");
		return (NULL);
	}
	while (1)
	{
		char *buffer = input_line + position;
		size_t remaining_size = bufsize - position;

		bytes_read = read_input(buffer, remaining_size);

		if (bytes_read == -1)
		{
			perror("error reading stdin");
			exit(EXIT_FAILURE);
		}
		else if (bytes_read == 0) /* EOF*/
		{
			break;
		}
		position += bytes_read;

		if (position >= bufsize - 1)
		{
			bufsize += bufsize;
			input_line = realloc(input_line, sizeof(char) * bufsize);
			if (input_line == NULL)
			{
				perror("error in read_args_stream.c: realloc failed\n");
				exit(EXIT_FAILURE);
			}
		}
		if (input_line[position - 1] == '\n')
		{
			input_line[position - 1] = '\0';
			return (input_line);
		}
	}
	free(input_line);
	exit(EXIT_SUCCESS);
}
