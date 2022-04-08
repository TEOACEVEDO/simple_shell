#include "main.c"
int fork_hijo(char *camino, char **tokenizador)
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
		if (execve(camino, tokenizador) == -1)
		{
			return (-1);
		}
	}

	else
	{
		wait(NULL);
		free(camino);
		free(tokenizador);
	}

	return (0);
}
