#include "main.h"

int main(void)
{
	int count = 1, i;
	int first;
	char *line = NULL, **token;
	size_t len = 0;

	while (count != 5)
	{
		printf("Shell$ ");
		first = getline(&line, &len, stdin);
		if (first == -1)
		{
			printf("Vuelva pronto!\n");
			return (-1);
		}
		token = tokener(line);
		i = fork_hijo(token[0], token);
		if (i == -1)
		{
			perror("error fork");
			return (-1);
		}
		if (count == 3)
		{
			printf("Para salir presione Ctrl+D\n");
			count = 0;
		}
		count++;
	}
	free(line);
	return (0);
}
