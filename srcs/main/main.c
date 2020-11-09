#include "../../includes/elec.h"

int	get_av_un(t_env *env, char *av)
{
	int	i;
	size_t	size;

	i = 0;
	size = ft_strlen(av);
	while (av[i])
		++i;
	if (av[i - 1] != 'c' || av[i - 2] != 'e' || av[i - 3] != 'l' ||
		av[i - 4] != 'e' || av[i - 5] != '.')
		return (at_error("wrong file extension"));
	if ((env->file.fd = open(av, O_RDONLY)) <= 0)
	{
		printf("Error\nCan't find or open %s", av);
		return (-1);
	}
	if (!(env->av.one = ft_strdup(av)))
		return (at_error("first argument alloc memory failed"));
	return (1);
}

int	main(int argc, char **argv)
{
	t_env	env;

	init(&env);
	if (argc != 2)
		return (0);
	if (get_av_un(&env, argv[1]) < 0)
		return (0);
	if (start_elec(&env) < 0)
		return (0);
	return (0);
}
