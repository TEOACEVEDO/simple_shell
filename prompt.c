#include "main.h"

int main(void)
{
	int i = 0, first = 0;
	char *line = NULL, **token = NULL, *new_command = NULL;
	size_t len = 0;
	struct stat st;
	int (*f)() = 0;

	while (1)
	{
		write(STDOUT_FILENO, "Shell$ ", 7);
		first = getline(&line, &len, stdin);
		if (first == -1)
		{	
			if (errno == EINVAL || errno == ENOMEM)
			{
				perror("./hsh");
			}
			free(line);
			return (0);
		}
		token = tokener(line, " \n\t");	
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
				perror("./hsh");
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
