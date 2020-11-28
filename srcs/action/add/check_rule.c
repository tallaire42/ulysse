#include "../../../includes/ulysse.h"

/*
** find the end of the rule in the path
*/

static	size_t	get_end(char *path)
{
	size_t	i;

	i = ft_strlen(path);
	if (c_is_str(path, '.'))
		return (i);
	while (i > 0 && path[i] != '.')
		--i;
	return (i);
}

/*
** find the start of the rule in the path
*/

static	size_t	get_start(char *path)
{
	size_t	i;

	i = 0;
	while (path[i] && (path[i] == '.' || path[i] == '/'))
		++i;
	while (path[i] && c_is_str(path + i, '/') > 0)
		++i;
	if (path[i] == '/')
		++i;
	return (i);
}

/*
** find the rule inside the file's path
*/

int	check_rule(char *av)
{
	size_t	end;
	size_t	start;
	char	*rule;

	rule = NULL;
	start = get_start(av);
	end = get_end(av + start) + start;
	if (start >= end)
		return (at_error("file name is missing in the path"));
	return (0);
}

