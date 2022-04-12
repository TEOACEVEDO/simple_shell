#include "main.h"

int main(void)
{
	int i, first;
	char *line = NULL, **token, *new_command;
	size_t len = 0;
	struct stat st;
	int (*f)();

	while (1)
	{
		write(STDOUT_FILENO, "Shell$ ", 7);
		first = getline(&line, &len, stdin);
		if (first == -1)
		{
			perror("Error getline\n");
			free(line);
			return (0);
		}
		token = tokener(line, " \n\t");
		if (token == NULL)
		{
			perror("Error token");
			continue;
		}
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
				perror("error fork");
				continue;
			}
			free(new_command);
		}
	}
	return (0);
}
