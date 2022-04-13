#include "main.h"
int fork_hijo(char *camino, char **arguments, char **environ)
{
	pid_t hijo = 0;
	int status = 0;

	hijo = fork();
	if (hijo == -1)
	{
		free(camino);
		return (1);
	}
	if (hijo == 0)
	{
		if (execve(camino, arguments, environ) == -1)
		{
			return (1);
		}
	}
	else
	{
		wait(&status);
		free(arguments);
		free(camino);
	}
	return (0);
}
