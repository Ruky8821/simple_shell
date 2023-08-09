#include "main.h"
#include <string.h>
/**
* command_type - process the command type
* @token: command symbole
* Return: int
*/
int command_type(const char *token)
{
	int nb_specs, j;

	command command_func[] = {
		{"ls", display_list}
	};
	nb_specs = sizeof(command_func) / sizeof(command_func[0]);
	for (j = 0; j < nb_specs; j++)
	{
		if (strcmp(token, command_func[j].cmd))
			command_func[j].command_spec();
	}
	return (1);
}
