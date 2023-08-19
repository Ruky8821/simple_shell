#include "main.h"
/**
 * change_dir-function that changes the currenct working directory
 * @params : double pointer to the path to the new directory
 */
void change_dir(char **params)
{
	int i, length = 0;
	char buffer[1024];

	for (i = 0; params[i] != NULL; i++)
		length++;
	if (length == 0)
	{
		if (chdir("/home") == -1)
			perror("chdir");
	}
	else if (length > 1)
		printf("too many params");
	else if (length == 1 && params[0][0] == '/')
	{
		if (str_cmp(params[0], "-") == 0)
		{
			if (chdir("/") == -1)
				perror("chdir");
			return;
		}
		if (chdir(params[0]) == -1)
			perror("chdir");
	}
	else
	{
		if (getcwd(buffer, sizeof(buffer)) != NULL)
			get_absolute_path(params[0], buffer);
		else
			perror("getcwd error");
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
		perror("chdir");
	free(new_dir);
}
