#include "main.h"

int searchb(char **token, char *line)
{
	int (*f)() = 0;

	f = get_function(token[0]);
        if (f != NULL)
	{
		free(token);
		if (f() == 1)
		{
			free(line);
			exit(0);
		}
		return (1);
	}
	return (0);
}
