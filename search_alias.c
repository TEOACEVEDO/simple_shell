#include "main.h"

char *search_alias(char **token)
{
	int i = 0, h = 1;
	char *path = NULL, **path_token = NULL, *new_rout = NULL;
	struct stat name;

	while (environ[i])
	{
		if (strncmp(environ[i], "PATH", 4) == 0)
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
		new_rout = strdup(path_token[h]);
		strcat(new_rout, "/");
		strcat(new_rout, token[0]);
		if (stat(new_rout, &name) == 0)
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
