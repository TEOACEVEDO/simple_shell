#include "main.h"

void free_tokens(char **token)
{
	int index = 0;

	while (token[index] != NULL)
	{
		free(token[index]);
		index++;
	}
	free(token);
}
