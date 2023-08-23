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
