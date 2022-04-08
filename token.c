#include "main.h"

char **tokener(char *str)
{
	char *delim = " ", **command[];
	int words = counter(str), i = 1;

	command = malloc(sizeof(char) * (words + 1));
	if (!command)
	{
		perror("Error malloc");
		return (NULL);
	}
	command[0] = strtok(str, delim);
	if (command[0] == NULL)
	{
		free(command[0]);
		free(command);
		return (NULL);
	}
	while (i < words)
	{
		command = strtok(NULL, delim);
		i++;
	}
	return (command);
}
