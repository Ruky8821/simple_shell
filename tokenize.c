#include "main.h"
/**
 * tokenize - Tokenize a string and stores non-empty tokens in a char array.
 * @one_param: The input string to tokenize.
 * @i: Current index in the tokens array.
 * @tokens: Array to store the resulting tokens.
 * Return: 0 on success, 1 if memory allocation fails.
 */
int tokenize(char *one_param, int i, char **tokens)
{
	while (one_param != NULL)
	{
		if (str_cmp(one_param, "#") == 0)
			break;
		if (one_param[0] != '#')
			tokens[i] = malloc(str_len(one_param) + 1);
		else
		{
			one_param = strtok(NULL, " \t");
			continue;
		}
		if (tokens[i] == NULL)
			return (1);
		str_cpy(tokens[i], one_param);
		one_param = strtok(NULL, " \t");
		i++;
	}
	tokens[i] = NULL;
	return (0);
}

