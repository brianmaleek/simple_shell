/*basic execute*/

#include "shell.h"

/**
 * execute - create a new execute process
 * @args: commands
 *
 * Return: 1 or 0
*/

int execute(char **args)
{
	pid_t process_id;
	int check;

	process_id = fork();

	if (process_id == 0)
	{
		/*start child process*/
		if (execvp(args[0], args) == -1)
		{
			perror("error");
		}
		exit(EXIT_FAILURE);
	}
	else if (process_id < 0)
	{
		perror("error: forking");
	}
	else
	{
		/*start parent*/
		while (!WIFEXITED(check) && !WIFSIGNALED(check))
		{
			waitpid(process_id, &check, WUNTRACED);
		}
	}
	return (-1);
}
