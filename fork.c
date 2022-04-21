#include "main.h"
/**
 * fork_hijo - function that creates a child process
 * to execute the given command (camino).
 * @camino: full path of the command to execute.
 * @arguments: command options.
 * @environ: user environment.
 * Return: Success is 0.
 */
int fork_hijo(char *camino, char **arguments, char **environ)
{
	pid_t hijo = 0;
	int status = 0, end = 0;

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
			return (-1);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			end = WEXITSTATUS(status);
		free(arguments);
		free(camino);
	}
	return (end);
}
