#include "../../../includes/ulysse.h"

static	int	check_path(char *av)
{
	int	i;

	i = 0;
	while (av && av[i])
	{
		if (av[i] == ' ')
			return (-1);
		++i;
	}
	if (i == 0)
		return (-1);
	return (0);
}

char		*get_file_name(char *av)
{
	size_t	i;
	char	*name;

	i = ft_strlen(av);
	name = NULL;
	if (check_path(av))
		return (NULL);
	while (i > 0 && av[i - 1] != '/')
	{
		if (av[i - 1] == '.' && av[i - 2] == '.' && i == 2)
			break ;
		--i;
	}
	if (!(name = ft_strdup(av + i)))
		return (NULL);
	return (name);
}
