#include "main.h"
#include <errno.h>
/**
* input_controller - function that takes user input and handles commands
* @input: user input string to be processed
* @argv: The name of the executable.
*/
void input_controller(char *input, char *argv)
{
	char **tokens;
	char *token;
	int i, j;

	for (i = 0; input[i]; i++)
		++i;
	if (i > 1 && input[0] == '\n')
		return;
	    tokens = malloc(sizeof(char *) * (i + 1));
	if (tokens == NULL)
		return;
	token = strtok(input, " ");
	i = 0;
	while (token != NULL)
	{
		tokens[i] = malloc(str_len(token) + 1);
		if (tokens[i] == NULL)
		{
			for (j = 0; j < i ; j++)
				free(tokens[j]);
			free(tokens);
			return;
		}
		for (j = 0; token[j] != '\0' ; j++)
		{
			if (token[j] == '\n')
				continue;
			tokens[i][j] = token[j];
		}

		tokens[i][j] = '\0';
		token = strtok(NULL, " ");
		i++;
	}
	tokens[i] = NULL;
	handle_command(tokens[0], argv);
	for (j = 0; j < i; j++)
		free(tokens[j]);
	free(tokens);
}
/**
 * handle_command - function that processes the command based on the given path
 * @path: The path containing the command to be processed.
 * @argv: The name of the executable.
*/

void handle_command(char *path, char *argv)
{
	char *get_command, *command;
	char *temp_path = (char *)malloc(strlen(path) + 1);

	str_cpy(temp_path, path);
	if (access(path, F_OK) == 0)
	{
		get_command = strtok(path, "/");
		while (get_command != NULL)
		{
			command = get_command;
			get_command = strtok(NULL, "/");
		}
		command_type(command, temp_path);
}
	else
		printf("%s: No such file or directory\n", argv);

}



