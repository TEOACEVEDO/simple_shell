#include "main.h"

char *search_alias(char **token)
{
	int i = 0, h = 1;
	char *path = NULL, **path_token = NULL, *new_rout = NULL;
	struct stat st;

	while (environ[i])
	{
		if (_strncmp(environ[i], "PATH", 4) != NULL)
		{
			path = strdup(environ[i]);
			break;
		}
		i++;
	}
	if (!path)
		return (NULL);
	path_token = tokener(path, "=:");
	while (path_token[h])
	{
		printf("Antes del new rout: %s\n", path_token[h]);
		new_rout = strdup(path_token[h]);
		printf("despues del new rout: %s\n", new_rout);
		if (!new_rout)
		{
			printf("Error rout\n");
			return (NULL);
		}
		strcat(new_rout, "/");
		strcat(new_rout, token[0]);
		if (stat(new_rout, &st) == 0)
		{
			free(path);
			free(path_token);
			return (new_rout);
		}
		free(new_rout);
		h++;
	}
	free(path);
	free(path_token);
	return (NULL);
}
