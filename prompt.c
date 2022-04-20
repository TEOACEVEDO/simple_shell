#include "main.h"
/**
 * prompt_interactivo - command line outside the shell
 * Return: success always 0
 */

int prompt_interactivo(void)
{
	int i = 0, first = 0, j = 0, f = 0;
	char *line = NULL, **token = NULL, *new_command = NULL;
	size_t len = 0;

	while (1)
	{
		signal(2, handler);
		write(STDOUT_FILENO, "Shell$ ", 7);
		first = getline(&line, &len, stdin);
		j = display(first, line);
		if (j == 0)
			return (0);
		token = tokener(line, " \n\t");
		if (token == NULL)
			continue;
		f = searchb(token, line);
		if (f == 1)
			continue;
		new_command = ver_access(token);
		if (new_command)
		{
			i = fork_hijo(new_command, token, environ);
			if (i == 1)
			{
				perror("Error Fork");
				continue;
			}
		}
	}
	return (0);
}
