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
#include <string.h>
void command_type(char *token, const char *path,char **params);
void display_list(void);
int str_len(char *c);
void str_cpy(char *dest, const char *src);
void  input_controller(char *input, char *argv);
int str_cmp(const char *x, const char *y);
void handle_command(char *path, char *argv, char **params);
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
