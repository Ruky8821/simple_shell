#include "main.h"
void change_dir(char **params)
{
	int i, length = 0;
	for (i = 0; params[i] != NULL; i++)
		length++;
	if (length == 0)
	{
		if (chdir("/home") == -1) {
        perror("chdir");
    }
	}
	else if (length > 1)
		printf("too many params");
	else if (length == 1)
	{
		if (str_cmp(params[0],"-")== 0)
		{
			if(chdir("/") == -1)
				perror("chdir");
			return;
		}
		   if (chdir(params[0]) == -1) {
        perror("chdir");
    }
	}
}

