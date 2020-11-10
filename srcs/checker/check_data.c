#include "../../includes/elec.h"

static	int	check_this_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != ' ' && line[i] != '\0')
	{
		if (ft_isalpha(line[i]) <= 0)
			return (-1);
		++i;
	}
	if (line[i] != ' ')
		return (-1);
	while (line[i] == ' ')
		++i;
	while (line[i] != ' ' && line[i] != '\0')
		++i;
	while (line[i] != '\0')
	{
		if (line[i] != ' ')
			return (-1);
		++i;
	}
	return (1);
}

int		check_data(t_env *env)
{
	int	i;

	i = 0;
	while (env->data.txt[i] != NULL)
	{
		while (env->data.txt[i][0] == '\0')
			++i;
		if (check_this_line(env->data.txt[i]) < 0)
		{
			printf("Error\nWrong data in %s\n", env->av.one);
			printf("(line : %d)", i + 1);
			return (-1);
		}
		++i;
	}
	return (1);
}
