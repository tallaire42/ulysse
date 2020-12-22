#include "../../../includes/ulysse.h"

static	int	print_fd(int fd)
{
	int	ret;
	char	buffer[BUFFER_SIZE];

	ret = 0;
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (ret < 0)
			return (-1);
		ft_putstr_fd(buffer, 1);
	}
	return (0);
}

static	char	*take_file_name(char *txt)
{
	char	*file_name;
	int	i;

	i = 0;
	file_name = NULL;
	while (txt[i] && txt[i] != ' ')
		++i;
	while (txt[i] && txt[i] == ' ')
		++i;
	if (!(file_name = ft_strdup(txt + i)))
		return (NULL);
	return (file_name);
}

static	int	match_rule(char *txt, char *rule)
{
	int	i;

	i = 0;
	while (txt && rule && txt[i] && txt[i] != ' ' && rule[i])
	{
		if (txt[i] != rule[i])
			return (0);
		++i;
	}
	if (txt[i] != '\0' && txt[i] != ' ')
		return (0);
	if (rule[i] != '\0')
		return (0);
	return (1);
}

static	char	*print_get_file_name(char **txt, char *rule)
{
	int	i;

	i = 0;
	while (txt && txt[i])
	{
		if (match_rule(txt[i], rule))
			return (take_file_name(txt[i]));
		++i;
	}
	return (NULL);
}

int		print_file(char *av, char **txt)
{
	int	ret;
	int	fd;
	char	*file_name;

	ret = 0;
	fd = 0;
	if (!(file_name = print_get_file_name(txt, av)))
	{
		free_get_file(txt);
		return (-1);
	}
	if ((fd = open(file_name, O_RDONLY)) < 0)
	{
		free(file_name);
		return (-1);
	}
	free(file_name);
	if (print_fd(fd))
		return (-1);
	if (close(fd))
		return (-1);
	return (0);
}

