#include "main.h"

int main(void)
{
	int i;
	int first;
	char *line = NULL, **token;
	size_t len = 0;

	while (1)
	{
		write(STDOUT_FILENO, "Shell$ ", 7);
		first = getline(&line, &len, stdin);
		if (first == -1)
		{
			perror("Error getline\n");
			return (0);
		}
		token = tokener(line, " \n\t");
		if (token == NULL)
		{
			perror("Error token");
			continue;
		}
		if (access(token[0], F_OK) == -1)
		{
			perror("Access fail");
			free(token);
			continue;
		}
		i = fork_hijo(token[0], token, environ);
		if (i == 1)
		{
			perror("error fork");
			continue;
		}
		free(line);
	}
	return (0);
}
