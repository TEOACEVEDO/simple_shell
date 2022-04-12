#include "main.h"

int (*get_function(char *str))()
{
	Built_in bin[] = {
		{"env", environment},
		{"exit", Exit_shell},
		{NULL, NULL}};
	int l = 0;

	while (bin[l].comand != NULL)
	{
		if ((strcmp(str, bin[l].comand)) == 0)
		{
			return (bin[l].f);
		}
		l++;
	}
	return (NULL);
}

int environment(void)
{
	int v = 0;
	
	while (environ[v])
	{
		write(STDOUT_FILENO, environ[v], strlen(environ[v]));
		write(STDOUT_FILENO, "\n", 1);
		v++;
	}
	return (0);
}

int Exit_shell(void)
{
	return (1);
}
