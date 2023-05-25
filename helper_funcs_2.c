#include "shell.h"

/**
 * read_input - reads input from stdin
 * @buffer: buffer to store input
 * @size: size of buffer
 * Return: number of characters read
 */
ssize_t read_input(char *buffer, size_t size)
{
	return (read(STDIN_FILENO, buffer, size));
}
