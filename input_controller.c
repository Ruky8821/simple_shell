#include "main.h"
#include <errno.h>
/**
* input_controller - function that takes user input and handles commands
* @input: user input string to be processed
* @argv: The name of the executable.
*/
void input_controller(char *input, char *argv)
{
	char **tokens, *token, *cmd;
	int i, j;

	for (i = 0; input[i]; i++)
		++i;
	if (i > 1 && input[0] == '\n')
		return;
	if (str_cmp(input, "exit") == 10)
		exit(0);
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
	cmd = malloc(sizeof(char) * (str_len(tokens[0]) + 1));
	for (j = 0; tokens[0][j] != '\0' ; j++)
		cmd[j] = tokens[0][j];
	for (j = 0; j < i - 1; j++)
		tokens[j] = tokens[j + 1];
	tokens[j] = '\0';
	handle_command(cmd, argv, tokens);
	for (j = 0; j < i; j++)
		free(tokens[j]);
	 free(tokens);
}



/**
 * handle_command - function that processes the command based on the given path
 * @path: The path containing the command to be processed.
 * @argv: The name of the executable.
*/

void handle_command(char *path, char *argv, char **params)
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
		command_type(command, temp_path, params);
}
	else
		printf("%s: No such file or directory\n", argv);

}

