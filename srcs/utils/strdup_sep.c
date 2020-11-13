#include "../../includes/ulysse.h"

static	size_t	strlen_sep(char *str, char sep)
{
	size_t	i;

	i = 0;
	while (str && str[i] && str[i] != sep)
		++i;
	return (i);
}

char		*strdup_sep(char *str, char sep)
{
	size_t	size;
	size_t	i;
	char *new;

	new = NULL;
	i = 0;
	size = strlen_sep(str, sep);
	if (!(new = malloc(sizeof(char) * size + 1)))
		return (NULL);
	while(str && str[i] && str[i] != sep)
	{
		new[i] = str[i];
		++i;
	}
	new[i] = '\0';
	return (new);
}
