#include "main.h"
#include <errno.h>
/**
* input_controller - function that takes user input and handles commands
* @input: user input string to be processed
* @argv: The name of the executable.
*/
void input_controller(char *input, char *argv)
{
	char **params, *cmd;
	int i, j;

	for (i = 0; input[i]; i++)
		++i;
	if (i > 1 && input[0] == '\n')
		return;
	if (str_cmp(input, "exit") == 10)
		exit(0);
	params = separate_params(input, i);
	cmd = malloc(sizeof(char) * (str_len(params[0]) + 1));
	str_cpy(cmd, params[0]);
	for (j = 0; j < i - 1; j++)
		params[j] = params[j + 1];
	params[j] = '\0';
	handle_command(cmd, argv, params);
	for (j = 0; j < i; j++)
		free(params[j]);
	free(params);
}
/**
 * separate_params - function that retrieves all the params from the input
 * @input: user input
 * @length: the length of the user string input
 * Return: char double array of params
*/
char **separate_params(char *input, int length)
{
	char **tokens, *one_param;
	int i, j;

	tokens = malloc(sizeof(char *) * (length + 1));
	if (tokens == NULL)
		return (NULL);
	one_param = strtok(input, " ");
	i = 0;
	while (one_param != NULL)
	{
		tokens[i] = malloc(str_len(one_param) + 1);
		if (tokens[i] == NULL)
		{
			for (j = 0; j < i ; j++)
				free(tokens[j]);
			free(tokens);
			return (NULL);
		}
		for (j = 0; one_param[j] != '\0' && one_param[j] != '\n' ; j++)
			tokens[i][j] = one_param[j];
		tokens[i][j] = '\0';
		one_param = strtok(NULL, " ");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}



/**
 * handle_command - function that processes the command based on the given path
 * @path: The path containing the command to be processed.
 * @argv: The name of the executable.
 * @params: the params excluding the command
*/

void handle_command(char *path, char *argv, char **params)
{
	char *get_command, *command;
	char *temp_path = (char *)malloc(strlen(path) + 1);

	str_cpy(temp_path, path);
	if (str_cmp(path, "cd") == 0)
	{
		change_dir(params);
		return;
	}
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

