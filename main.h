#include <stdio.h>
#include <stdlib.h>
int command_type(const char *token);
void display_list();
typedef struct _command
{
char *spec;
void (*command_spec)();
} command;
