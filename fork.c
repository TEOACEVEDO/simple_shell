#include "main.h"
int fork_hijo(char *camino, char **arguments, char **environ)
{
	pid_t pidC;

	pidC = fork();

	if (pidC == -1)
	{
		free(camino);
		return (1);
	}

	if (pidC == 0)
	{
		if (execve(camino, arguments, environ) == -1)
		{
			return (1);
		}
	}

	else
	{
		wait(NULL);
		free(arguments);
	}

	return (0);
}
