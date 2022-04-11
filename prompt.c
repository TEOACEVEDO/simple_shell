#include "main.h"

int main(void)
{
	int i, first;
	char *line = NULL, **token;
	size_t len = 0;
	struct stat st;

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
		if (stat(token[0], &st) == -1)
		{
			perror("Access fail");
			free(token);
			continue;
		}
		if (token != NULL)
		{
			i = fork_hijo(token[0], token, environ);
			if (i == 1)
			{
				perror("error fork");
				continue;
			}
		}
	}
	return (0);
}
