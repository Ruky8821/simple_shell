#include "main.h"
/**
 * change_dir-function that changes the currenct working directory
 * @params : double pointer to the path to the new directory
 */
void change_dir(char **params)
{
	int i, length = 0;
	char buffer[1024], **temp_params;

	for (i = 0; params[i] != NULL; i++)
		;
	temp_params = malloc(sizeof(char *) * (length + 1));
	copy_non_space_strings(temp_params, params, "cd");
	for (i = 0; temp_params[i] != NULL; i++)
		;
	if (i == 1)
	{
		if (chdir("/home") == -1)
			perror("");
	}
	else if (i > 2)
		write(1, "too many arguments\n", 19);
	else if (i == 2)
	{
		if (str_cmp(temp_params[1], "-") == 0)
		{
			if (chdir("/") == -1)
				perror(temp_params[1]);
			return;
		}
		if (temp_params[1][0] == '/')
		{
			if (chdir(temp_params[1]) == -1)
				perror(temp_params[1]);
		}
		else
		{
			if (getcwd(buffer, sizeof(buffer)) != NULL)
				get_absolute_path(temp_params[1], buffer);
			else
				perror("");
		}
	}
}

/**
 * get_absolute_path - function that returns the abs path of the user input
 * @rel_path : user input relative path
 * @cwd : current working directory
 */
void get_absolute_path(char *rel_path, char *cwd)
{
	char *new_dir;
	int i, j;

	new_dir = malloc(sizeof(char) * (str_len(cwd) + str_len(rel_path + 1)));
	for (i = 0; cwd[i] ; i++)
		new_dir[i] = cwd[i];
	new_dir[i] = '/';
	for (j = 0 ; rel_path[j] ; j++)
		new_dir[i + j + 1] = rel_path[j];
	new_dir[i + j + 1] = '\0';
	if (chdir(new_dir) == -1)
		perror(rel_path);
	free(new_dir);
}
