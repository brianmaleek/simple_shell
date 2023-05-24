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
		if (execve(args[0], args, environ) == -1)
		{
			char command_path[BUFSIZE];
			char *path_token;
			char *path = getenv("PATH");

			_strcpy(command_path, args[0]);

			path_token = strtok(path, ":");

			while (path_token)
			{
				_strcpy(command_path, path_token);
				_strcat(command_path, "/");
				_strcat(command_path, args[0]);
				if (access(command_path, F_OK) == 0)
				{
					if (execve(command_path, args, environ) == -1)
					{
						perror("execve error");
					}
					exit(EXIT_FAILURE);
				}
				path_token = strtok(NULL, ":");
			}
			path_token = strtok(NULL, ":");
		}
		perror("execve error");
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
			if (waitpid(process_id, &check, WUNTRACED) == -1)
			{
				perror("error: waitpid");
				return (-1);
			}
			else
			{
				waitpid(process_id, &check, WUNTRACED);
			}
		} while (!WIFEXITED(check) && !WIFSIGNALED(check));
	}
	return (-1);
}
