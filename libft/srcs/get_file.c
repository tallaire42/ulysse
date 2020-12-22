#include "../includes/libft.h"

static	char	**empty_file(void)
{
	char	**txt;

	txt = NULL;
	if (!(txt = (char **)malloc(sizeof(char *) * 2)))
		return (NULL);
	if (!(txt[0] = malloc(sizeof(char) * 1)))
		return (NULL);
	txt[0][0] = '\0';
	return (txt);
}

static	char	*get_string(char *path, int size)
{
	char	*string;
	char	buff[BUFFER_SIZE];
	int	ret;
	int	fd;

	string = NULL;
	fd = 0;
	ret = 0;
	if (!(string = ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	if ((fd = open(path, O_RDONLY)) < 0)
	{
		free(string);
		return (NULL);
	}
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
		ft_strlcat(string, buff, ret + 1);
	if (ret == (-1))
	{
		free(string);
		return (NULL);
	}
	return (string);
}


static	int	filelen(char *path)
{
	int	ret;
	int	i;
	int	size;
	int	fd;
	char	buff[BUFFER_SIZE];

	i = 0;
	size = 0;
	ret = 0;
	if ((fd = open(path, O_RDONLY)) < 0)
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
		size += ret;
	if (close(fd))
		return (-1);
	if (ret < 0)
		return (-1);
	return (size);
}

/*
** Put the text from file to (char **)txt
*/

char		**get_file(char *path)
{
	int	fd;
	char	**txt;
	char	*string;
	int	size;

	fd = 0;
	txt = NULL;
	string = NULL;
	size = 0;
	if ((size = filelen(path)) < 0)
		return (NULL);
	if (!(string = get_string(path, size)))
		return (NULL);
	if (string[0] == '\0')
	{
		free(string);
		return (empty_file());
	}
	if (!(txt = ft_split(string, '\n')))
	{
		free(string);
		return (NULL);
	}
	free(string);
	return (txt);
}
