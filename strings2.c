#include "main.h"

char *_strcat(char *dest, char *src)
{
	int i = 0;
	int u = 0;
	int j;

	while (dest[i] != '\0')
		i++;
	while (src[u] != '\0')
		u++;
	for (j = 0; j <= u; j++)
	{
		dest[i] = src[j];
		i++;
	}
	return (dest);
}

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
