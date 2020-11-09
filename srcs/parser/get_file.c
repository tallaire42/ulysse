#include "../../includes/elec.h"

static	int	get_txt(t_env *env)
{
	int	i;
	int	ret;
	char *line;

	i = 0;
	ret = 0;
	line = NULL;
	if ((env->file.fd = open(env->av.one, O_RDONLY)) <= 0)
	{
		printf("Error\nCan't find or open %s", env->av.one);
		return (-1);
	}
	while ((ret = get_next_line(env->file.fd, &line)) > 0)
	{
		if (!(env->file.txt[i] = ft_strdup(line)))
			return (at_error("Alloc memory failed in .elec extension file"));
		++i;
		free(line);
	}
	if (ret < 0)
		return (at_error("Failed to read .elec extension file"));
	env->file.txt[i] = NULL;
	free(line);
	return (1);
}

static	int	size_file(t_env *env)
{
	int	ret;
	char	*line;

	ret = 0;
	line = NULL;
	while ((ret = get_next_line(env->file.fd, &line)) > 0)
	{
		++env->file.size;
		free(line);
	}
	if (env->file.size == 0)
		return (at_error(".elec extension file is empty"));
	else
		free(line);
	return (1);
}

int		get_file(t_env *env)
{
	if (size_file(env) < 0)
		return (-1);
	printf("size = %d\n", env->file.size);
	if (!(env->file.txt = (char **)malloc(sizeof(char *) *
		env->file.size + 1)))
		return (at_error("Failed to read .elec extension file\n alloc memory failed"));
	if (get_txt(env) < 0)
		return (-1);
	return (1);
}
