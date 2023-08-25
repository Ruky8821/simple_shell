#include "main.h"
/**
 * print_error - Print an error message to the standard error stream.
 * @message: Pointer to the error message to be printed.
 * @argv: Pointer to the name of the command or program generating the error.
 */
void print_error(char *message, char *argv)
{
	write(STDERR_FILENO, argv, str_len(argv));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, message, str_len(message));
}
/**
 * not_existing_dir - Prints an error message when attempting
 *			to change to a non-existing directory.
 * @argv: The name of the command that triggered the error.
 * @dir: Name of the non-existing directory.
 */
void not_existing_dir(char *argv, char *dir)
{
	print_error("1: cd: can't cd to ", argv);
	write(STDERR_FILENO, dir, str_len(dir));
	write(STDERR_FILENO, "\n", 1);
}
