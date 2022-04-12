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

char *_strdup(const char *s)
{
		int i;
			char *dup;
				int len;

					if (s == NULL)
							{
										return (NULL);
											}

						len = strlen(s);
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
