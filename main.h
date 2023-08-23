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
int str_len(char *c);
void str_cpy(char *dest, const char *src);
void input_controller(char *input, char *argv);
void handle_command(char *path, char **params, char *argv);
int check_line_empty(char *input);
int str_cmp(const char *x, const char *y);
char **separate_params(char *input);
void change_dir(char **params);
void print_error(char *message, char *argv);
char *get_previous_dir(void);
void command_type(char *token, const char *path, char **params);
void exit_shell(char **params, char *argv);
void get_absolute_path(char *rel_path, char *cwd);
char *get_path(char *argv);
char *token_dirs(char *penv_cp, char *argv, char *penv);
char *_strcat(char *dest, char *src);
void copy_non_space_strings(char **argv, char **params, char *token);
int string_to_int(const char *str);
#endif
