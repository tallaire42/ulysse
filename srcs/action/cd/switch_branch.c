#include "../../../includes/ulysse.h"

static	size_t	size_of_txt(char **txt)
{
	size_t	i;

	i = 0;
	while (txt && txt[i])
		++i;
	return (i);
}

static	int	match_branch(char *branch, char *av)
{
	int	i;

	i = 0;
	while (branch[i] && av[i])
	{
		if (branch[i] != av[i])
			return (-1);
		++i;
	}
	if (branch[i] != '\0' || av[i] != '\0')
		return (-1);
	return (0);
}

static	int	cpy_txt(char **new, char **txt, char *av)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (txt && txt[i])
	{
		if (match_branch(txt[i], av))
		{
			if (!(new[j] = ft_strdup(txt[i])))
			{
				free_get_file(new);
				return (-1);
			}
			++j;
		}
		++i;
	}
	new[j] = NULL;

	return (0);
}

char		**switch_branch(char **txt, char *av)
{
	char	**new;
	size_t	size;
	int	i;
	int	j;

	i = 0;
	j = 1;
	new = NULL;
	if ((size = size_of_txt(txt)) == 0)
		return (NULL);
	if (!(new = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	if (!(new[0] = ft_strdup(av)))
	{
		free(new);
		return (NULL);
	}
	if (cpy_txt(new, txt, av))
	{
		free_get_file(txt);
		return (NULL);
	}
	free_get_file(txt);
	return (new);
}
