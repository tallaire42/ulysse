#include "../../includes/elec.h"

static	char	**free_get_file(t_env *env)
{
	size_t	i;

	i = 0;
	while (env->data.txt[i])
	{
		free(env->data.txt[i]);
		++i;
	}
	free(env->data.txt);
	env->data.txt = NULL;
	return (NULL);
}

static	void	free_av_one(t_env *env)
{
	free(env->av.one);
	env->av.one = NULL;
	if (env->av.two != NULL)
		free(env->av.two);
	env->av.two = NULL;
}

static	void	free_data(t_env *env)
{
	int	i;
	/*
	int	j;

	j = 0;
	while (env->data.def[j])
	{
		i = 0;
		while (env->data.def[j][i])
		{
			free(env->data.def[j][i]);
			++i;
		}
		free(env->data.def[j]);
		++j;
	}
	free(env->data.def);
	*/
	i = 0;
	while (env->data.rules[i])
	{
		free(env->data.path[i]);
		free(env->data.rules[i]);
		++i;
	}
	free(env->data.rules);
	free(env->data.path);
}

void		*free_elec(t_env *env, int end)
{
	int	i;

	i = 0;
	if (++i < end)
		free_av_one(env);
	if (++i < end)
		env->data.txt =
		free_get_file(env);
	if (++i < end)
		free_data(env);
	return (NULL);
}
