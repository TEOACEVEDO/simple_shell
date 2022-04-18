#include "main.h"

char *_strncmp(char *path, char *match, size_t n)
{
	while (n && *path && (*path == *match))
	{
		++path;
		++match;
		--n;
	}
	if (n == 0)
	{
		return (path);
	}
	else
	{
		return (NULL);
	}
}

char *_strdup(char *s)
{
	int i;
	char *dup;
	int len;

	if (s == NULL)
	{
		return (NULL);
	}
	len = _strlen(s);
	dup = malloc((sizeof(char) * len) + 1);
	if (dup == NULL)
	{
		return (NULL);
	}
	for (i = 0; s[i] != '\0'; i++)
	{
		dup[i] = s[i];
	}
	dup[i] = '\0';
	return (dup);
}

int _strlen(char *s)
{
	if (!*s || !s)
		return (0);
	return (1 + _strlen(s + 1));
}

/* int _atoi(char *s)
{
	int i = 0;
	int u = 0;
	int cont = 0;
	int number;
	unsigned int sum = 0;

	while (s[i] != '\0')
		i++;
	while (u <= i)
	{
		if (s[u] == '-')
			cont++;
		if (s[u] >= '0' && s[u] <= '9')
		{
			number = s[u] - '0';
			if (cont % 2)
				number = -number;
			sum = (sum * 10) + number;
			if (s[u + 1] < '0' || s[u + 1] > '9')
				break;
		}
		u++;
	}
	if (sum == 0)
		return (0);
	return (sum);
} */

char *_strcpy(char *dest, char *src)
{
	int i = 0;
	int u = 0;

	while (src[i] != '\0')
		i++;
	while (u <= i)
	{
		dest[u] = src[u];
		u++;
	}
	return (dest);
}
