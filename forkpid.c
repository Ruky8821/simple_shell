#include "main.h"
/**
 *
 */
void newproc(char **argv)
{
	pid_t pid_child;
	int status;

	pid_child = fork();
	if (pid_child == -1)
	{
		perror(" fail in fork child procss");
		exit(EXIT_FAILURE);
	}
	else if (!pid_child)
		execute(argv);
	else
	{
		waitpid(pid_child, &status, 0);

		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) != 0)
				fprintf(stderr, "new process not zero\n");
			else if (WIFSIGNALED(status))
				fprintf(stderr, "new process terminated\n");
		}
	}
}
