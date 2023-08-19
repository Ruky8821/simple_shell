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

extern char **environ;
void command_type(char *token, const char *path, char **params);
int str_len(char *c);
void str_cpy(char *dest, const char *src);
void  input_controller(char *input, char *argv);
int str_cmp(const char *x, const char *y);
char **separate_params(char *input, int length);
void handle_command(char *path, char *argv, char **params);
void newproc(char **argv);
void execute(char **argv);
void change_dir(char **params);
void get_absolute_path(char *rel_path, char *cwd);
char *get_path(char *argv);
char *token_dirs(char *penv_cp, char *argv, char *penv);

#endif
