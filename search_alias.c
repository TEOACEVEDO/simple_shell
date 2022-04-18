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
			path = _strdup(environ[i]);
			break;
		}
		i++;
	}
	if (!path)
		return (NULL);
	path_token = tokener(path, "=:");
	while (path_token[h])
	{
		new_rout = malloc(sizeof(char) * (_strlen(path_token[h]) + _strlen(token[0]) + 2));
		_strcpy(new_rout, path_token[h]);
		if (!new_rout)
		{
			printf("Error rout\n");
			return (NULL);
		}
		_strcat(new_rout, "/");
		_strcat(new_rout, token[0]);
		if (stat(new_rout, &st) == 0)
		{
			free(path);
			free(path_token);
			return (new_rout);
		}
		free(new_rout);
		h++;
	}
	
	free(path_token);
	free(path);
	return (NULL);
}
