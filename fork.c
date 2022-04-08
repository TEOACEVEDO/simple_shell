#include "main.h"
int fork_hijo(char *camino, char **arguments)
{
	pid_t pidC;

	pidC = fork();

	if (pidC == -1)
	{
		free(camino);
		return (-1);
	}

	if (pidC == 0)
	{
		if (execve(camino, arguments, NULL) == -1)
		{
			return (-1);
		}
	}

	else
	{
		wait(NULL);
		free(camino);
		free(arguments);
	}

	return (0);
}
