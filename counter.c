#include "main.h"
int counter(char *string)
{
	int linia = 0;
	unsigned int iter = 0;
	while(*string)
	{
		if (*string == ' ' || *string == '=' || *string == ':' || *string == '\n' || *string == '\t')
			linia = 0;

		else if (linia == 0)
		{
			linia = 1;
			++iter;
		}
		++string;
	}
	return (iter);
}
