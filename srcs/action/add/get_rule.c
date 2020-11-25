#include "../../../includes/ulysse.h"

/*
** alloc and copy the rule from the path
*/

static	char	*rule_cpy(char *path, size_t start, size_t end)
{
	char	*rule;
	size_t	j;
	size_t	i;

	rule = NULL;
	j = start;
	i = 0;
	if (!(rule = ft_calloc(end - start + 1, sizeof(char))))
		return (at_err_null("failed to copy the rule"));
	while (path[j] && j < end)
	{
		rule[i] = path[j];
		++i;
		++j;
	}
	rule[i] = '\0';
	return (rule);
}

/*
** find the end of the rule in the path
*/

static	size_t	get_end(char *path)
{
	size_t	i;

	i = ft_strlen(path);
	if (c_is_str(path, '.') < 0)
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

char	*get_rule(char *av)
{
	size_t	end;
	size_t	start;
	char	*rule;

	rule = NULL;
	start = get_start(av);
	end = get_end(av + start) + start;
	if (start >= end)
		return (at_err_null("file name is missing in the path"));
	if (!(rule = rule_cpy(av, start, end)))
		return (NULL);
	return (rule);
}

