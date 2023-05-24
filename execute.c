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
		if (execve(args[0], args, environ) == -1)/*start child process*/
		{
			char command_path[BUFSIZE], *path_token = strtok(getenv("PATH"), ":");

			while (path_token)
			{
				_strcpy(command_path, path_token);
				_strcat(path_token, '/');
				_strcat(path_token, args[0]);
				if (access(command_path, F_OK) == 0
					&& execve(command_path, args, environ) != -1)
					exit(EXIT_SUCCESS);
				path_token = strtok(NULL, ":");
			}
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
			waitpid(process_id, &check, WUNTRACED);
		} while (!WIFEXITED(check) && !WIFSIGNALED(check));
	}
	return (-1);
}
