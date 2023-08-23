#include "main.h"
#include <errno.h>
/**
* input_controller - function that takes user input and handles commands
* @input: user input string to be processed
*/
void input_controller(char *input)
{
	char **params, *cmd;
	int i, j;

	if (check_line_empty(input) == 1)
		return;
	for (i = 0; input[i] ; i++)
		;
	params = separate_params(input, i - 1);
	cmd = malloc(sizeof(char) * (str_len(params[0]) + 1));
	if (cmd == NULL)
	{
		free(params);
		return;
	}
	str_cpy(cmd, params[0]);
	for (j = 0 ; j < i - 1 ; j++)
		params[j] = params[j + 1];
	params[j - 1] = NULL;
	handle_command(cmd, params);
	for (j = 0; j < i; j++)
		free(params[j]);
	free(params);
	free(cmd);
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
	for (i = 0; i <= length; i++)
		tokens[i] = NULL;
	one_param = strtok(input, " \t");
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
 * @params: the params excluding the command
*/
void handle_command(char *path, char **params)
{
	char *get_command, *command, *full_path;
	char *temp_path = NULL;

	if (str_cmp(path, "exit") == 0)
		exit(0);
	if (str_cmp(path, "cd") == 0)
	{
		change_dir(params);
		return;
	}
	if (path[0] != '/')
	{
		full_path =  get_path(path);
		if (full_path == NULL)
		{
			free(full_path);
			perror("command not found");
			return;
		}
			command_type(path, full_path, params);
		free(full_path);
		return;
	}
	temp_path = (char *)malloc(strlen(path) + 1);
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
	free(temp_path);
}
