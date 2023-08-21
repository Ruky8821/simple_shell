#include "main.h"
/**
* main - Entry point to the program
* Return: 0 (Success)
*/
int main(void)
{
	char *line = NULL;
	ssize_t  gerror = 0;
	size_t size = 0;

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
		input_controller(line);
		free(line);

	}
	return (0);
}
