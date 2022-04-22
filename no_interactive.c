#include "main.h"
/**
 * prompt_no_interactivo - command line outside the shell
 * @argc: number of arguments passed non-interactive
 * @argv: pointer with arguments passed non-interactive
 * Return: success always 0
 */
int prompt_no_interactivo(int argc, char **argv)
{
	int i = 0, first = 0, process = 0;
	char *line = NULL, **token = NULL, *new_command = NULL;
	size_t len = 0;
	(void)argc;
	(void)argv;

	while (1)
	{
		signal(2, handler);
		first = getline(&line, &len, stdin);
		process++;
		display_n(first, line, i);
		token = tokener(line, " \n\t");
		if (token == NULL)
		continue;
		if (searchb(token, line, i, process) == 1)
		continue;
		new_command = ver_access(token, process);
		if (new_command)
		{
			accion(new_command, token, process);
		}
	}
	return (0);
}
