#include "main.h"
#include <string.h>
/**
* command_type - process the command type
* @token: command symbole
* @path : pointer to full path of the command executable
* Return: int
*/
void command_type(char *token, const char *path, char **params)
{
	int i,j, length = 0;
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork error");
        return;
    }
    for (i = 0; params[i]; i++)
	    length ++;
    if (pid == 0) {
	    char **argv = malloc(sizeof(char *) * (length + 2));
	    argv[0] = token;
	    for (i = 0; params[i] != NULL; i++)
	    {
		                argv[i + 1] = malloc(str_len(params[i]) + 1); 
		for (j = 0; params[i][j]; j++)
		{

		    argv[i + 1][j] = params[i][j];
		}
		argv[i + 1][j] = '\0';
	    } 

	    argv[i+1] = NULL;
   execve(path, argv, NULL);
        perror("execve error");
        exit(1);
    } else {
        int status;
        waitpid(pid, &status, 0);

    }
}
