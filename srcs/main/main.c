#include "./../../includes/elec.h"

static	int	get_av_three(t_env *env, char *av)
{
	size_t	i;

	i = 0;
	env->av.three = NULL;
	while (av[i])
	{
		if (ft_isalpha(av[i]) == 0 && av[i] != '_')
		{
			free_ulysse(env, 2);
			printf("Second argument must has only alpha character");
			return (-1);
		}
		++i;
	}
	if (!(env->av.three = ft_strdup(av)))
	{
		free_ulysse(env, 2);
		return (at_error("Second argument alloc memory failed"));
	}
	return (1);
}

static	int	get_av_two(t_env *env, char *av)
{
	size_t	i;

	i = 0;
	env->av.two = NULL;
	while (av[i])
	{
		if (ft_isalpha(av[i]) == 0 && av[i] != '_')
		{
			free_ulysse(env, 2);
			printf("Second argument must has only alpha character");
			return (-1);
		}
		++i;
	}
	if (!(env->av.two = ft_strdup(av)))
	{
		free_ulysse(env, 2);
		return (at_error("Second argument alloc memory failed"));
	}
	return (1);
}

static	int	get_av_one(t_env *env, char *av)
{
	int	i;
	size_t	size;

	i = 0;
	env->av.one = NULL;
	size = ft_strlen(av);
	while (av[i])
		++i;
	if (av[i - 1] != 'y' || av[i - 2] != 'l' ||
		av[i - 3] != 'u' || av[i - 4] != '.')
		return (at_error("Wrong file extension"));
	if (open(av, O_RDONLY) <= 0)
	{
		printf("Error\nCan't find or open %s", av);
		return (-1);
	}
	if (!(env->av.one = ft_strdup(av)))
		return (at_error("First argument alloc memory failed"));
	return (1);
}

int		main(int argc, char **argv)
{
	t_env	env;

	init(&env);
	if (argc != 4)
		return (0);
	if (get_av_one(&env, argv[1]) < 0)
		return (0);
	if (get_av_two(&env, argv[2]) < 0)
		return (0);
	if (get_av_three(&env, argv[3]) < 0)
		return (0);
	if (start_ulysse(&env) < 0)
		return (0);
	return (0);
}
