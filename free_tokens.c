#include "main.h"
/**
 * free_tokens - function that frees the memory space of all the tokens
 * @token: double pointer to be freed.
 */

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
