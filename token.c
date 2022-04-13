#include "main.h"

char **tokener(char *str, char *delim)
{
	char **command = NULL;
	int words = counter(str), i = 1;

	command = malloc(sizeof(char *) * (words + 1));
	if (!command)
	{
		perror("Error malloc");
		return (NULL);
	}
	command[0] = strtok(str, delim);
	if (command[0] == NULL)
	{
		free_tokens(command);
		return (NULL);
	}
	while (i < (words + 1))
	{
		command[i] = strtok(NULL, delim);
		i++;
	}
	return (command);
}
