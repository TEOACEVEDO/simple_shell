#include "main.h"
int fork_hijo(char *camino, char **arguments, char **environ)
{
	pid_t hijo;
	int status;

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
	}
	return (0);
}
