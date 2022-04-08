#include "main.h"

int main(void)
{
	int count = 1, i;
	int first;
	char *line = NULL, *token, *str = " ";
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
		i = tokener(line);
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
