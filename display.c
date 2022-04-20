#include "main.h"

int display(int first, char *line)
{
	if (first == -1)
	{
		if (errno == EINVAL || errno == ENOMEM)
			perror("./hsh");
		write(STDOUT_FILENO, "\n", 1);
		free(line);
	        return (0);
	}
	return (1);
}
