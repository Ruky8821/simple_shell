#include "main.h"
/**
 * copy_non_space_strings - Copies non-space strings from params to argv.
 * @argv: A pointer to the destination array of strings
 * @params: A pointer to the source array of strings to process
 * @token: The first token to be included in the argv array.
 */
void copy_non_space_strings(char **argv, char **params, char *token)
{
	int argv_index = 1, i, j, k = 0;
	int contains_only_spaces = 1;

	argv[0] = token;
	for (i = 0; params[i] != NULL; i++)
	{
		for (j = 0; params[i][j]; j++)
		{
			if (params[i][j] != ' ' && params[i][j] != '\t')
			{
				contains_only_spaces = 0;
				break;
			}
		}
		if (!contains_only_spaces)
		{
			argv[argv_index] = malloc(str_len(params[i]) + 1);
			for (j = 0; params[i][j]; j++)
			{
				if (params[i][j] == ' ')
					continue;
				argv[argv_index][k] = params[i][j];
				k++;
			}
			argv[argv_index][k] = '\0';
			argv_index++;
		}
	}
	argv[argv_index] = NULL;
}
