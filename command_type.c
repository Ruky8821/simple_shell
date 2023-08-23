#include "main.h"
#include <string.h>
#include <errno.h>
/**
* command_type - process the command type
* @token: command symbole
* @path : pointer to full path of the command executable
* @params: an array
* Return: int
*/
void command_type(char *token, const char *path, char **params)
{
	int i;
	pid_t pid = fork();
	char **env = environ, **args;


	if (pid == -1)
	{
		perror("fork error");
		return;
	}
	for (i = 0; params[i] ; i++)
		;
	if (pid == 0)
	{
		args = malloc(sizeof(char *) * (i + 2));
		copy_non_space_strings(args, params, token);
		execve(path, args, env);
		perror("execve error");
		exit(1);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}
