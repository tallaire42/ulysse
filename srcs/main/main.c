#include "./../../includes/ulysse.h"

void		free_main_av(t_env *env)
{
	if (env->av.argc > 1 && env->av.one != NULL)
	{
		free(env->av.one);
		env->av.one = NULL;
	}
	if (env->av.argc > 2 && env->av.two != NULL)
	{
		free(env->av.two);
		env->av.two = NULL;
	}
}

static	int	get_av_two(t_env *env, char *av)
{
	size_t	i;

	i = 0;
	env->av.two = NULL;
	if (c_is_str(av, ' ') > 0)
	{
//		free_ulysse(env, 2);
		printf("%sError%s\n", RED, NC);
		printf("%s must not have space character (' ')\n", av);
		printf("Please, rename your file");
		return (-1);
	}
	if (!(env->av.two = ft_strdup(av)))
	{
//		free_ulysse(env, 2);
//		return (at_error("Second argument alloc memory failed"));
		return (-1);
	}
	return (0);
}

static	int	get_av_one(t_env *env, char *av)
{
	env->av.one = NULL;
	if (!(env->av.one = ft_strdup(av)))
		return (-1);
//		return (at_error("First argument alloc memory failed"));
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	env;

	env.av.argc = argc;
	if (argc < 2 || argc > 3)
		return (0);
	if (get_av_one(&env, argv[1]))
		return (0);
	if (argc == 3)
	{
		if (get_av_two(&env, argv[2]))
			return (0);
	}
	if (start_ulysse(&env))
		return (0);
	free_main_av(&env);
	return (0);
}
