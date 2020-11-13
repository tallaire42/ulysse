#include "../../includes/ulysse.h"

static	void	free_get_file(char **txt)
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

/*
** Put the text from file to (char **)txt
*/

static	char	**get_txt(size_t size, int fd)
{
	int	i;
	int	ret;
	char	**txt;
	char	*line;

	i = 0;
	ret = 0;
	line = NULL;
	txt = NULL;
	if (!(txt = (char **)calloc(size + 1, sizeof(char *))))
		at_err_null("Failed to read file\n alloc memory failed");
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(txt[i] = ft_strdup(line)))
			return (NULL);
		++i;
		free(line);
	}
	if (ret < 0)
		at_err_null("Failed to read file\n alloc memory failed");
	txt[i] = NULL;
	free(line);
	return (txt);
}

/*
** Give the number of line of file's text
*/

static	size_t	file_size(int fd, char *file_name)
{
	size_t	size;
	int	ret;
	char	*line;

	ret = 0;
	line = NULL;
	size = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		++size;
		free(line);
	}
	if (size == 0)
	{
		printf("Error\n%s is empty", file_name);
		return (-1);
	}
	else
		free(line);
	return (size);
}

char		**get_file(char *file_name)
{
	size_t	size;
	int	fd;
	char	**txt;

	size = 0;
	fd = 0;
	if ((fd = at_open(file_name)) < 0)
		return (NULL);
	if ((size = file_size(fd, file_name)) < 0)
		return (NULL);
	if ((fd = at_open(file_name)) < 0)
		return (NULL);
	if (!(txt = get_txt(size, fd)))
	{
		free_get_file(txt);
		return (NULL);
	}
	return (txt);
}
