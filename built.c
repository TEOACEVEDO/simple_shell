#include "main.h"

/**
 * searchb - Verify the Built-in
 * @token: command to be verified
 * @line: line input
 * @i: Exit status
 * Return: 1 if is Built-in
 * 0 if is not
 */
int searchb(char **token, char *line, int i, int process)
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
				error_q(token, process);
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

/**
 * error_q - Prints a error message for the command
 * @tokens: command input
 * @process: number of process of the program
 */
void error_q(char **tokens, int process)
{
	char *num_p = NULL;
	char buffer[1024];

	num_p = _itoa(process, buffer, 10);
	write(1, "./hsh", 5);
	write(1, ": ", 2);
	write(1, num_p, _strlen(num_p));
	write(1, ": ", 2);
	write(1, tokens[0], _strlen(tokens[0]));
	write(1, ": ", 2);
	write(1, "Illegal number: ", 16);
	write(1, tokens[1], _strlen(tokens[1]));
	write(1, "\n", 1);
}
