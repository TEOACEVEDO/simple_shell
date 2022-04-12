#include "main.h"

char *espace(char *path, char *alias)
{
	char *duplicado;

	printf("entrada");
	if (path == NULL || alias == NULL)
		return (NULL);
	printf("malloc");
	duplicado = malloc(sizeof(char) * (strlen(path) + strlen(alias) + 2));
	if (duplicado == NULL)
		return (NULL);
	return (duplicado);
}

