#include "main.h"

/**
 * searchb - Verify the Built-in
 * @token: command to be verified
 * @line: line input
 * @i: Exit status
 * Return: 1 if is Built-in
 * 0 if is not
 */
int searchb(char **token, char *line, int i)
{
	int (*f)() = 0, num = 0;

	f = get_function(token[0]);
	if (f != NULL)
	{
		if (f() == 0)
			free(token);
		if (f() == 1)
		{
			if (token[1] == NULL)
			{
				free(token);
				free(line);
				exit(i);
			}
			if (_isdigit(token[1]) == -1)
			{
				perror(token[1]);
				free(token);
				return (1);
			}
			else
			{
				num = _atoi(token[1]);
				free(token);
				free(line);
				exit(num);
			}
		}
		return (1);
	}
	return (0);
}
