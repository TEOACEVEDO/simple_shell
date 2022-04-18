#include "main.h"

int prompt_no_interactivo(int argc, char **argv)
{
	int i = 0, first = 0, (*f)() = 0;
	char *line = NULL, **token = NULL, *new_command = NULL, *file = argv[argc - 1];
	size_t len = 0;
	struct stat st;

	while (1)
	{
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
		f = get_function(token[0]);
		if (f != NULL)
		{
			free(token);
			if (f() == 1)
			{
				free(line);
				exit(0);
			}
			continue;
		}	
		if (stat(token[0], &st) == -1)
		{
			new_command = search_alias(token);
			if (new_command == NULL)
			{
				perror(file);
				free(new_command);
				free(token);
				continue;
			}
		}
		else
			new_command = strdup(token[0]);
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
