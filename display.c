#include "main.h"

/**
 * display - Verify the input
 * @first: Number of chars of the input
 * @line: Input
 * Return: 1 if is ok
 * 0 if is not
 */
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
