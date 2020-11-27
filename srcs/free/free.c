#include "../../includes/ulysse.h"

static	void	free_txt(char **txt)
{
	int	i;

	i = 0;
	while (txt && txt[i])
	{
		free(txt[i]);
		++i;
	}
	free(txt);
	txt = NULL;
}

static	void	free_av(t_env *env)
{
	free(env->av.one);
	env->av.one = NULL;
	if (env->av.two != NULL)
		free(env->av.two);
	env->av.two = NULL;
	if (env->av.three != NULL)
		free(env->av.three);
	env->av.three = NULL;
	if (env->branch.path != NULL)
		free(env->branch.path);
	env->branch.path = NULL;
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
	env->data.rules = NULL;
	free(env->data.path);
	env->data.path = NULL;
}

void		*free_ulysse(t_env *env, int end)
{
	int	i;

	i = 0;
	if (++i < end)
		free_av(env);
	if (++i < end)
		free_txt(env->data.txt);
	if (++i < end)
		free_data(env);
	return (NULL);
}
