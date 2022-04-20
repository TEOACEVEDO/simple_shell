#include "main.h"

char *ver_access(char **token)
{
	char *new_command = NULL;
	struct stat st;

	if (stat(token[0], &st) == -1)
	{
		new_command = search_alias(token);
		if (new_command == NULL)
		{
			perror("./hsh");
			free(new_command);
			free(token);
			return (NULL);
		}
	}
	else
		new_command = _strdup(token[0]);
	return (new_command);
}
