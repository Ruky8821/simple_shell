#include "main.h"
/**
* input_controller - function that takes user input and handles commands
* @input: user input string to be processed
* @argv : An array of pointers to the command-line arguments
*/
void input_controller(char *input, char *argv)
{
	char **params, **tags;
	int i, j;

	if (check_line_empty(input) == 1)
		return;
	for (i = 0; input[i] ; i++)
		;
	params = separate_params(input);
	for (i = 0; params[i] != NULL; i++)
		;
	tags = malloc(sizeof(char *) * i);
	if (tags == NULL)
	{
		for (int i = 0; params[i] != NULL; i++)
			free(params[i]);
		free(params);
		return;
	}
	for (j = 0; j < i - 1 ; j++)
	{
		tags[j] = malloc(strlen(params[j + 1]) + 1);
		str_cpy(tags[j], params[j + 1]);
	}
	tags[j] = NULL;
	handle_command(params[0], tags, argv);
	for (j = 0; j < i; j++)
		free(params[j]);
	free(params);
	for (j = 0; j < i - 1; j++)
		free(tags[j]);
	free(tags);
}
/**
 * separate_params - function that retrieves all the params from the input
 * @input: user input
 * Return: char double array of params
*/
char **separate_params(char *input)
{
	char **tokens, *one_param, *token;
	int i = 0, j;
	char *temp_input = malloc(sizeof(char) * (str_len(input)));

	if (temp_input == NULL)
		return (NULL);
	strtok(input, "\n");
	str_cpy(temp_input, input);
	token = strtok(temp_input, " ");
	while (token != NULL)
	{
		i++;
		token = strtok(NULL, " ");
	}
	tokens = (char **) malloc(sizeof(char *) * (i + 1));
	if (tokens == NULL)
	{
		free(temp_input);
		return (NULL);
	}
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
			free(temp_input);
			return (NULL);
		}
		str_cpy(tokens[i], one_param);
		one_param = strtok(NULL, " \t");
		i++;
	}
	tokens[i] = NULL;
	free(temp_input);
	return (tokens);
}
/**
 * handle_command - function that processes the command based on the given path
 * @path: The path containing the command to be processed.
 * @params: the params excluding the command
 * * @argv : An array of pointers to the command-line arguments
*/
void handle_command(char *path, char **params, char *argv)
{
	char *get_command, *command, *full_path;
	char *temp_path = NULL;

	if (str_cmp(path, "exit") == 0)
		exit_shell(params, argv);
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
			print_error("1: ", argv);
			write(STDERR_FILENO, path, str_len(path));
			write(STDERR_FILENO, ": not found\n", 12);
			free(full_path);
			exit(127);
		}
			command_type(path, full_path, params);
		free(full_path);
		return;
	}
	temp_path = (char *)malloc(str_len(path) + 1);
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
