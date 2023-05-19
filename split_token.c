#include "shell.h"

/**
 * split_to_tokens - split input to tokens
 * @token: input to split
 * Return: pointer to array of tokens
 */

char **split_to_tokens(char *tok)
{
	int buffersize = TOK_BUFSIZE;
	int position = 0;
	char **tokens = malloc(buffersize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		_puts("allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(tok, DELIMITER);
	do
	{
		if (token[0] == '#')
		{
			break;
		}

		tokens[position] = token;
		position++;

		if (position >= buffersize)
		{
			buffersize += TOK_BUFSIZE;
			tokens = realloc(tokens, buffersize * sizeof(char *));
			if (!tokens)
			{
				_puts("allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIMITER);
	} while (token != NULL);

	tokens[position] = NULL;
	return (tokens);
}
