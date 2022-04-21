#include "main.h"

/**
 * searchb - Verify the Built-in
 * @token: command to be verified
 * @line: line input
 * Return: 1 if is Built-in
 * 0 if is not
 */
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
			exit(EXIT_SUCCESS);
		}
		return (1);
	}
	return (0);
}
