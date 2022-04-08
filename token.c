#include "main.h"

int tokener(char *str)
{
	char *delim = " ", *command;
	char *argv[] = {"/bin/ls", NULL};

	command = strtok(str, delim);
	printf("%s", command);
	if (execve(argv[0], argv, NULL) == -1)
		perror("Error");
	return (1);
}
