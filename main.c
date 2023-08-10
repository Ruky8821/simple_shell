#include <string.h>
#include "main.h"
/**
* main - Entry point to the program
* @argc : The number of command-line arguments
* @argv : An array of pointers to the command-line arguments
* Return: 0 (Success)
*/
int main(int argc, char *argv[])
{
	char *line;
	ssize_t  gerror;
	size_t size = 0;

	(void)argc;
	while (1)
	{
		line = NULL;
		write(1, "$ ", 2);
		gerror = getline(&line, &size, stdin);
		if (gerror == -1)
		{
			free(line);
			exit(0);
		}
		input_controller(line, argv[0]);
		free(line);
	}
	return (0);
}
