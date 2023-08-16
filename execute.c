#include "main.h"
/**
 * execute - executes a program
 * @argv: array of commands
 */
void execute(char **argv)
{
	char *todo = NULL;

	while (argv != NULL)
	{
		todo = argv[0];

		if (execve(todo, argv, NULL) == -1)
		{
			perror("error: exec");
			exit(EXIT_FAILURE);
		}
		argv++;
	}

}
