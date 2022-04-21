#include "main.h"
/**
 * prompt_no_interactivo - command line outside the shell
 * @argc: number of arguments passed non-interactive
 * @argv: pointer with arguments passed non-interactive
 * Return: success always 0
 */
int prompt_no_interactivo(int argc, char **argv)
{
	int i = 0, first = 0, f = 0, j = 0;
	char *line = NULL, **token = NULL, *new_command = NULL;
	size_t len = 0;
	(void)argc;
	(void)argv;

	while (1)
	{
		signal(2, handler);
		first = getline(&line, &len, stdin);
		j = display_n(first, line, i);
		if (j == 0)
			return (0);
		token = tokener(line, " \n");
		if (token == NULL)
			continue;
		f = searchb(token, line, i);
		if (f == 1)
			continue;
		new_command = ver_access(token);
		if (new_command)
		{
			i = fork_hijo(new_command, token, environ);
			if (i == -1)
			{
				perror("Error Fork");
				continue;
			}
		}
	}
	return (0);
}
