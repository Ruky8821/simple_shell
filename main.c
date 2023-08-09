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
	char *line, *token, *first_token, *second_token;
	ssize_t  gerror;
	size_t size = 0;
	int count;

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
		token = strtok(line, "/");
		count = 0;
		while (token != NULL)
		{
			if (count == 0)
				first_token = token;
			else if (count == 1)
				second_token = token;
			count++;
			token = strtok(NULL, "/");
		}
	if (count == 1 || count > 2)
		printf("%s: No such file or directory\n", argv[0]);
	if (count == 2 && str_cmp(first_token, "bin") == 0)
		command_type(second_token);
	free(line);
	}
	return (0);
}
