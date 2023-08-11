#include "main.h"
#include <string.h>
/**
* command_type - process the command type
* @token: command symbole
* @path : pointer to full path of the command executable
* Return: int
*/
void command_type(const char *token, const char *path)
{
	char *const argv[] = {"ls", NULL};

	if (execve(path, argv, NULL) == -1)
		perror("execve error");
}
