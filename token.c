#include "main.h"

int tokener(char *str)
{
	char *delim = " ", *command;
	char *argv[] = {"/usr/", NULL};

	command = strtok(str, delim);
	if (execve(command, argv, NULL) == -1)
		perror("Error exe");
	return (1);
}
