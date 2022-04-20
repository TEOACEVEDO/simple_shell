#include "main.h"
/**
 * get_function - search the builtins
 * @str: string to be compared
 * Exit_shell - function for exit the shell
 * Return: success 0.
 */

int (*get_function(char *str))()
{
	Built_in bin[] = {
		{"env", environment},
		{"exit", Exit_shell},
		{NULL, NULL}};
	int l = 0;

	while (bin[l].comand != NULL)
	{
		if ((_strcmp(str, bin[l].comand)) == 0)
		{
			return (bin[l].f);
		}
		l++;
	}
	return (NULL);
}
/**
 * environment - prints the environ
 * Return: success 0.
 */
int environment(void)
{
	int v = 0;

	while (environ[v])
	{
		write(STDOUT_FILENO, environ[v], _strlen(environ[v]));
		write(STDOUT_FILENO, "\n", 1);
		v++;
	}
	return (0);
}
/**
 * Exit_shell - exit the shell
 * Return: success 1.
 */
int Exit_shell(void)
{
	return (1);
}
