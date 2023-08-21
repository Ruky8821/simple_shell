#include "main.h"
#include <string.h>
/**
* command_type - process the command type
* @token: command symbole
* @path : pointer to full path of the command executable
* @params: an array
* Return: int
*/
void command_type(char *token, const char *path, char **params)
{
	int i, length = 0;
	pid_t pid = fork();
	char **env = environ, **argv;

	if (pid == -1)
	{
		perror("fork error");
		return;
	}
	for (i = 0; params[i] ; i++)
		length++;
	if (pid == 0)
	{
		argv = malloc(sizeof(char *) * (length + 2));
		copy_non_space_strings(argv, params, token);
		execve(path, argv, env);
		perror("execve error");
		exit(1);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}
