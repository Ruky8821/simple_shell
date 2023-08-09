#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <dirent.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
int command_type(const char *token);
void display_list();
int str_len(char *c);
int str_cmp(const char *x, const char *y);
/**
* struct _command - associate specifier with pointer function
* @cmd: command symbol
* @command_spec: pointer to function that achieves the command functionality
*/
typedef struct _command
{
	char *cmd;
	void (*command_spec)();
} command;
#endif
