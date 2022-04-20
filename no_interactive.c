#include "main.h"
/**
 * prompt_no_interactivo - command line outside the shell
 * @argc: number of arguments passed non-interactive
 * @argv: pointer with arguments passed non-interactive
 * Return: success always 0
 */
int prompt_no_interactivo(int argc, char **argv)
{
	int i = 0, first = 0, f = 0;
	char *line = NULL, **token = NULL, *new_command = NULL;
	char *file = argv[argc - 1];
	size_t len = 0;

	while (1)
	{
		signal(2, handler);
		first = getline(&line, &len, stdin);
		if (first == -1)
		{
			if (errno == EINVAL || errno == ENOMEM)
				perror(file);
			free(line);
			return (0);
		}
		token = tokener(line, " \n");
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
