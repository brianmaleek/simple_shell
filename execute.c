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
	/*get program name*/

	if (process_id == 0)
	{
		/*start child process*/
		if (execvp(args[0], args) == -1)
		{
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, args[0], _strlen(args[0]));
			write(STDERR_FILENO, ": not found\n", 12);

		}
		exit(EXIT_FAILURE);
	}
	else if (process_id < 0)
	{
		perror("error: forking");
	}
	else
	{
		do {
		/*start parent*/
			waitpid(process_id, &check, WUNTRACED);
		} while (!WIFEXITED(check) && !WIFSIGNALED(check));
	}
	return (-1);
}
