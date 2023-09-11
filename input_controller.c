#include "main.h"
/**
* input_controller - function that takes user input and handles commands
* @input: user input string to be processed
* @argv : An array of pointers to the command-line arguments
*/
void input_controller(char **input, char *argv)
{
	char **params, **tags;
	int i, j;
	int status = 0;

	if (check_line_empty(*input) == 1)
		return;
	for (i = 0; input[i] ; i++)
		;
	params = separate_params(*input);
	for (i = 0; params[i] != NULL; i++)
		;
	tags = malloc(sizeof(char *) * i);
	if (tags == NULL)
	{
		for (i = 0; params[i] != NULL; i++)
			free(params[i]);
		free(params);
		return;
	}
	for (j = 0; j < i - 1 ; j++)
	{
		tags[j] = malloc(str_len(params[j + 1]) + 1);
		str_cpy(tags[j], params[j + 1]);
	}
	tags[j] = NULL;
	handle_command(params[0], tags, argv, &status);
	if (str_cmp(params[0], "exit") == 0)
	{
		free_double_pointer(params, i);
		free_double_pointer(tags, i - 1);
		free(*input);
		exit(status);
	}
	free_double_pointer(params, i);
	free_double_pointer(tags, i - 1);
}
/**
 * separate_params - function that retrieves all the params from the input
 * @input: user input
 * Return: char double array of params
*/
char **separate_params(char *input)
{
	char **tokens, *one_param, *token;
	int i = 0;
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
	tokenize(one_param, i, tokens);
	free(temp_input);
	return (tokens);
}
/**
 * handle_command - function that processes the command based on the given path
 * @path: The path containing the command to be processed.
 * @params: the params excluding the command
 * @argv : An array of pointers to the command-line arguments
 * @status : status of the code
*/
void handle_command(char *path, char **params, char *argv, int *status)
{
	char *get_command, *command, *full_path, *temp_path;

	if (str_cmp(path, "exit") == 0)
	{
		*status = exit_shell(params, argv);
		return;
	}
	if (str_cmp(path, "cd") == 0)
	{
		change_dir(params, argv);
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
			*status = 127;
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
/**
 * free_double_pointer - Frees memory allocated for
 *				a double pointer and its content.
 * @ptr: The double pointer to be freed.
 * @length: The length of the array of pointers.
 */
void free_double_pointer(char **ptr, int length)
{
	int j;

	for (j = 0; j < length; j++)
		free(ptr[j]);
	free(ptr);
}
