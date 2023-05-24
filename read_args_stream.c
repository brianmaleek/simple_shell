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
			input_line = reallocate_buffer(input_line, sizeof(char) * bufsize);
		}
		if (is_end_of_input(input_line, position))
		{
			return (finalize_input(input_line, position));
		}
	}
	free(input_line);
	exit(EXIT_SUCCESS);
}

/**
 * reallocate_buffer - handles reallocation of buffer
 * @buffer: pointer to current input buffer to be reallocated
 * @new_size: integer representing new size for the buffer
 * Return: new buffer
*/
char *reallocate_buffer(char *buffer, int new_size)
{
	char *new_buffer = realloc(buffer, sizeof(char) * new_size);

	if (new_buffer == NULL)
	{
		perror("error in read_args_stream.c: realloc failed\n");
		exit(EXIT_FAILURE);
	}
	return (new_buffer);
}

/**
 * is_end_of_input - checks if last character read is newline
 * @input: character array representing input buffer
 * @position: Integer indicating current position in input buffer
 * Return: position
*/
int is_end_of_input(const char *input, int position)
{
	return (input[position - 1] == '\n');
}

/**
 * finalize_input - replace newline with null byte
 * @input: character array representing input buffer
 * @position: Integer indicating current position in input buffer
 * Return: input
*/
char *finalize_input(char *input, int position)
{
	input[position - 1] = '\0';
	return (input);
}
