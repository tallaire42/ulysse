#include "../../includes/ulysse.h"

static	void	free_txt(char **txt)
{
	int	i;

	i = 0;
	while (txt && txt[i])
	{
		free(txt[i]);
		++i;
	}
	free(txt);
	txt = NULL;
}

char		*get_path(char **txt)
{
	size_t	i;
	size_t	size;
	char	*path;

	i = 0;
	size = 0;
	path = NULL;
	while (txt && txt[0] && txt[0][i] != ' ')
		++i;
	while (txt && txt[0] && txt[0][i] == ' ')
		++i;
	while (txt && txt[0] && txt[0][i + size] && txt[0][i + size] != ' ')
		++size;
	if (!(path = malloc(sizeof(char) * size + 1)))
		return (NULL);
	size = 0;
	while (txt && txt[0] && txt[0][i] && txt[0][i] != ' ')
	{
		path[size] = txt[0][i];
		++i;
		++size;
	}
	path[size] = '\0';
	return (path);
}

char		*wich_branch(char *file_path)
{
	int	fd;
	char	**txt;
	char	*path;

	fd = 0;
	txt = NULL;
	if (!(txt = get_file(file_path)))
		return (NULL);
	if (!(path = get_path(txt)))
		return (at_err_null("Can't find branch"));
	free_txt(txt);
	return (path);
}
